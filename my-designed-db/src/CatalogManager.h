#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <regex>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
// #include <io.h>
#include <dirent.h>
#include "Exception.h"
#include "sqlcommand.h"
#include "BufferManager.h"
#include "RecordManager.h"
using namespace std;

const int MAX_CHAR_SIZE = 255;  // 字符串型属性值的最大长度
const int MAX_NAME_LENGTH = 16; // 属性名的最大长度

// 目录管理
class CatalogManager
{
public:
    string used_Database; // 当前使用的数据库

    CatalogManager();
    ~CatalogManager(){};
    // 创建数据库
    // 同时新建与数据库同名的文件夹，文件夹里面创建该数据库的信息文件 TableList
    // TableList 格式：
    // 表数量
    // { 表名 属性数 实际记录长度 表的block数 { 属性名、数据类型(int)、数据长度、属性类型、索引名、索引的block数 }* }*
    void Create_Database(string DB_Name);
    // 删除数据库
    void Drop_Database(string DB_Name);
    // 使用数据库
    void Use_Database(string DB_Name);
    // 创建表
    // 同时更改 TableList 中的内容
    void Create_Table(SqlCommand &cmd);
    // 删除表
    // 同时删除索引
    void Drop_Table(string Table_Name);
    // 为指定属性创建索引
    // 该属性必须为 unique 属性
    void Create_Index(string Index_Name, string Attr_Name, string DB_Name);
    // 删除索引
    void Drop_Index(string Index_Name);
    // 添加记录
    void Add_Tuple(int num, string Table_Name);
    // 删除记录
    void Delete_Tuple(int num, string Table_Name);
    // 删除表内所有记录
    void Empty_Table(string Table_Name);
    // 获取当前使用的数据库名
    string Get_Used_Database();
    // 获取所有数据库的名字
    vector<string> Get_All_Databases();
    // 获取当前数据库中的所有表名
    vector<string> Get_All_Table_Name();
    // 获取当前数据库中的已经建立的表的个数
    int Get_All_Tables_Num();
    // 获取指定表的所有属性的信息
    vector<string> Get_Attr_Info_All(string Table_Name);
    // 获取指定表的所有记录的属性的信息
    vector<Attribute> Get_Attr_Info_All_Record(string Table_Name);
    // 获取指定表的指定属性的信息
    vector<string> Get_Attr_Info(string Table_Name, string Attr);
    // 获取指定表的指定记录的属性的信息
    Attribute Get_Attr_Info_Record(string Table_Name, string Attr);
    // 获取表的属性数
    int Get_Table_Attr_Num(string Table_Name);
    // 获取当前使用的数据库中的所有表的索引信息
    // 表格名 属性名 索引名
    vector<string> Get_All_Index();
    // 获取当前使用的数据库中的指定表的索引信息
    // 属性名 索引名
    vector<string> Get_Table_Index(string Table_Name);
    // 获取指定表的指定属性的索引信息
    string Get_Index(string Table_Name, string Attr);
    // 获取表的实际记录长度
    int Get_Table_Record_Num(string Table_Name);
    // 获取表中属性的 id
    int Get_Attr_Id(string Table_Name, string Attr_Name);
    // 获取 block 数
    int Get_Block_Num(string name);
    // 设置 block 数
    void Set_Block_Num(string name, int block_num);
    // block 数加一
    void Increase_Block_Num(string name);
    // 获取表的 block 数
    int Get_Table_Block_Num(string Table_Name);
    // 设置表的 block 数
    void Set_Table_Block_Num(string Table_Name, int block_num);
    // 获取索引的 block 数
    int Get_Index_Block_Num(string Index_Name);
    // 设置索引的 block 数
    void Set_Index_Block_Num(string Index_Name, int block_num);
    // 验证表格是否存在
    bool Judge_Table_Exist(string Table_Name);
    // 验证指定属性是否可以建立索引
    bool Judge_Index(string attr_name, string Table_Name);
    // 验证指定属性组在指定表中是否存在
    bool Judge_Attrs_Exist(string Table_Name, vector<string> &Attrs);
    // 验证指定属性是否为指定表的属性
    bool Judge_Attr(string attr_name, string Table_Name);
    // 验证插入的记录是否满足表属性的类型
    bool Judge_Data(vector<string> &Datas, string Table_Name);
    // 验证指定表的指定属性的索引是否存在
    bool Judge_Attr_Index_Exist(string Table_Name, string attr_name);
    // 验证数据库是否存在
    bool Judge_Database_Redundancy(string database);
    // 验证所有属性信息是否满足建表要求
    bool Judge_Attrs(vector<string> &infos);
    // 验证文件是否存在
    bool Judge_File_Exist(string fileName, string path);
    // 验证字符串长度是否符合要求
    bool Judge_String_Length(string &s);
    // 获取文件所有内容
    vector<string> Get_All_Lines(string path);
    // int 转 字符串
    string itoa(int x);
    // 分裂字符串
    vector<string> split(string s);
    // 向文件中写入内容
    void Write_Into_File(string path, vector<string> contents);
};

// 表
class table
{
public:
    string table_name;             // 表名
    int attr_num;                  // 属性数量
    int size;                      // 实际记录长度
    int table_block_size;          // 表的block数
    vector<string> attr_name;      // 属性名
    vector<int> attr_type;         // 属性类型 (float -1, int 0, char 0-255, Date -2 且符合日期类型)
    vector<int> attr_length;       // 属性长度
    vector<string> key_constraint; // 关键字限制，如：primary key, unique, null
    vector<string> index;          // 属性对应的索引名
    vector<int> index_block_size;  // 索引的block数

    table()
    {
        attr_num = 0;
        size = 0;
    }
};
