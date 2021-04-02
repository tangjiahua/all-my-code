#ifndef API_H
#define API_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "sqlcommand.h"
#include "Exception.h"

#include "CatalogManager.h"
#include "BufferManager.h"
#include "IndexManager.h"
#include "RecordManager.h"
#include "interpreter.h"

class API
{
public:
    API(SqlCommand c);

    virtual ~API(void);

    void execute(SqlCommand sql);
    void select_many_table(SqlCommand sql_temp);
    void sql_execfile(SqlCommand sql_temp);

    SqlCommand sql;
    vector<class Attribute> attr;
    vector<class Attribute> attr_special;
    vector<class Attribute> attr_normal;
    vector<class Condition> con;
    vector<class Condition> con_special;
    vector<class Condition> con_normal;

private:
};

#endif // !API_H
