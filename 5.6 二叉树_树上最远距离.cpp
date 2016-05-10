#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class LongestDistance {
public:
    int depth(TreeNode* root,int &dep)
    {
        if(root==NULL) return 0;
        int left = depth(root->left,dep);
        int right = depth(root->right,dep);
        dep = dep > (left+right+1)?dep:(left+right+1);
        return left>right?(left+1):(right+1);
        
    }
    int findLongest(TreeNode* root) {
        /*
        情况A: 路径经过左子树的最深节点，通过根节点，再到右子树的最深节点。
        情况B: 路径不穿过根节点，而是左子树或右子树的最大距离路径，取其大者。
        */
        int dep = 0;
        depth(root,dep);
        return dep;
    }
};