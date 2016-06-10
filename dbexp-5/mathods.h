#pragma once
#include "stdafx.h"
#include "treemathod.h"

// dbexp-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

const char key_words[4][20][20] =
{ { "ESSN", "ADDRESS", "SALARY", "SUPERSSN", "ENAME", "DNO" },
{ "DNO", "DNAME", "DNEMBER", "MGRSSN", "MGRSTARTDATE" },
{ "PNAME", "PNO", "PLOCATION", "DNO" },
{ "HOURS", "P.ESSN", "PNO" } };
//struct tree; 

tree better(tree tree0)
{
	int i = 0;
	int j = 0;
	int k = 0;
	tree tree_now;
	tree join;
	tree select;
	tree temp;
	tree_now = tree0;
	join = tree0;
	select = tree0;
	char ** a;
	char * content;
	char * token;
	char ** b;
	string tempstr;

	temp = init_tree(temp, NULL, NULL, NULL, NULL);
	join = find("JOIN", join);
	select = find("SELECT", select);
	if (compare(tree_now, select)) tree_now = *tree_now.left;
	else tree_now.left = select.left;
	if (select.left->state != "JOIN")  tree_now = *tree_now.left;
	strcpy(content, select.content.c_str());
	token = strtok(content, "&");
	while (token != NULL)
	{
		a[i] = token;
		token = strtok(NULL, " ");
		i += 1;
	}
	for (j = 0; j < i; j++)
	{
		token = strtok(a[j], "=");
		while (token != NULL)
		{
			b[k] = token;
			token = strtok(NULL, " ");
			k += 1;
		}
		tempstr = b[0];
		if (join.left->content == tempstr)
		{
			temp = *join.left;
			temp.state = "SELECT";
			temp.content = a[j];
			temp.left = &init_tree(*temp.left, NULL, NULL, NULL, NULL);
			temp.left->content = tempstr;

		}
		if (join.right->content == tempstr)
		{
			temp = *join.right;
			temp.state = "SELECT";
			temp.content = a[j];
			temp.left = &init_tree(*temp.left, NULL, NULL, NULL, NULL);
			temp.left->content = tempstr;
		}
	}
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
			str_tree.left->content.append(split[i - 1]);
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

int out_by_tree(tree tree0)
{
	int i = 0;
	int t = 0;
	tree * tree1;
	tree1 = &tree0;
	tree **treelist = NULL;
	while ((tree1 != NULL) || (treelist != NULL))
	{
		while (tree1 != NULL)
		{
			if (tree1->state != "")
				cout << tree1->state << " " << endl;
			if (tree1->content != "")
				cout << tree1->content;
			treelist[i] = tree1;
			i += 0;
			tree1 = tree1->left;
		}
		t = sizeof(tree1) / sizeof(tree);
		if (t != 0)
		{
			treelist[t - 1] = NULL;
			tree1 = treelist[t - 1];
			tree1 = tree1->right;
		}
	}
	return 0;
}


