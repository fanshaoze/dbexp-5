#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <string>
#include "treemathod.h"
using namespace std;
struct tree;
typedef struct tree
{
	string state;
	tree* left;
	tree* right;
	string content;
}tree;
tree init_tree(string state, tree* left, tree* right, string content);
int compare(tree tree1, tree tree2);
tree find(string str, tree tree0);
