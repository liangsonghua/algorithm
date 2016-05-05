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

class CheckBalance {
public:
    int getTreeHight(TreeNode* p)
    {
        if(p==NULL) return 0;
        int l = getTreeHight(p->left), r = getTreeHight(p->right);
        return (l>r?l:r)+1;
    }
    bool check(TreeNode* root) {
        if(root==NULL)return true;
        if(abs(getTreeHight(root->left)-getTreeHight(root->right))>1)return false;
        if(!check(root->left)||!check(root->right)) return false;
        return true;
    }
};