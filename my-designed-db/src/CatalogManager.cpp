#include "CatalogManager.h"
#include "IndexManager.h"

extern IndexManager IM;

CatalogManager::CatalogManager()
{
    used_Database = "";
    if (!Judge_File_Exist("DB", "./"))
    {
        string dic_name = "DB";
        int status = mkdir(dic_name.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
        if (status != 0)
        {
            throw CatalogError("Create database catalog failed!!! ");
        }
    }
}

void CatalogManager::Create_Database(string DB_Name)
{
    double dur;
    clock_t start, end;
    start = clock();
    if (!Judge_String_Length(DB_Name))
    {
        throw CatalogError("Too long name!!!");
    }

    bool flag;
    fstream f;
    int num;
    string DBs;
    f.open("./DB/DBList", ios::in);
    if (f.fail())
    {
        flag = false;
    }
    else
    {
        int FLAG = 0;
        string line;
        while (getline(f, line))
        {
            if (line.size() != 0)
            {
                if (FLAG == 0)
                {
                    num = atoi(line.c_str());
                    FLAG = 1;
                }
                else
                {
                    DBs = line;
                }
            }
        }
        flag = true;
        f.close();
    }

    if (flag)
    {
        int i;
        vector<string> DB_Names = split(DBs);
        for (i = 0; i < DB_Names.size(); i++)
        {
            if (DB_Names[i] == DB_Name)
            {
                throw CatalogError("This database is already existed!!!");
            }
        }
        num++;
        int status;
        string path = "./DB/" + DB_Name;
        status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
        if (status == -1)
        {
            throw CatalogError("Can not create database!!!");
        }
        else
        {
            fstream fout;
            fout.open("./DB/" + DB_Name + "/TableList", ios::out);
            if (fout.fail())
            {
                throw CatalogError("Open failed!!!");
            }
            fout << 0 << endl; // 初始化数据库，0个表
            fout.close();
            DBs = DBs + DB_Name + " ";
            vector<string> contents;
            contents.push_back(itoa(num));
            contents.push_back(DBs);
            Write_Into_File("./DB/DBList", contents);
            end = clock();
            dur = (double)(end - start);
            cout << "Succeed! (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
        }
    }
    else
    {
        int status;
        string path = "./DB/" + DB_Name;
        status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
        if (status == -1)
        {
            throw CatalogError("Can not create database!!!");
        }
        else
        {
            fstream fout;
            fout.open("./DB/" + DB_Name + "/TableList", ios::out);
            if (fout.fail())
            {
                throw CatalogError("Open failed!!!");
            }
            fout << 0 << endl; //初始化数据库，0个表
            fout.close();
            DBs = DB_Name + " ";
            vector<string> contents;
            contents.push_back(itoa(1));
            contents.push_back(DBs);
            Write_Into_File("./DB/DBList", contents); // 写
            end = clock();
            dur = (double)(end - start);
            cout << "Succeed! (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
        }
    }
}

void CatalogManager::Use_Database(string DB_Name)
{
    bool flag;
    flag = Judge_File_Exist(DB_Name, "./DB/");
    if (!flag)
    {
        throw CatalogError("No this database!!!");
    }
    else
    {
        this->used_Database = DB_Name;
        cout << "Database changes!" << endl;
        ;
    }
}

void CatalogManager::Drop_Database(string DB_Name)
{
    double dur;
    clock_t start, end;
    start = clock();
    string path = "./DB/DBList";
    vector<string> lines;
    try
    {
        lines = Get_All_Lines(path);
    }
    catch (CatalogError e)
    {
        throw e;
    }
    int num = atoi(lines[0].c_str());
    vector<string> DBs = split(lines[1]);

    bool flag = false;
    for (int i = 0; i < DBs.size(); i++)
    {
        if (DBs[i] == DB_Name)
        {
            num--;
            lines[0] = itoa(num);
            flag = true;
            string cmd;
            cmd = "rm -R ./DB/" + DB_Name;
            pid_t status;
            status = system(cmd.c_str());
            if (status == -1)
            {
                throw CatalogError("Delete failed!!!");
            }
            else
            {
                if (used_Database == DB_Name)
                {
                    used_Database = "";
                }
                num--;
                vector<string>::iterator p = DBs.begin() + i;
                DBs.erase(p);
                lines[1] = "";
                for (int j = 0; j < DBs.size(); j++)
                {
                    lines[1] = lines[1] + DBs[j] + " ";
                }
                end = clock();
                dur = (double)(end - start);
                cout << "Succeed! (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
            }
            break;
        }
    }

    if (flag)
    {
        Write_Into_File(path, lines);
    }
    else
    {
        throw CatalogError("No this database!!!");
    }
}

void CatalogManager::Create_Table(SqlCommand &cmd)
{
    double dur;
    clock_t start, end;
    start = clock();
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    string Table_Name = cmd.get_table_name();
    vector<string> tableName = Get_All_Table_Name();
    int i;
    for (i = 0; i < tableName.size(); i++)
    {
        if (Table_Name == tableName[i])
        {
            throw CatalogError("This table is already existed!!!");
        }
    }

    table t;
    t.table_name = cmd.get_table_name();
    t.attr_num = (int)cmd.col_name_vector.size();
    t.table_block_size = 0;

    if (t.attr_num > 32)
    {
        throw CatalogError("Too more attrs!!!");
    }

    vector<string> infos;
    for (int i = 0; i < t.attr_num; i++)
    {
        if (!Judge_String_Length(cmd.col_name_vector[i]))
        {
            throw CatalogError("Too long name!!!");
        }
        infos.push_back(cmd.col_name_vector[i]);
        infos.push_back(itoa(cmd.value_type[i]));
        infos.push_back(cmd.col_special_vector[i]);
    }
    bool flag = Judge_Attrs(infos);

    if (!flag)
    {
        throw CatalogError("Wrong attr!!!");
    }

    for (int i = 0; i < t.attr_num; i++)
    {
        t.attr_name.push_back(cmd.col_name_vector[i]);
        t.attr_type.push_back(cmd.value_type[i]);
        int length;
        if (cmd.value_type[i] > 0)
        {
            length = sizeof(char) * cmd.value_type[i];
        }
        else if (cmd.value_type[i] == 0)
        {
            length = sizeof(int);
        }
        else
        {
            length = sizeof(float);
        }
        t.attr_length.push_back(length);
        t.key_constraint.push_back(cmd.col_special_vector[i]);
        string index_name = "null";
        if (cmd.col_special_vector[i] == "primary")
        {
            index_name = t.table_name + "-" + t.attr_name[i] + "-index";
        }
        t.index.push_back(index_name);
        t.index_block_size.push_back(0);
    }

    ostringstream new_line;
    new_line << t.table_name;
    new_line << " " << t.attr_num;
    new_line << " " << t.size;
    new_line << " " << t.table_block_size;
    for (int i = 0; i < t.attr_num; i++)
    {
        new_line << " " << t.attr_name[i];
        new_line << " " << t.attr_type[i];
        new_line << " " << t.attr_length[i];
        new_line << " " << t.key_constraint[i];
        new_line << " " << t.index[i];
        new_line << " " << t.index_block_size[i];
    }
    string present_table = new_line.str();

    vector<string> lines;
    string line;
    string path = "./DB/" + used_Database + "/TableList";
    lines = Get_All_Lines(path);
    int tabel_num = atoi(lines[0].c_str());
    tabel_num++;
    ostringstream ss;
    ss << tabel_num;
    line = ss.str();
    lines[0] = line;
    lines.push_back(present_table);

    Write_Into_File(path, lines);

    for (int i = 0; i < t.attr_num; i++)
    {
        if (cmd.col_special_vector[i] == "primary")
        {
            string index_name = t.table_name + "-" + t.attr_name[i] + "-index";
            IM.createIndex(used_Database, t.table_name, t.attr_name[i], index_name, t.attr_type[i]);
        }
    }
    end = clock();
    dur = (double)(end - start);
    cout << "Succeed! (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
}

void CatalogManager::Drop_Table(string Table_Name)
{
    double dur;
    clock_t start, end;
    start = clock();
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    // 确认表的存在
    int i;
    vector<string> tableName = Get_All_Table_Name();
    for (i = 0; i < tableName.size(); i++)
    {
        if (tableName[i] == Table_Name)
        {
            break;
        }
    }
    if (i == tableName.size())
    {
        throw CatalogError("No this table!!!");
    }

    // 删表
    string path;
    path = "./DB/" + used_Database + "/" + Table_Name;

    bm.deleteFile(Table_Name);

    //删索引
    vector<string> attrs = Get_Attr_Info_All(Table_Name);
    for (int i = 0; i < attrs.size(); i++)
    {
        vector<string> words = split(attrs[i]);
        if (words[4] == "null")
        {
            continue;
        }
        else
        {
            string attr = words[0];
            int type = atoi(words[1].c_str());
            string index = Table_Name + "-" + attr + "-index";
            //            cout<<attr<<" "<<index<<" "<<type<<endl;
            IM.dropIndex(used_Database, Table_Name, attr, index, type);
        }
    }

    // 更改数据字典
    string line;
    path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);
    int tabel_num = atoi(lines[0].c_str());
    tabel_num--;
    ostringstream ss;
    ss << tabel_num;
    line = ss.str();
    lines[0] = line;

    vector<string>::iterator p = lines.begin() + i + 1;
    lines.erase(p);
    Write_Into_File(path, lines);
    end = clock();
    dur = (double)(end - start);
    cout << "Succeed! (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
}

