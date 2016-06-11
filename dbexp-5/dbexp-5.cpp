// dbexp-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int n;
	int i = 0;
	char sql1[] = "SELECT [ ENAME = 'Mary' & DNAME = 'Research' ] ( EMPLOYEE JOIN DEPARTMENT )";
	tree tree0;
	rel spl_rel;
	//ceshi();
	spl_rel = split(sql1, " ");
	cout << spl_rel.length<<endl;
	//for (i = 0; i < n; i++)
		//cout << a[i] << endl;
	//cout << search("ENAME") << endl;

	//init_tree(tree0, NULL, NULL, NULL, NULL);
	//tree0 = trans_to_tree(sql1);
	//out_by_tree(tree0);
	//better(tree0);
	//out_by_tree(tree0);

	return 0;
}
