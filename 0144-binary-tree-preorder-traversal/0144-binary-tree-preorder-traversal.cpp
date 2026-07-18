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
void preorder(TreeNode* root,vector<int>& ans)
{
    if(root -> left == NULL && root -> right == NULL)
    {
        ans.push_back(root -> val);
        return;
    }
    ans.push_back(root -> val);
    if(root -> left != NULL)
    {
        preorder(root -> left,ans);
    }
    if(root -> right != NULL)
    {
        preorder(root -> right,ans);
    }
    return;
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == 0)
        {
            return {};
        }
        preorder(root,ans);
        return ans;
    }
};