// dbexp-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	//int n;
	int i = 0;
	char sql0[] = "SELECT [ ENAME = 'Mary' & DNAME = 'Research' ] ( EMPLOYEE JOIN DEPARTMENT )";
	
	tree * tree0 = new tree;
	
	//rel spl_rel;
	//ceshi();
	//spl_rel = split(sql1, " ");
	//cout << spl_rel.length<<endl;
	cout << search("DNAME") << endl;
	cout << "___________________________1" << endl;
	tree0 = init_tree("", NULL, NULL, "");
	tree0 = trans_to_tree(sql0);
	//cout << tree0->state;
	out_by_tree(tree0);
	cout << "better##############" << endl;
	tree0 = better(tree0);
	out_by_tree(tree0);
	cout << "___________________________2" << endl;
	char sql1[] = "PROJECTION [ BDATE ] ( SELECT [ ENAME = 'John' & DNAME = ' Research' ] ( EMPLOYEE JOIN DEPARTMENT ) )";
	tree * tree1 = new tree;
	tree1 = init_tree("", NULL, NULL, "");
	tree1 = trans_to_tree(sql1);
	//cout << tree0->state;
	out_by_tree(tree1);
	cout << "better::############" <<endl;
	tree0 = better(tree1);
	out_by_tree(tree1);
	/*cout << "___________________________3" << endl;
	char sql2[] = "PROJECTION [ ENAME ] ( SELECT [ SALARY < 3000 ] ( EMPLOYEE JOIN SELECT [ PNO = 'P1' ] ( WORKS_ON JOIN PROJECT ) )";
	tree * tree2 = new tree;
	tree2 = init_tree("", NULL, NULL, "");
	tree2 = trans_to_tree(sql2);
	//cout << tree0->state;
	out_by_tree(tree2);
	cout << "better##############" << endl;
	tree0 = better(tree2);
	out_by_tree(tree2);*/

	return 0;
}
