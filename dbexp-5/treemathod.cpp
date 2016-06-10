#pragma once
#include "stdafx.h"
#include "treemathod.h"
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
int compare(tree tree1, tree tree2)
{
	if (tree1.content == tree2.content && tree1.left == tree2.left &&
		tree1.right == tree2.right&& tree1.state == tree2.state)
		return 1;
	else return 0;
}
tree find(string str, tree tree0)
{
	while (tree0.state == str)
		tree0 = *tree0.left;
	return tree0;
}
