#include "MySql.h"

int main()
{
	MySql_Select("select * from snacks");
	cout << "ok" << endl;
	return 0;
}