void CatalogManager::Create_Index(string Index_Name, string Table_Name, string Attr_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    if (!Judge_String_Length(Index_Name))
    {
        throw CatalogError("Too long name!!!");
    }

    string path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);

    int i;
    int j;
    vector<string> words;
    bool flag = false;
    for (i = 0; i < lines.size(); i++)
    {
        words = split(lines[i]);
        if (words[0] == Table_Name)
        {
            for (j = 0; j < atoi(words[1].c_str()); j++)
            {
                if (words[j * 6 + 4] == Attr_Name)
                {
                    if (words[j * 6 + 7] == "primary")
                    {
                        if (words[j * 6 + 8] == "null")
                        {
                            //建索引
                            string index_name = Table_Name + "-" + Attr_Name + "-index";
                            IM.createIndex(used_Database, Table_Name, Attr_Name, index_name, atoi(words[j * 6 + 5].c_str()));

                            words[j * 6 + 8] = Index_Name;
                            string new_line;
                            for (int k = 0; k < words.size(); k++)
                            {
                                new_line = new_line + words[k] + " ";
                            }
                            lines[i] = new_line;
                            flag = true;
                            break;
                        }
                        else
                        {
                            throw CatalogError("This index is already existed!!!");
                        }
                    }
                    else if (words[j * 6 + 7] == "unique")
                    {
                        if (words[j * 6 + 8] == "null")
                        {
                            //建索引
                            string index_name = Table_Name + "-" + Attr_Name + "-index";

                            IM.createIndex(used_Database, Table_Name, Attr_Name, index_name, atoi(words[j * 6 + 5].c_str()));

                            words[j * 6 + 8] = Index_Name;
                            string new_line;
                            for (int k = 0; k < words.size(); k++)
                            {
                                new_line = new_line + words[k] + " ";
                            }
                            lines[i] = new_line;
                            flag = true;

                            break;
                        }
                        else
                        {
                            throw CatalogError("This index is already existed!!!");
                        }
                    }
                    else if (words[j * 6 + 7] == "null")
                    {
                        throw CatalogError("Can not create index on this attr!!!");
                    }
                }
            }
            break;
        }
    }
    if (flag)
    {
        Write_Into_File(path, lines);
        cout << "Succeed!";
    }
    else
    {
        throw CatalogError("Can not create index!!!");
    }
}

