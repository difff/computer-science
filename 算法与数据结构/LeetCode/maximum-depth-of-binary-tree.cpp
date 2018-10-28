#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <queue>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int maxDepth(TreeNode *root) {
    	if (root == NULL)
    		return 0;
     	if (root->left == NULL && root->right == NULL)
     		return 1;
     	else
     		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    static int max(int a, int b) {
    	return a > b ? a : b;
    }
};

int main(int argc, char const *argv[])
{

	return 0;
}