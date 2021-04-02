#include <iostream>
#include <string>
#include "interpreter.h"
#include "API.h"

Buffer bm;
CatalogManager CL;
IndexManager IM;
RecordManager RM;

int main()
{
	InterPreter interpreter;

	while (1)
	{
		try
		{
			string sql = interpreter.Read_input();
			SqlCommand c = interpreter.Final_expression(sql);
			
			API api(c);
			api.execute(c);
		}
		catch (CatalogError e)
		{
			cout << e.what() << endl;
		}
	}

	system("pause");

	return 0;
}
