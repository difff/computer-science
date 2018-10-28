#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) 
    {
    	vector<int> pPreOrder, pInOrder, qPreOrder, qInOrder;

		preOrder(p, pPreOrder);
		preOrder(q, qPreOrder);
		if (!isSameVector(pPreOrder, qPreOrder))
			return false;
		inOrder(p, pInOrder);
		inOrder(q, qInOrder);
		if (!isSameVector(pInOrder, qInOrder))
			return false;
		return true;
    }

    bool isSameVector(vector<int> &a, vector<int> &b) {
    	if (a.size() != b.size())
    		return false;
    	for (int i = 0; i != a.size(); ++i) {
    		if (a[i] != b[i])
    			return false;
    	}
    	return true;
    }

    void preOrder(TreeNode *t, vector<int> &order) 
    {
    	if (t == NULL)
    		return;
    	order.push_back(t->val);
    	preOrder(t->left, order);
    	preOrder(t->right, order);
    }

    void inOrder(TreeNode *t, vector<int> &order)
    {
    	if (t == NULL)
    		return;
    	inOrder(t->left, order);
    	order.push_back(t->val);
    	inOrder(t->right, order);
    }
};

/*
上述解法是有问题的 因为题目没说明每个节点的值都一样
比如{1, 1}和{1, #, 1} (完全二叉树构建)
前序遍历和中序遍历结果都是{1, 1}和{1, 1}
*/

class Solution2 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) 
    {

    }
};









