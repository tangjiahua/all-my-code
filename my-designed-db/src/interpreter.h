#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "sqlcommand.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class InterPreter
{
public:
    string Read_input(); //读入输入的值
    string initial_sentense(string old_sql);    //初始化一个语句
    string Process(string sql);
    string replace_allvalues(string sql, string old_values, string new_values);
    string get_first_word(string sql, string split);
    string del_first_word(string sql, string split);
    string split(string value);
    string get_split_string_value(string sql);
    string get_current_value(string sql, string split);//
    int is_digit(string s);//判断是数字
    int re_judge(string left_data, string right_data, string op);//正则检查

    SqlCommand drop_database(string sql);
    SqlCommand drop_table(string sql);
    SqlCommand drop_index(string sql);
    SqlCommand quit();
    SqlCommand execfile(string sql);//通过文件执行
    SqlCommand create_index(string sql);
    SqlCommand insert_values(string sql);
    SqlCommand delete_from(string sql);
    SqlCommand select_from(string sql);
    SqlCommand create_table(string sql);
    SqlCommand use_database(string sql);
    SqlCommand show_databases(string sql);
    SqlCommand show_tables(string sql);
    SqlCommand create_database(string sql);
    SqlCommand update_table(string sql);

    SqlCommand Final_expression(string sql); //根据输入来判断到底是哪种形式，unique, primary
};

#endif // !INTERPRETER_H