void CatalogManager::Drop_Index(string Index_Name)
{
    double dur;
    clock_t start, end;
    start = clock();
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    string path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);
    vector<string> words;

    int i;
    int j;
    bool flag = false;
    for (i = 1; i < lines.size(); i++)
    {
        words = split(lines[i]);
        int attr_num = atoi(words[1].c_str());
        for (j = 0; j < attr_num; j++)
        {
            if (words[j * 6 + 8] == Index_Name)
            {
                words[j * 6 + 8] = "null";
                //删除索引
                string index_name = words[0] + "-" + words[j * 6 + 4] + "-index";
                IM.dropIndex(used_Database, words[0], words[j * 6 + 4], index_name, atoi(words[j * 6 + 5].c_str()));

                string new_line;
                for (int k = 0; k < words.size(); k++)
                {
                    new_line = new_line + words[k] + " ";
                }
                lines[i] = new_line;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    if (flag)
    {
        Write_Into_File(path, lines);
        end = clock();
        dur = (double)(end - start);
        cout << "Succeed!! (" << dur / CLOCKS_PER_SEC << " sec)" << endl;
    }
    else
    {
        throw CatalogError("No this index!!!");
    }
}

void CatalogManager::Empty_Table(string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    string path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);
    vector<string> words;
    int i;

    bool flag = false;
    for (i = 1; i < lines.size(); i++)
    {
        words = split(lines[i]);

        if (words[0] == Table_Name)
        {
            words[2] = "0";
            string new_line;
            for (int k = 0; k < words.size(); k++)
            {
                new_line = new_line + words[k] + " ";
            }
            lines[i] = new_line;
            flag = true;
            break;
        }
    }

    if (flag)
    {
        Write_Into_File(path, lines);
    }
    else
    {
        throw CatalogError("No this table!!!");
    }
}

void CatalogManager::Add_Tuple(int num, string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    string path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);
    vector<string> words;
    int i;

    bool flag = false;
    for (i = 1; i < lines.size(); i++)
    {
        words = split(lines[i]);

        if (words[0] == Table_Name)
        {
            int n = atoi(words[2].c_str()) + num;
            words[2] = itoa(n);
            string new_line;
            for (int k = 0; k < words.size(); k++)
            {
                new_line = new_line + words[k] + " ";
            }
            lines[i] = new_line;
            flag = true;
            break;
        }
    }

    if (flag)
    {
        Write_Into_File(path, lines);
    }
    else
    {
        throw CatalogError("No this table!!!");
    }
}

