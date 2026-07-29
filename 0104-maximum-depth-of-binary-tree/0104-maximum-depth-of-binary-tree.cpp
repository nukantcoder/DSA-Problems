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
//the main approach or the intuition is since for every node height depends on the height of its leftsubtree and rightsubtree respectively so for every node it os doing same thing so applying recusion is ideal and base case when current node is null it indicates no node exists so height will be 0. TC:O(N) AS:O(N) Stack Space atmax can have all the N nodes
     int maxDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int leftheight = maxDepth(root -> left);
        int rightheight = maxDepth(root -> right);

        return max(leftheight,rightheight) + 1;
    }
};