#include "API.h"

extern CatalogManager CL;
extern IndexManager IM;
extern RecordManager RM;

using namespace std;

API::API(SqlCommand c)
{
    sql = c;
}

API::~API()
{
}

void API::execute(SqlCommand sql)
{
    SqlCommand sql_temp = sql; //临时定义的sql属性
    attr.clear();
    con.clear();
    attr_special.clear();
    attr_normal.clear();
    con_special.clear();
    con_normal.clear();
    try
    {
        switch (sql_temp.get_command_type())
        {
        case (SQL_ERROR):
        {
            cout << "---- Syntax Error! ---- \n"
                 << endl;
            break;
        }

        case (SQL_DROP_DATABASE):
        {
            CL.Drop_Database(sql_temp.get_database_name());

            break;
        }

        case (SQL_DROP_TABLE):
        {
            CL.Drop_Table(sql_temp.get_table_name());
            //cout << "Query OK, 0 rows affected" << endl;
            break;
        }

        case (SQL_DROP_INDEX):
        {
            CL.Drop_Index(sql_temp.get_index_name());
            //cout << "Query OK, 0 rows affected" << endl;
            break;
        }

        case (SQL_QUIT):
        {
            cout << "Bye!\n"
                 << endl;
            exit(0);
        }

        case (SQL_EXECFILE):
        {
            sql_execfile(sql_temp);
            break;
        }

        case (SQL_CREATE_INDEX):
        {
            bool flag = true;
            flag = CL.Judge_Table_Exist(sql_temp.get_table_name());

            if (flag == false)
            {
                cout << "No this table!!" << endl;
                return;
            }

            flag = CL.Judge_Index(sql_temp.get_col_name(), sql_temp.get_table_name());

            if (flag == false)
            {
                cout << "Can not create index!!" << endl;
                return;
            }
            double dur;
            clock_t start, end;
            start = clock();
            CL.Create_Index(sql_temp.get_index_name(), sql_temp.get_table_name(), sql_temp.get_col_name());
            vector<Attribute> all_info = CL.Get_Attr_Info_All_Record(sql_temp.get_table_name());
            RM.Record_CreateIndex(sql_temp.get_table_name(), sql_temp.get_col_name(), sql_temp.get_index_name(), all_info);
            end = clock();
            dur = (double)(end - start);
            cout << " (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
            //cout << "Query OK, 0 rows affected" << endl;
            break;
        }

            /*insert into table values ('A', 'B', 'C' ...)*/
        case (SQL_INSERT_INTO):
        {
            double dur;
            clock_t start, end;
            start = clock();
            bool flag = true;
            flag = CL.Judge_Table_Exist(sql_temp.get_table_name());

            if (flag == false)
            {
                cout << "No this table!!! " << endl;
                return;
            }

            flag = CL.Judge_Data(sql_temp.col_values_vector, sql_temp.get_table_name());
            if (flag == false)
            {
                cout << "Data Unvalid!!" << endl;
                return;
            }

            /*All valid*/
            attr = CL.Get_Attr_Info_All_Record(sql_temp.get_table_name());
            int t = RM.Record_InsertValue(sql_temp.get_table_name(), sql_temp.col_values_vector, attr);
            if (t == -1)
                cout << "Duplicate entry for primary key or unique key" << endl;
            else
            {
                CL.Add_Tuple(1, sql_temp.get_table_name());
                end = clock();
                dur = (double)(end - start);
                cout << "Query OK, 1 row affected (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
            }
            break;
        }

        case (SQL_DELETE_FROM):
        {
            double dur;
            clock_t start, end;
            start = clock();
            int record_num;
            bool flag = true;
            flag = CL.Judge_Table_Exist(sql_temp.get_table_name());

            if (flag == false)
            {
                cout << "No this table!!! " << endl;
                return;
            }

            /*delete from table 属性名，数据类型，数据长度，属性类型，索引名*/
            if (sql_temp.command_op_vector.size() == 0)
            {
                attr = CL.Get_Attr_Info_All_Record(sql_temp.get_table_name());
                record_num = RM.Record_DeleteAllValue(sql_temp.get_table_name(), attr);
            }
            else // delete from table where ...
            {
                /*create condition vector*/
                for (int i = 0; i < sql_temp.command_op_vector.size(); i++)
                {
                    string name = sql_temp.command_left_vector[i];
                    string op = sql_temp.command_op_vector[i];
                    int id;

                    if (op == "=")
                        id = 0;
                    else if (op == "<>")
                        id = 1;
                    else if (op == "<")
                        id = 2;
                    else if (op == ">")
                        id = 3;
                    else if (op == "<=")
                        id = 4;
                    else if (op == ">=")
                        id = 5;
                    else if (op == "like")
                        id = 6;

                    string value = sql_temp.command_right_vector[i];
                    Condition con_d(name, value, id);
                    con.push_back(con_d);
                }
                attr = CL.Get_Attr_Info_All_Record(sql_temp.get_table_name());
                record_num = RM.Record_DeleteValue(sql_temp.get_table_name(), con, attr);
            }
            CL.Delete_Tuple(record_num, sql_temp.get_table_name());
            string info = "";
            end = clock();
            dur = (double)(end - start);
            info = info + "Query OK, " + to_string(record_num) + " rows affected";
            cout << info << " (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
            break;
        }

            /*select * from student where sage > 20 and sgender = 'F';*/
        case (SQL_SELECT_FROM):
        {
            //取出所有表名
            vector<string> select_table = sql_temp.get_select_table();
            //判断有多表
            if (select_table.size() != 0)
            {
                select_many_table(sql);
                break;
            }

            double dur;
            clock_t start, end;
            start = clock();
            SelectResult result;
            vector<Attribute> all_info;

            //代取的属性列和id，标志变量
            vector<string> select_attr;
            vector<int> select_attr_id;
            bool select_flag = false;

            vector<int> Result;
            int record_num;
            bool flag = true;
            flag = CL.Judge_Table_Exist(sql_temp.get_table_name());
            if (flag == false)
            {
                cout << "No this table!!! " << endl;
                return;
            }
            //取出全部的属性列
            all_info = CL.Get_Attr_Info_All_Record(sql_temp.get_table_name());
            select_attr = sql_temp.get_select_attr();
            //判断是否有属性列代取
            if (select_attr.size() != 0)
            {
                select_flag = true;
                //获取代取属性列的位置号
                for (int i = 0; i < select_attr.size(); i++)
                {
                    for (int j = 0; j < all_info.size(); j++)
                    {
                        if (all_info[j].attr_name == select_attr[i])
                        {
                            select_attr_id.push_back(j);
                            break;
                        }
                    }
                }
            }
            //select * from table;
            if (sql_temp.command_op_vector.size() == 0)
            {
                record_num = RM.Record_SelectAll(sql_temp.get_table_name(), all_info, result, all_info);
            }
            else
            {
                //select * from table where A = B;
                flag = CL.Judge_Attrs_Exist(sql_temp.get_table_name(), sql_temp.command_left_vector);
                if (flag == false)
                {
                    cout << "Some attrs not existed!!! " << endl;
                    return;
                }

                /*create condition vector*/
                for (int i = 0; i < sql_temp.command_op_vector.size(); i++)
                {
                    string name = sql_temp.command_left_vector[i];
                    string op = sql_temp.command_op_vector[i];
                    int id;

                    if (op == "=")
                        id = 0;
                    else if (op == "<>")
                        id = 1;
                    else if (op == "<")
                        id = 2;
                    else if (op == ">")
                        id = 3;
                    else if (op == "<=")
                        id = 4;
                    else if (op == ">=")
                        id = 5;
                    else if (op == "like")
                        id = 6;

                    string value = sql_temp.command_right_vector[i];
                    Condition con_d(name, value, id);

                    if (CL.Judge_Attr_Index_Exist(sql_temp.get_table_name(), name))
                    {
                        con_special.push_back(con_d);
                        attr_special.push_back(CL.Get_Attr_Info_Record(sql_temp.get_table_name(), name));
                    }
                    else
                    {
                        con_normal.push_back(con_d);
                        attr_normal.push_back(CL.Get_Attr_Info_Record(sql_temp.get_table_name(), name));
                    }
                }

                RM.and_or_flag = sql.and_or_flag;
                if (attr_special.size() == 0) //no index condition
                {
                    record_num = RM.Record_SelectValue(sql_temp.get_table_name(), all_info, result, all_info, con_normal);
                }
                else
                {
                    if (sql_temp.and_or_flag == 1)
                    {
                        IM.searchMutiCondition(CL.Get_Used_Database(), sql_temp.get_table_name(), con_special, Result);
                        record_num = RM.Record_SelectValue(sql_temp.get_table_name(), Result, all_info, result, all_info, con_normal);
                    }
                    else if (sql_temp.and_or_flag == 2)
                    {
                        vector<class Condition> temp;
                        temp.insert(temp.end(), con_special.begin(), con_special.end());
                        temp.insert(temp.end(), con_normal.begin(), con_normal.end());
                        record_num = RM.Record_SelectValue(sql_temp.get_table_name(), all_info, result, all_info, temp);
                    }
                }
            }
            /*开始输出表数据*/
            cout << "select" << endl;
            string info = "|";
            if (select_flag)
            {
                //输出代取属性列
                for (int i = 0; i < all_info.size(); i++)
                {
                    for (int k = 0; k < select_attr.size(); k++)
                    {
                        if (all_info[i].attr_name == select_attr[k])
                        {
                            info = select_attr[k];
                            cout << info << " ";
                            break;
                        }
                    }
                }
                cout << endl;
                //输出数据
                for (int i = 0; i < result.size(); i++)
                {
                    for (int j = 0; j < result[i].size(); j++)
                    {
                        for (int k = 0; k < select_attr_id.size(); k++)
                        {
                            if (j == select_attr_id[k])
                            {
                                cout << result[i][j] << " ";
                                break;
                            }
                        }
                    }
                    cout << endl;
                }
            }
            else
            {
                //全部属性列
                for (int i = 0; i < all_info.size(); i++)
                {
                    info = all_info[i].attr_name;
                    cout << info << " ";
                }
                cout << endl;
                //输出数据
                for (int i = 0; i < result.size(); i++)
                {
                    for (int j = 0; j < result[i].size(); j++)
                    {
                        cout << result[i][j] << " ";
                    }
                    cout << endl;
                }
            }

            info = to_string(record_num);
            info += " rows in set.";
            end = clock();
            dur = (double)(end - start);
            cout << info << " (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
            break;
        }

        case (SQL_CREATE_TABLE):
        {
            CL.Create_Table(sql_temp);
            break;
        }

        case (SQL_USE_DATABASE):
        {
            CL.Use_Database(sql_temp.get_database_name());
            break;
        }

        case (SQL_SHOW_DATABASES):
        {
            vector<string> Rem = CL.Get_All_Databases();
            cout << "Databases" << endl;
            for (int i = 0; i < Rem.size(); i++)
            {
                cout << Rem[i] << endl;
            }
            break;
        }

        case (SQL_SHOW_TABLES):
        {
            vector<string> Rem = CL.Get_All_Table_Name();
            cout << "Tables" << endl;
            for (int i = 0; i < Rem.size(); i++)
            {
                cout << Rem[i] << endl;
            }
            break;
        }

        case (SQL_CREATE_DATABASE):
        {
            CL.Create_Database(sql_temp.get_database_name());
            break;
        }

            /*update table set id = 5 where ... and ...*/
        case (SQL_UPDATE):
        {
            double dur;
            clock_t start, end;
            start = clock();
            vector<int> Result;
            vector<class Attribute> all_info;
            vector<string> value;
            vector<class Attribute> select_attr;
            int record_num;

            bool flag = true;
            flag = CL.Judge_Table_Exist(sql_temp.get_table_name());

            if (flag == false)
            {
                cout << "No this table!!! " << endl;
                return;
            }

            flag = CL.Judge_Attr(sql_temp.get_col_name(), sql_temp.get_table_name());
            if (flag == false)
            {
                cout << sql_temp.get_col_name() + " no existed!!!" << endl;
                return;
            }

            flag = CL.Judge_Attrs_Exist(sql_temp.get_table_name(), sql_temp.command_left_vector);
            if (flag == false)
            {
                cout << "Some attrs not existed!!! " << endl;
                return;
            }

            /*create condition vector*/
            for (int i = 0; i < sql_temp.command_op_vector.size(); i++)
            {
                string name = sql_temp.command_left_vector[i];
                string op = sql_temp.command_op_vector[i];
                int id;

                if (op == "=")
                    id = 0;
                else if (op == "<>")
                    id = 1;
                else if (op == "<")
                    id = 2;
                else if (op == ">")
                    id = 3;
                else if (op == "<=")
                    id = 4;
                else if (op == ">=")
                    id = 5;
                else if (op == "like")
                    id = 6;

                string value = sql_temp.command_right_vector[i];
                Condition con_d(name, value, id);

                if (CL.Judge_Attr_Index_Exist(sql_temp.get_table_name(), name))
                {
                    con_special.push_back(con_d);
                    attr_special.push_back(CL.Get_Attr_Info_Record(sql_temp.get_table_name(), name));
                }
                else
                {
                    con_normal.push_back(con_d);
                    attr_normal.push_back(CL.Get_Attr_Info_Record(sql_temp.get_table_name(), name));
                }
            }

            all_info = CL.Get_Attr_Info_All_Record(sql_temp.get_table_name());
            value.push_back(sql_temp.get_col_value());
            select_attr.push_back(CL.Get_Attr_Info_Record(sql_temp.get_table_name(), sql_temp.get_col_name()));
            if (con_special.size() == 0) //no index condition
            {
                record_num = RM.Record_Update(sql_temp.get_table_name(), select_attr, value, all_info, con_normal);
            }
            else
            {
                IM.searchMutiCondition(CL.Get_Used_Database(), sql_temp.get_table_name(), con_special, Result);
                record_num = RM.Record_Update(sql_temp.get_table_name(), Result, select_attr, value, all_info, con_normal);
            }
            if (record_num == -1)
                cout << "Duplicate entry for primary key or unique key!!!" << endl;
            else
            {
                end = clock();
                dur = (double)(end - start);
                cout << "Query OK, " + to_string(record_num) + " rows affected"
                     << " (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
            }
            break;
        }
        case (SQL_NO_RESULT):
        {
            cout << "No result!!!" << endl;
            break;
        }
        default:
            break;
        }
    }
    catch (CatalogError e)
    {
        throw e;
    }
}

