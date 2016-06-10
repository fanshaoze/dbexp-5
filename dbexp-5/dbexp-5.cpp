// dbexp-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
struct tree;
typedef struct tree
{
	string state;
	tree* left;
	tree* right;
	string content;
}tree;

tree init_tree(tree tree0,string state, tree* left, tree* right, string content);
tree better(string str);
string find(string str);
tree trans_to_tree(string str);
int out_by_tree(string str);
string search(string s);
const char key_words[4][20][20] =
{ {"ESSN", "ADDRESS", "SALARY", "SUPERSSN", "ENAME", "DNO"},
{"DNO", "DNAME", "DNEMBER", "MGRSSN", "MGRSTARTDATE" },
{"PNAME", "PNO", "PLOCATION", "DNO"},
{"HOURS", "P.ESSN", "PNO"} };
//struct tree; 


int main()
{
	int i = 0;
	string str1 = "SELECT [ ENAME = 'Mary' & DNAME = 'Research' ] ( EMPLOYEE JOIN DEPARTMENT ) ";
	string str2 = "PROJECTION [ BDATE ] ( SELECT [ ENAME = 'John' & DNAME = ' Research' ] ( EMPLOYEE JOIN DEPARTMENT) ) ";
	cout << str1 << endl;
	cout << str2 << endl;
	return 0;
}
tree init_tree(tree tree0, string state, tree* left, tree* right, string content)
{
	tree0.left = new tree;
	tree0.right = new tree;
	tree0.state = state;
	tree0.left = left;
	tree0.right = right;
	tree0.content = content;
	return tree0;
}
tree better(string str)
{
	tree tree_now;
	return tree_now;
}
string search(string s)
{
	int i;
	int k;
	for (i = 0; i < 4; i++)
	{
		for (k = 0; k < sizeof(key_words[i]); i++)
		{
			if (key_words[i][k] == s)
			{
				if (i == 0) return "EMPLOYEE";
				else if (i == 1) return "DEPARTMENT";
				else if (i == 2) return "PROJECT";
				else return "WORKS_ON";
			}
		}
	}
	return "NOTHING";
}
tree trans_to_tree(string str)
{
	int i = 0;
	int n = 0;
	char split[100][20];
	int strlen = str.length();
	int t = 0;
	int flag = 1;
	char strpart[20];
	while (t < strlen)
	{
		memset(strpart, 0, 20);
		for (i = 0; i < 20; i++)
		{
			if (str[t] != ' ')
			{
				strpart[i] = str[t];
				t++;
			}
			else
			{
				strpart[i] = '\0';
				t++;
				break;
			}
		}
		strcpy(split[i], strpart);
		n += 1;
	}
	tree str_tree;
	tree result;
	init_tree(str_tree, NULL, NULL, NULL, NULL);
	result = str_tree;
	for (i = 0; i < n; i++)
	{
		string ss(split[i]);
		tree lasttree;
		tree nexttree;
		if (!(strcmp(split[i], "PROJECTION") && strcmp(split[i], "SELECT") && strcmp(split[i], "AVG")))
		{
			str_tree.state.append(ss);
		}
		else if (!(strcmp(split[i], "[") && strcmp(split[i], "]") && strcmp(split[i], ")"))) continue;
		else if (!strcmp(split[i], "("))
		{
			
			str_tree.left = &(init_tree(lasttree, NULL, NULL, NULL, NULL));
			str_tree = *str_tree.left;
		}
		else if (!strcmp(split[i], "JOIN"))
		{
			str_tree.state.append(ss);
			str_tree.left = &(init_tree(lasttree, NULL, NULL, NULL, NULL));
			str_tree.left->content.append(split[i-1]);
			str_tree.right = &(init_tree(nexttree, NULL, NULL, NULL, NULL));
			str_tree.right->content.append(split[i + 1]);
		}
		else
		{
			if (!strcmp(split[i], "JOIN")) continue;
			str_tree.content = str_tree.content + split[i];
		}
	}
	return result;
}
string find(string str)
{
	return str;
}
int out_by_tree(string str)
{
	return 0;
}
