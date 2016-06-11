#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <string>
#include "treemathod.h"
using namespace std;

// dbexp-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
typedef struct rel
{
	int length;
	char result[100][20];
}rel;
int ceshi();
rel split(char str[], char * v);
tree better(tree tree0);
string search(string s);
tree trans_to_tree(string str);
int out_by_tree(tree * tree0);
