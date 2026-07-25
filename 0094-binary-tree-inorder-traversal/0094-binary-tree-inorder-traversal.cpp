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
//The main approach behind inorder iterative solution is before printing a node firstly explore its left subtree and when the left subtree is explored our stck which will contain the previous incompleted nodes so process the topmost node pop it and now visit its rightmost subtree then so till current is not null and stack is not empty
//TC:O(N) N is number of nodes AS:O(N) as maximum stck could contain N nodes
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode*current;

        current = root;
        vector<int>ans;
        while(current != NULL || st.size() != 0)
        {
            if(current != NULL)
            {
                st.push(current);
                current = current -> left;
            }
            else
            {
                current = st.top();
                ans.push_back(current -> val);
                st.pop();
                current = current -> right;
            }
        }
        return ans;
    }
};