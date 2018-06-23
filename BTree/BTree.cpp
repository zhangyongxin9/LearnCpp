// BTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct BTreeNode
{
	int value;
	BTreeNode* m_left;
	BTreeNode* m_right;
};

BTreeNode* constructCore(int* preStart,int* preEnd,int* midStart,int* midEnd)
{
	BTreeNode* root = new BTreeNode();
	root->value = preStart[0];
	root->m_left = nullptr;
	root->m_right = nullptr;
	if (preStart == preEnd || midStart == midEnd)
		return root;

	int* p = midStart;
	int leftLen = 0;
	while (*p != preStart[0])
	{
		++p;
		++leftLen;
	}
	if (leftLen > 0)
		root->m_left = constructCore(preStart + 1, preStart + leftLen, midStart, p - 1);
	if( leftLen < preEnd-preStart)//--大于等于数组长度表示没有右子树
		root->m_right = constructCore(preStart + leftLen + 1, preEnd, p + 1, midEnd);

	return root;
}

BTreeNode* constructBTree(int* pre, int* mid, int length)
{
	return constructCore(pre,pre+length-1,mid,mid+length-1);
}

void printBTreeAfter(BTreeNode* bTree)
{
	if (bTree == nullptr)
		return;
	printBTreeAfter(bTree->m_left);
	printBTreeAfter(bTree->m_right);
	cout << endl << bTree->value;
}

int main()
{
	//--已知前序+中序-> 输出后序
	int pre[] = {1,2,4,7,3,5,6,8};
	int mid[] = {4,7,2,1,5,3,8,6};

	BTreeNode* bTree = constructBTree(pre, mid, sizeof(pre)/sizeof(pre[0]) );
	printBTreeAfter(bTree);

	getchar();
    return 0;
}

