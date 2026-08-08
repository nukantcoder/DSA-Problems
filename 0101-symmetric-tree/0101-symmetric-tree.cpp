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
//The Main intuition behind the approach since we have to check te symmetry left subtree should be mirror image of right subtree so start with root -> left and root -> right and for compare left -> left with right -> right and left -> right with right -> left Time Complecity:O(N) Auxiliary Space : O(n) worstcase which is stack space
bool isMirror(TreeNode*p,TreeNode*q)
{
    if(p == NULL && q == NULL)
    {
        return true;
    }
    if(p == NULL || q == NULL)//because i have already checked for both NULL so if one of them will be NULL return false
    {
        return false;
    }
    if(p -> val != q -> val)
    {
        return false;
    }
    return isMirror(p -> left,q -> right) && isMirror(p -> right,q -> left);
}
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        return isMirror(root -> left,root -> right);
    }
};