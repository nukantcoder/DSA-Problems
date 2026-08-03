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
int diameter = 0;
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = height(root -> left);
        int right = height(root -> right);
        int throughroot = left + right;

        diameter = max(diameter,throughroot);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
     //The main approach behind optimal solution is instead of finding height again and again for several nodes just compute the leftheight and rightheight of a node and leftheight + rightheight update diameter and return height TC:O(N) AS:O(N) recursion stack space worst case 
     int val = height(root);
     return diameter;
    }
};