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
//The main approach behind the optimized solution is in brute force approach approach we were calculating the height again and again for a node so it was taking O(N^2) time now instead of separately calculating balnced and height when we will have a nodes left subtree height and right subtree height will will calculate itself and if   if(abs(left - right) > 1) return - 1 which will indicate this node is balanced and will return -1 to upward unfinished call and left == -1 and right == -1 will make sure early termination indicating an unbalanced subtree. Time Complexity:O(N) Auxilary Space:O(N) in worst case stack space 
int checkheight(TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = checkheight(root -> left);
    if(left == -1)
    {
        return -1;
    }
    int right = checkheight(root -> right);
    if(right == -1)
    {
        return -1;
    }

    if(abs(left - right) > 1)
    {
        return -1;
    }
    return 1 + max(left,right);
}
    bool isBalanced(TreeNode* root) {
        
        int val = checkheight(root);
        if(val != -1)
        {
            return true;
        }
        return false;
    }
};