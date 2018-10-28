#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
主要是无法作标记
*/

class BinaryTree {
public:
	TreeNode* createByCompleteBinaryTreeOrder(vector<int> order, int n, int idx)
	{
	    if (order[idx] == -1 || idx >= n)
	        return NULL;
	    TreeNode *root = new TreeNode(order[idx]);
	    root->left = createByCompleteBinaryTreeOrder(order, n, idx*2+1);
	    root->right = createByCompleteBinaryTreeOrder(order, n, idx*2+2);
	    return root;
	}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > vv;
    	if (root == NULL)
    		return vv;
    	vector<int> v;
    	v.push_back(root->val);
    	vv.push_back(v);
    	v.clear();
    	queue<TreeNode *> q;    	
    	q.push(root);
    	int levelPoppingCount = 0;
    	int poppingLevel = 0;
    	while (!q.empty()) {
    		TreeNode *far = q.front();
    		if (far->left != NULL) {
    			q.push(far->left);
    			v.push_back(far->left->val);
    		}
    		if (far->right != NULL) {
    			q.push(far->right);
    			v.push_back(far->right->val);
    		}
    		q.pop();
    		levelPoppingCount++;
    		if (levelPoppingCount == vv[poppingLevel].size()) {
    			poppingLevel++;
    			if (v.size() == 0)
    				break;
	    		vv.push_back(v);
    			levelPoppingCount = 0;
    			v.clear();
	    	}
	    }
	    return vv;
    }
};

class Solution2 {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > vv;
    	if (root == NULL)
    		return vv;
    	dfs(root, 1, vv);
    	return vv;
    }

    void dfs(TreeNode *root, int level, vector<vector<int> > &vv) {
    	if (root == NULL)
    		return;
    	if (vv.size() < level) {
    		vector<int> *v = new vector<int>;
    		v->push_back(root->val);
    		vv.push_back(*v);
    	} else {
    		vv[level-1].push_back(root->val);
    	}
    	dfs(root->left, level+1, vv);
    	dfs(root->right, level+1, vv);
    }
};


int main(int argc, char const *argv[])
{
	int a[] = {3, 9, 20, -1, 15, 7};
	vector<int> v(a, a+6);
	BinaryTree bt;

	TreeNode *root = bt.createByCompleteBinaryTreeOrder(v, v.size(), 0);
	Solution2 s;
	vector<vector<int> > vv = s.levelOrder(root);

	for (int i = 0; i != vv.size(); ++i) {
		for (int j = 0; j != vv[i].size(); ++j) {
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}