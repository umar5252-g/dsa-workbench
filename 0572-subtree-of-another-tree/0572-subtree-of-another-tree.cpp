/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool identical(TreeNode* p, TreeNode*  q){
        if(p == NULL || q ==NULL){
            return p==q;
        }

        return identical(p->left, q->left) && identical(p->right, q->right) 
        && p->val == q->val;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot== NULL)return root==subRoot;
        
        if(root->val == subRoot->val && identical(root, subRoot)){
           return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
        
    }
};