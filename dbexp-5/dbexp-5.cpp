// dbexp-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
string mathod1(string str1);
string mathod2(string str2);
int out_by_tree(string str);
const char key_words[3][20] = { "JOIN","SELECT","PROJECTION" };

int main()
{
	int i = 0;
	string str1 = "SELECT [ ENAME = 'Mary' & DNAME = 'Research' ] ( EMPLOYEE JOIN DEPARTMENT )";
	string str2 = "PROJECTION [ BDATE ] ( SELECT [ ENAME = 'John' & DNAME = ' Research' ] ( EMPLOYEE JOIN DEPARTMENT) )";
	mathod1(str1);
	mathod2(str2);
	cout << str1 << endl;
	cout << str2 << endl;
	
	return 0;
}
string mathod1(string str1)
{

	return str1;
}
string mathod2(string str2)
{
	return str2;
}
int out_by_tree(string str)
{
	return 0;
}