void CatalogManager::Delete_Tuple(int num, string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    string path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);
    vector<string> words;
    int i;

    bool flag = false;
    for (i = 1; i < lines.size(); i++)
    {
        words = split(lines[i]);

        if (words[0] == Table_Name)
        {
            int n = atoi(words[2].c_str()) - num;
            if (n < 0)
            {
                throw CatalogError("Wrong!!!");
            }
            words[2] = itoa(n);
            string new_line;
            for (int k = 0; k < words.size(); k++)
            {
                new_line = new_line + words[k] + " ";
            }
            lines[i] = new_line;
            flag = true;
            break;
        }
    }

    if (flag)
    {
        Write_Into_File(path, lines);
    }
    else
    {
        throw CatalogError("No this table!!!");
    }
}

string CatalogManager::Get_Used_Database()
{
    return used_Database;
}

vector<string> CatalogManager::Get_All_Databases()
{
    vector<string> DB_Names;
    fstream f;
    f.open("./DB/DBList", ios::in);
    if (f.fail())
    {
        throw CatalogError("No database!!!");
    }
    string line;
    bool flag = false;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            if (!flag)
            {
                flag = true;
                continue;
            }
            else
            {
                DB_Names = split(line);
            }
        }
    }
    if (DB_Names.size() == 0)
    {
        throw CatalogError("No database!!!");
    }
    else
    {
        return DB_Names;
    }
}

vector<string> CatalogManager::Get_All_Table_Name()
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    vector<string> tableName;
    vector<string> stringList;
    ifstream fin;
    fin.open("./DB/" + used_Database + "/TableList", ios::in);
    if (fin.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    int num = -1;
    string line;

    while (getline(fin, line))
    {
        if (line.length() == 0)
            continue;

        if (num == -1)
        {
            num = stoi(line);
        }
        else
        {
            stringList = split(line);
            tableName.push_back(stringList[0]);
        }
    }
    fin.close();

    return tableName;
}

int CatalogManager::Get_All_Tables_Num()
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    ifstream fin;
    fin.open("./DB/" + used_Database + "/TableList", ios::in);
    if (fin.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    int num = -1;
    vector<string> stringList;
    string line;

    while (getline(fin, line))
    {
        if (line.length() == 0)
        {
            continue;
        }
        else
        {
            stringList = split(line);
            num = atoi(stringList[0].c_str());
            break;
        }
    }

    return num;
}

