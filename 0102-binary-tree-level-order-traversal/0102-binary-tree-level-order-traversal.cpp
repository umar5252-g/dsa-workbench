/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void levelorder(TreeNode* root, vector<vector<int>>& ans) {

        if(root == NULL) return;
        vector<int> lev;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (q.size() > 0) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                ans.push_back(lev);
                lev.clear();

                if (!q.empty()) {
                    q.push(NULL);
                }
                continue;
            }

            lev.push_back(curr->val);

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<int> q;
        vector<vector<int>> ans;
        levelorder(root, ans);
        return ans;
    }
};