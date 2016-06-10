// dbexp-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	char * sql1;
	tree tree0;

	sql1 = "SELECT [ ENAME = 'Mary' & DNAME = 'Research' ] ( EMPLOYEE JOIN DEPARTMENT )";
	char ** a = new char *;
	split(a,sql1, " ");
	cout << search("ENAME") << endl;

	init_tree(tree0, NULL, NULL, NULL, NULL);
	tree0 = trans_to_tree(sql1);
	out_by_tree(tree0);
	better(tree0);
	out_by_tree(tree0);

	return 0;
}
