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
//Brute Force Approach - for every node were calculating its throughroot path, its leftpath and its rightpath now i understood this approach   int leftdiameter = diameter(root -> left);
   //     int rightdiameter = diameter(root -> right); why these are written as they were gib=ving the longest diameter from left and right respeactively Time complexity:O(n) for every node * O(n) for every node we are going till leaf so all the way down O(n^2)
int height(TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = height(root -> left);
    int right = height(root -> right);
    return 1 + max(left,right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int leftheight = height(root -> left);// since these both are being calculated again and again these must be optimized 
        int rightheight = height(root -> right);//
        int troot = leftheight + rightheight;
        int leftdiameter = diameterOfBinaryTree(root -> left);
        int rightdiameter = diameterOfBinaryTree(root -> right);
        return max(troot,max(leftdiameter,rightdiameter));
    }
};