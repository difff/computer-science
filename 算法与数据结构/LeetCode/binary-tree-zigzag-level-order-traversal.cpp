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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
            if (level%2 == 0)
                v->insert(v->begin(), root->val);
            else
                v->push_back(root->val);
            vv.push_back(*v);
        } else {
            if (level%2 == 0)
                vv[level-1].insert(vv[level-1].begin(), root->val);
            else
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
    Solution s;
    vector<vector<int> > vv = s.levelOrder(root);

    for (int i = 0; i != vv.size(); ++i) {
        for (int j = 0; j != vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}