vector<string> CatalogManager::Get_Attr_Info_All(string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    fstream f;
    string path;
    path = "./DB/" + used_Database + "/TableList";
    f.open(path, ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    string line;
    vector<string> words;
    vector<string> results;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            words = split(line);
            if (words[0] == Table_Name)
            {
                int count = atoi(words[1].c_str());
                for (int i = 0; i < count; i++)
                {
                    string tmp;
                    tmp = tmp + words[4 + i * 6] + " ";
                    tmp = tmp + words[5 + i * 6] + " ";
                    tmp = tmp + words[6 + i * 6] + " ";
                    tmp = tmp + words[7 + i * 6] + " ";
                    tmp = tmp + words[8 + i * 6] + " ";
                    results.push_back(tmp);
                }
                break;
            }
        }
    }
    f.close();
    return results;
}

vector<Attribute> CatalogManager::Get_Attr_Info_All_Record(string Table_Name)
{
    vector<Attribute> results;
    vector<string> attrs = Get_Attr_Info_All(Table_Name);
    int i;
    for (i = 0; i < attrs.size(); i++)
    {
        vector<string> words = split(attrs[i]);
        Attribute attr;
        attr.attr_name = words[0];
        if (atoi(words[1].c_str()) > 0)
        {
            attr.attr_type = CHAR;
            attr.attr_len = atoi(words[1].c_str());
        }
        else if (atoi(words[1].c_str()) == 0)
        {
            attr.attr_type = INT;
            attr.attr_len = sizeof(int);
        }
        else if (atoi(words[1].c_str()) == -1)
        {
            attr.attr_type = FLOAT;
            attr.attr_len = sizeof(float);
        }
        else if (atoi(words[1].c_str()) == -2)
        {
            attr.attr_type = DATE;
            attr.attr_len = 19;
        }
        if (words[3] == "primary")
        {
            attr.attr_key_type = PRIMARY;
        }
        else if (words[3] == "unique")
        {
            attr.attr_key_type = UNIQUE;
        }
        else if (words[3] == "null")
        {
            attr.attr_key_type = EMPTY;
        }

        attr.attr_id = i;

        results.push_back(attr);
    }

    return results;
}

Attribute CatalogManager::Get_Attr_Info_Record(string Table_Name, string Attr)
{
    vector<string> words = Get_Attr_Info(Table_Name, Attr);
    Attribute attr;
    attr.attr_name = words[0];
    if (atoi(words[1].c_str()) > 0)
    {
        attr.attr_type = CHAR;
        attr.attr_len = atoi(words[1].c_str());
    }
    else if (atoi(words[1].c_str()) == 0)
    {
        attr.attr_type = INT;
        attr.attr_len = sizeof(int);
    }
    else
    {
        attr.attr_type = FLOAT;
        attr.attr_len = sizeof(float);
    }

    if (words[3] == "primary")
    {
        attr.attr_key_type = PRIMARY;
    }
    else if (words[3] == "unique")
    {
        attr.attr_key_type = UNIQUE;
    }
    else if (words[3] == "null")
    {
        attr.attr_key_type = EMPTY;
    }

    attr.attr_id = Get_Attr_Id(Table_Name, Attr);

    return attr;
}

int CatalogManager::Get_Table_Attr_Num(string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    fstream f;
    string path;
    path = "./DB/" + used_Database + "/TableList";
    f.open(path, ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    string line;
    vector<string> words;
    vector<string> results;
    int num = -1;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            words = split(line);
            if (words[0] == Table_Name)
            {
                num = atoi(words[1].c_str());
                break;
            }
        }
    }
    f.close();

    if (num == -1)
    {
        throw CatalogError("No this table!!!");
    }
    else
    {
        return num;
    }
}

vector<string> CatalogManager::Get_Attr_Info(string Table_Name, string Attr)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    vector<string> all_Attr = Get_Attr_Info_All(Table_Name);

    int i;
    for (i = 0; i < all_Attr.size(); i++)
    {
        vector<string> words = split(all_Attr[i]);
        if (words[0] == Attr)
        {
            return words;
        }
    }

    throw CatalogError("No this attr!!! ");
}

