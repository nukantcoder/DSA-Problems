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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL)
        {
            return {};
        }
        TreeNode*current = root;
        TreeNode*lastvisited = NULL;
        TreeNode*top; 
        stack<TreeNode*>st;

        while(current != NULL || !st.empty())
        {
            if(current != NULL)
            {
                st.push(current);
                current = current -> left;
            }
            else
            {
                top = st.top();
                if(top -> right != NULL)//right child exists
                {
                    if(top -> right == lastvisited)//right node already visited
                    {
                        ans.push_back(top -> val);
                        lastvisited = top;
                        st.pop();
                    }
                    else
                    {
                        current = top -> right;
                    }
                }
                else//right child does not exist
                {
                      ans.push_back(top -> val);
                      lastvisited = top;
                      st.pop();
                }
            }
        }
        return ans;
    }
};