void API::select_many_table(SqlCommand sql)
{
    SqlCommand sql_temp = sql;

    double dur;
    clock_t start, end;
    start = clock();

    //第一、二张表结果，连接表结果
    SelectResult result, result2, result3;
    //第一、二张表属性，连接表属性
    vector<Attribute> all_info, all_info2, all_info3;
    vector<int> Result;
    int record_num, record_num2, record_num3;

    //代取的表名，待比较的表.属性
    vector<string> select_table = sql_temp.get_select_table();
    vector<string> attr_table;
    vector<string> attr_attr;

    //判断表存在
    for (int i = 0; i < select_table.size(); i++)
    {
        if (!CL.Judge_Table_Exist(select_table[i]))
        {
            cout << "A table no existed!!!" << endl;
            return;
        }
    }

    //判断列存在(左右各一次)
    int pos = 0;
    for (int i = 0; i < sql_temp.command_left_vector.size(); i++)
    {
        string sTable = sql_temp.command_left_vector[i];
        pos = sTable.find(".");
        //左-分表分列
        attr_table.push_back(sTable.substr(0, pos));
        attr_attr.push_back(sTable.substr(pos + 1));
    }

    for (int i = 0; i < sql_temp.command_right_vector.size(); i++)
    {
        string sTable = sql_temp.command_right_vector[i];
        pos = sTable.find(".");
        //右-分表分列
        attr_table.push_back(sTable.substr(0, pos));
        attr_attr.push_back(sTable.substr(pos + 1));
    }

    SelectResult attrs_attrs;
    vector<string> temp;
    temp.push_back(attr_attr[1]);
    attr_attr.pop_back();

    attrs_attrs.push_back(attr_attr);
    attrs_attrs.push_back(temp);

    for (int i = 0; i < attr_table.size(); i++)
    {
        if (!CL.Judge_Attrs_Exist(attr_table[i], attrs_attrs[i]))
        {
            cout << "Some attrs not existed!!! " << endl;
            return;
        }
    }

    //全部的属性列
    all_info = CL.Get_Attr_Info_All_Record(attr_table[0]);
    all_info2 = CL.Get_Attr_Info_All_Record(attr_table[1]);
    for (int i = 0; i < all_info.size(); i++)
    {
        all_info3.push_back(all_info[i]);
    }
    for (int i = 0; i < all_info2.size(); i++)
    {
        all_info3.push_back(all_info2[i]);
    }

    //全部的数据
    record_num = RM.Record_SelectAll(attr_table[0], all_info, result, all_info);
    record_num2 = RM.Record_SelectAll(attr_table[1], all_info2, result2, all_info2);

    //找到第一张表的属性列号
    int aTableAttrId = -1;
    for (int i = 0; i < all_info.size(); i++)
    {
        if (all_info[i].attr_name == attr_attr[0])
        {
            aTableAttrId = i;
            break;
        }
    }
    //找到第二张表的属性列号
    int bTableAttrId = -1;
    for (int i = 0; i < all_info2.size(); i++)
    {
        if (all_info2[i].attr_name == attr_attr[1])
        {
            bTableAttrId = i;
            break;
        }
    }

    //笛卡尔积
    int line1 = result.size();
    int line2 = result2.size();

    //暂存数据
    vector<string> resultTemp;

    for (int i = 0; i < line1; i++)
    {
        for (int j = 0; j < line2; j++)
        {
            if (result[i][aTableAttrId] == result2[j][bTableAttrId])
            {
                for (int k = 0; k < result[i].size(); k++)
                {
                    resultTemp.push_back(result[i][k]);
                }
                for (int k = 0; k < result2[j].size(); k++)
                {
                    resultTemp.push_back(result2[j][k]);
                }
                result3.push_back(resultTemp);
                resultTemp.clear();
            }
        }
    }

    /*开始输出表数据*/
    cout << "select" << endl;
    string info = "|";
    //全部属性列
    for (int i = 0; i < all_info3.size(); i++)
    {
        info = all_info3[i].attr_name;
        cout << info << " ";
    }
    cout << endl;
    //输出数据
    for (int i = 0; i < result3.size(); i++)
    {
        for (int j = 0; j < result3[i].size(); j++)
        {
            cout << result3[i][j] << " ";
        }
        cout << endl;
    }

    info = to_string(record_num);
    info += " rows in set.";
    end = clock();
    dur = (double)(end - start);
    cout << info << " (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
    return;
}

void API::sql_execfile(SqlCommand sql_temp)
{
    ifstream read_in(sql_temp.get_file_name());
    string sql_com;
    string sql_clause = "";

    if (!read_in) //判断文件是否打开
    {
        cout << "Can not open file!" << endl;
        return;
    }

    while (getline(read_in, sql_com)) //sql_com是已经存放在里面的sql命令
    {
        InterPreter inter_temp;

        //跳过注释
        if (sql_com.find('#') != -1)
        {
            sql_com = sql_com.substr(0, sql_com.find('#'));
        }

        if (sql_com.empty())
            continue;

        //找不到结尾符
        if (sql_com.find(';') == -1)
        {
            sql_clause += sql_com;
            continue;
        }
        else
        {
            sql_clause += sql_com;
        }

        sql_com = inter_temp.initial_sentense(sql_clause);

        if (sql_com == "error") //如果出错的话，打印出来就吼了
            cout << "---- Syntax Error! ---- \n"
                 << endl;
        else
        {
            SqlCommand c = inter_temp.Final_expression(sql_com);
            API api(c);
            api.execute(c); //是一个正常的语句的话，重新执行一遍整个语句
        }

        sql_clause = "";
    }
}