vector<string> CatalogManager::Get_All_Index()
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    fstream f;
    string path;
    path = "./DB/" + used_Database + "/TableList";
    f.open(path, ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    string line;
    vector<string> words;
    vector<string> results;
    bool first = false;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            if (!first)
            {
                first = true;
                continue;
            }
            words = split(line);
            string Table_Name = words[0];
            int count = atoi(words[1].c_str());
            for (int i = 0; i < count; i++)
            {
                if (words[8 + i * 6] == "null")
                {
                    continue;
                }
                string tmp;
                tmp = tmp + Table_Name + " ";
                tmp = tmp + words[4 + i * 6] + " ";
                tmp = tmp + words[8 + i * 6] + " ";
                results.push_back(tmp);
            }
        }
    }
    f.close();
    return results;
}

vector<string> CatalogManager::Get_Table_Index(string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    fstream f;
    string path;
    path = "./DB/" + used_Database + "/TableList";
    f.open(path, ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    string line;
    vector<string> words;
    vector<string> results;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            vector<string> words = split(line);
            if (words[0] == Table_Name)
            {
                int num = atoi(words[1].c_str());
                for (int i = 0; i < num; i++)
                {
                    if (words[6 * i + 8] != "null")
                    {
                        results.push_back(words[6 * i + 4]);
                        string index_name = Table_Name + "-" + words[6 * i + 4] + "-index";
                        results.push_back(index_name);
                    }
                }
                break;
            }
        }
    }
    f.close();
    return results;
}

string CatalogManager::Get_Index(string Table_Name, string Attr)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    fstream f;
    string path;
    path = "./DB/" + used_Database + "/TableList";
    f.open(path, ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    string line;
    vector<string> words;
    vector<string> results;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            words = split(line);
            if (words[0] == Table_Name)
            {
                int count = atoi(words[1].c_str());
                for (int i = 0; i < count; i++)
                {
                    if (words[4 + i * 6] == Attr)
                    {
                        f.close();
                        return words[8 + i * 6];
                    }
                }
                f.close();
                throw CatalogError("No this attr!!! ");
            }
        }
    }
    f.close();
    throw CatalogError("No this table!!!");
}

int CatalogManager::Get_Table_Record_Num(string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    fstream f;
    string path;
    path = "./DB/" + used_Database + "/TableList";
    f.open(path, ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    string line;
    vector<string> words;
    vector<string> results;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            words = split(line);
            if (words[0] == Table_Name)
            {
                int count = atoi(words[2].c_str());
                f.close();
                return count;
            }
        }
    }
    f.close();
    throw CatalogError("No this table!!!");
}

int CatalogManager::Get_Attr_Id(string Table_Name, string Attr_Name)
{
    vector<string> attrs = Get_Attr_Info_All(Table_Name);
    int i;
    for (i = 0; i < attrs.size(); i++)
    {
        vector<string> words = split(attrs[i]);
        if (words[0] == Attr_Name)
        {
            return i;
        }
    }
    if (i == attrs.size())
    {
        throw CatalogError("No this table!!!");
    }
    else
    {
        throw CatalogError("No this attr!!! ");
    }
}

int CatalogManager::Get_Block_Num(string name)
{
    regex s(".*(-index)$");
    bool flag = regex_match(name, s);
    if (flag)
    {
        return Get_Index_Block_Num(name);
    }
    else
    {
        return Get_Table_Block_Num(name);
    }
}

void CatalogManager::Set_Block_Num(string name, int block_num)
{
    regex s(".*(-index)$");
    bool flag = regex_match(name, s);
    if (flag)
    {
        Set_Index_Block_Num(name, block_num);
    }
    else
    {
        Set_Table_Block_Num(name, block_num);
    }
}

void CatalogManager::Increase_Block_Num(string name)
{
    regex s(".*(-index)$");
    bool flag = regex_match(name, s);
    if (flag)
    {
        int num = Get_Index_Block_Num(name);
        num++;
        Set_Index_Block_Num(name, num);
    }
    else
    {
        int num = Get_Table_Block_Num(name);
        num++;
        Set_Table_Block_Num(name, num);
    }
}

int CatalogManager::Get_Table_Block_Num(string Table_Name)
{
    string path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);
    int num = (int)lines.size();
    int i;
    for (i = 1; i < num; i++)
    {
        vector<string> words;
        words = split(lines[i]);
        if (words[0] == Table_Name)
        {
            return atoi(words[3].c_str());
        }
    }

    return -1;
}

