#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
         vector<vector<int>> allTreeValues;
        vector<int> treeValues;
        vector<TreeNode*> treeNodes;
        if (!root) return allTreeValues;
		//last表示当前行的最右，nLast表示下一行的最右
        TreeNode *last=root;
        TreeNode *nlast=root;
        treeNodes.push_back(root);
        while(!treeNodes.empty())
        {
            TreeNode *temp=treeNodes[0];
            treeValues.push_back(temp->val);
            if(temp->left)
            {
               nlast=temp->left;
               treeNodes.push_back(temp->left);
            }
             if(temp->right)
            {
               nlast=temp->right;
               treeNodes.push_back(temp->right);
            }
            if(temp==last)
            {
                last=nlast;
                allTreeValues.push_back(treeValues);
                treeValues.clear();
            }
            vector<TreeNode*>::iterator it=treeNodes.begin();
            treeNodes.erase(it);
        }
       return allTreeValues;
    }
};