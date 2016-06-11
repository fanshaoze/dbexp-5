#pragma once
#include "stdafx.h"
#include "mathods.h"

// dbexp-5.cpp : 定义控制台应用程序的入口点。

const char key_words[4][20][20] =
{ { "ESSN", "ADDRESS", "SALARY", "SUPERSSN", "ENAME", "DNO" },
{ "DNO", "DNAME", "DNEMBER", "MGRSSN", "MGRSTARTDATE" },
{ "PNAME", "PNO", "PLOCATION", "DNO" },
{ "HOURS", "P.ESSN", "PNO" } };
//struct tree; 
rel split(char str[], char * v)
{
	rel split_result;
	int i = 0;
	char * token = NULL;
	cout << str;
	cout << v;
	cout << endl;
	token = strtok(str, v);
	cout << token << endl;
	while (token != NULL)
	{
		strcpy(split_result.result[i], token);
		cout << split_result.result[i] << endl;
		token = strtok(NULL, " ");
		i += 1;
	}
	split_result.length = i;
	return split_result;
}
tree better(tree tree0)
{
	int n = 0;
	int i = 0;
	int j = 0;
	tree tree_now;
	tree join;
	tree select;
	tree temp;
	tree_now = tree0;
	join = tree0;
	select = tree0;
	rel a;
	rel b;
	char * content = NULL;
	
	string tempstr;

	temp = init_tree("", NULL, NULL, "");
	join = find("JOIN", join);
	select = find("SELECT", select);
	if (compare(tree_now, select)) tree_now = *tree_now.left;
	else tree_now.left = select.left;
	if (select.left->state != "JOIN")  tree_now = *tree_now.left;
	strcpy(content, select.content.c_str());
	a = split(content, "&");
	for (j = 0; j < n; j++)
	{
		b = split(a.result[j], "=");
		tempstr = b.result[0];
		if (join.left->content == tempstr)
		{
			temp = *join.left;
			temp.state = "SELECT";
			temp.content = a.result[j];
			temp.left = &init_tree("", NULL, NULL, "");
			temp.left->content = tempstr;

		}
		if (join.right->content == tempstr)
		{
			temp = *join.right;
			temp.state = "SELECT";
			temp.content = a.result[j];
			temp.left = &init_tree("", NULL, NULL, "");
			temp.left->content = tempstr;
		}
	}
	return tree_now;
}
string search(string s)
{
	cout << s;
	int i;
	int k;
	for (i = 0; i < 4; i++)
	{
		for (k = 0; k < sizeof(key_words[i]); k++)
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
	rel spl;
	int strlen = str.length();
	int t = 0;
	int flag = 1;
	spl = split((char *)str.c_str(), " ");
	tree * str_tree;
	tree * result = new tree;
	str_tree = &init_tree("", NULL, NULL, "");
	result = str_tree;
	for (i = 0; i < spl.length; i++)
	{
		string ss(spl.result[i]);
		//cout << ss;
		if (!(strcmp(spl.result[i], "PROJECTION") && strcmp(spl.result[i], "SELECT") &&
			strcmp(spl.result[i], "AVG")))
		{
			//cout << spl.result[i];
			str_tree->state.append(ss);
		}
		else if (!(strcmp(spl.result[i], "[") && strcmp(spl.result[i], "]") &&
			strcmp(spl.result[i], ")")))
		{
			//cout << spl.result[i];
			continue;
		}
		else if (!strcmp(spl.result[i], "("))
		{
			//cout << spl.result[i] << endl;
			str_tree->left = &(init_tree("", NULL, NULL, ""));
			str_tree = str_tree->left;
		}
		else if (!strcmp(spl.result[i], "JOIN"))
		{
			//cout << spl.result[i] << endl;
			str_tree->state.append(ss);
			str_tree->left = &(init_tree("", NULL, NULL, ""));
			str_tree->left->content.append(spl.result[i - 1]);
			str_tree->right = &(init_tree("", NULL, NULL, ""));
			str_tree->right->content.append(spl.result[i + 1]);
		}
		else
		{
			if (!(strcmp(spl.result[i + 1], "JOIN")&&strcmp(spl.result[i - 1], "JOIN")))
				continue;
			str_tree->content = str_tree->content + spl.result[i];
			//cout << str_tree.content << endl;
		}
	}
	return *result;
}

int out_by_tree(tree * tree0)
{
	int i = 0;
	int t = 1;
	tree * tree1;
	tree1 = tree0;
	tree ** treelist = new tree *;
	while ((tree1 != NULL) || (t != 0))
	{
		while (tree1 != NULL)
		{
			if (tree1->state != "")
				cout << tree1->state << " ";
			//if (tree1->content != "")
				cout << tree1->content << endl;
			treelist[i] = tree1;
			i += 1;
			tree1 = tree1->left;
		}
		//cout << i;
		t = i;
		if (t != 0)
		{
			t -= 1;
			tree1 = treelist[t];
			tree1 = tree1->right;
			treelist[t] = NULL;
			i = t;
		}
	}
	return 0;
}
int ceshi()
{
	char str[] = "ab,cd,ef";
	char *ptr;
	printf("before strtok:  str=%s\n", str);
	printf("begin:\n");
	ptr = strtok(str, ",");
	while (ptr != NULL) {
		printf("str=%s\n", str);
		printf("ptr=%s\n", ptr);
		ptr = strtok(NULL, ",");
	}
	system("pause");
	return 0;
}