int CatalogManager::Get_Index_Block_Num(string Index_Name)
{
    int index = (int)Index_Name.find("-");
    string Table_Name;
    for (int j = 0; j < index; j++)
    {
        Table_Name = Table_Name + Index_Name.at(j);
    }
    string path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);
    int num = (int)lines.size();
    int i;
    for (i = 1; i < num; i++)
    {
        vector<string> words;
        words = split(lines[i]);
        int n = atoi(words[1].c_str());
        for (int j = 0; j < n; j++)
        {
            if (words[6 * j + 8] != "null")
            {
                string new_index_name = words[0] + "-" + words[j * 6 + 4] + "-index";
                if (new_index_name == Index_Name)
                {
                    return atoi(words[6 * j + 9].c_str());
                }
            }
        }
    }
    return -1;
}

void CatalogManager::Set_Table_Block_Num(string Table_Name, int block_num)
{
    string path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);
    vector<string> words;
    for (int i = 1; i < lines.size(); i++)
    {
        words = split(lines[i]);
        if (words[0] == Table_Name)
        {
            words[3] = itoa(block_num);
            lines[i] = "";
            for (int j = 0; j < words.size(); j++)
            {
                lines[i] = lines[i] + words[j] + " ";
            }
            break;
        }
    }
    Write_Into_File(path, lines);
}

void CatalogManager::Set_Index_Block_Num(string Index_Name, int block_num)
{
    int index = (int)Index_Name.find("-");
    string Table_Name;
    for (int j = 0; j < index; j++)
    {
        Table_Name = Table_Name + Index_Name.at(j);
    }
    string path = "./DB/" + used_Database + "/TableList";
    vector<string> lines = Get_All_Lines(path);
    vector<string> words;
    for (int i = 1; i < lines.size(); i++)
    {
        words = split(lines[i]);
        if (words[0] == Table_Name)
        {
            int num = atoi(words[1].c_str());
            for (int j = 0; j < num; j++)
            {
                if (words[j * 6 + 8] != "null")
                {
                    string new_index_name = words[0] + "-" + words[j * 6 + 4] + "-index";
                    if (new_index_name == Index_Name)
                    {
                        words[j * 6 + 9] = itoa(block_num);
                        break;
                    }
                }
            }
            lines[i] = "";
            for (int j = 0; j < words.size(); j++)
            {
                lines[i] = lines[i] + words[j] + " ";
            }
            break;
        }
    }
    Write_Into_File(path, lines);
}

bool CatalogManager::Judge_Database_Redundancy(string database)
{
    fstream f;
    f.open("./DB/DBList", ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    string line;
    vector<string> DBs;
    bool flag = false;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            if (!flag)
            {
                flag = true;
            }
            else
            {
                DBs = split(line);
                for (int i = 0; i < DBs.size(); i++)
                {
                    if (DBs[i] == database)
                    {
                        return true;
                    }
                }
                return false;
            }
        }
    }
    return false;
}

