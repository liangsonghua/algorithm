#include <iostream>
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
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        /*
        1.核心是中序遍历的非递归算法。
        2.修改当前遍历节点与前一遍历节点的指针指向。
        */
        if(pRootOfTree == NULL) return NULL;
        stack<TreeNode* > stack;
        TreeNode* root =NULL;
        TreeNode* pre = NULL;
        while(pRootOfTree || !stack.empty())
        {
           while(pRootOfTree)
           {
               stack.push(pRootOfTree);
               pRootOfTree = pRootOfTree->left;
           }
           if(!stack.empty())
           {
                pRootOfTree = stack.top();
                stack.pop();
                if(root == NULL)
                {
                    root = pRootOfTree;
                    pre = root;
                 
                }
                else
                {
                    pre->right = pRootOfTree;
                    pRootOfTree->left = pre;
                    pre = pRootOfTree;
                }  
                pRootOfTree = pRootOfTree->right;  
           }
        }
       return root;
    }
};