bool CatalogManager::Judge_Table_Exist(string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    fstream f;
    string path = "./DB/" + used_Database + "/TableList";
    f.open(path, ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    string line;
    vector<string> list;
    bool flag = false;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            if (!flag)
            {
                flag = true;
            }
            else
            {
                list = split(line);
                if (list[0] == Table_Name)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CatalogManager::Judge_Attrs(vector<string> &infos)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    int i;
    bool primary = false;
    regex name("^[a-zA-z_][0-9a-zA-z_]*");
    int num = ((int)infos.size() + 1) / 3;
    for (i = 0; i < num; i++)
    {
        bool flag = regex_match(infos[3 * i], name);
        if (!flag)
        {
            return false;
        }
        int type = atoi(infos[3 * i + 1].c_str());
        if (type > MAX_CHAR_SIZE)
        {
            return false;
        }
        if (infos[3 * i + 2] == "primary")
        {
            if (!primary)
            {
                primary = true;
            }
            else
            {
                return false;
            }
        }
    }

    if (!primary)
    {
        return false;
    }

    return true;
}

bool CatalogManager::Judge_Index(string attr_name, string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    fstream f;
    string path = "./DB/" + used_Database + "/TableList";
    f.open(path, ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    string line;
    vector<string> list;
    while (getline(f, line))
    {
        if (line.length() != 0)
        {
            list = split(line);
            if (list[0] == Table_Name)
            {
                int num;
                num = atoi(list[1].c_str());
                for (int i = 0; i < num; i++)
                {
                    if (list[6 * i + 4] == attr_name)
                    {
                        if (list[6 * i + 8] == "null" && (list[6 * i + 7] == "primary" || list[6 * i + 7] == "unique"))
                        {
                            f.close();
                            return true;
                        }
                        else
                        {
                            f.close();
                            return false;
                        }
                    }
                }
                break;
            }
        }
    }
    return false;
}

bool CatalogManager::Judge_Attrs_Exist(string Table_Name, vector<string> &Attrs)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    vector<string> attr_List;
    attr_List = Get_Attr_Info_All(Table_Name);
    for (int i = 0; i < Attrs.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < attr_List.size(); j++)
        {
            if (Attrs[i] == split(attr_List[j])[0])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            return false;
        }
    }
    return true;
}

bool CatalogManager::Judge_Attr(string attr_name, string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    vector<string> attr_List;
    attr_List = Get_Attr_Info_All(Table_Name);
    for (int i = 0; i < attr_List.size(); i++)
    {
        if (split(attr_List[i])[0] == attr_name)
        {
            return true;
        }
    }
    return false;
}

bool CatalogManager::Judge_Data(vector<string> &Datas, string Table_Name)
{
    if (used_Database == "")
    {
        throw CatalogError("No database!!!");
    }

    regex integer("^-?\\d+$");
    regex wrong_int("^-?0+0*\\d+$");
    regex float_num("^-?[0-9]+\\.[0-9]+");
    regex date("^[1-2][0-9][0-9][0-9]\\.[0-1][0-9]\\.[0-2][0-9]-[0-2][0-9]:[0-5][0-9]:[0-5][0-9]$");
    vector<string> attr_List = Get_Attr_Info_All(Table_Name);
    for (int i = 0; i < attr_List.size(); i++)
    {
        vector<string> words = split(attr_List[i]);
        if (atoi(words[1].c_str()) > 0)
        {
            if (Datas[i].length() > atoi(words[1].c_str()))
            {
                return false;
            }
        }
        if (atoi(words[1].c_str()) == 0)
        {
            if (regex_match(Datas[i], integer))
            {
                if (regex_match(Datas[i], wrong_int))
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if (atoi(words[1].c_str()) == -1)
        {
            if (regex_match(Datas[i], float_num))
            {
                continue;
            }
            else // int
            {
                if (regex_match(Datas[i], integer))
                {
                    if (regex_match(Datas[i], wrong_int))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (atoi(words[1].c_str()) == -2)
        {
            if (regex_match(Datas[i], date))
            {
                continue;
            }
            else
            {
                return false;
            }
            
        }
    }
    return true;
}

bool CatalogManager::Judge_Attr_Index_Exist(string Table_Name, string attr_name)
{
    vector<string> words = Get_Attr_Info(Table_Name, attr_name);
    if (words[4] != "null")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CatalogManager::Judge_File_Exist(string fileName, string path)
{
    int status;
    string relative_path = path + fileName;
    status = access(relative_path.c_str(), 0);
    if (status == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<string> CatalogManager::split(string s)
{
    vector<string> stringList;
    istringstream ss(s);
    string tmp;
    while (ss >> tmp)
    {
        stringList.push_back(tmp);
    }
    return stringList;
}

vector<string> CatalogManager::Get_All_Lines(string path)
{
    fstream f;
    f.open(path, ios::in);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    vector<string> lines;
    string line;
    while (getline(f, line))
    {
        if (line.size() != 0)
        {
            lines.push_back(line);
        }
    }
    f.close();

    return lines;
}

void CatalogManager::Write_Into_File(string path, vector<string> contents)
{
    fstream f;
    f.open(path, ios::out);
    if (f.fail())
    {
        throw CatalogError("Open failed!!! ");
    }
    int i;
    for (i = 0; i < contents.size(); i++)
    {
        f << contents[i] << endl;
    }
    f.close();
}

string CatalogManager::itoa(int x)
{
    ostringstream ss;
    ss << x;
    return ss.str();
}

bool CatalogManager::Judge_String_Length(string &s)
{
    if (s.size() > MAX_NAME_LENGTH)
        return false;
    else
        return true;
}
