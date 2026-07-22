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
//The main approach is since level by level traversal is also called BFS so since BFS includes data queue because want the node which is first in to be out first as well at each level number of nodes depened on the current size of queue.
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            vector<int>current;
            int levelsize = q.size();

            for(int i = 0;i < levelsize;i++)
            {
                TreeNode*node = q.front();
                current.push_back(node -> val);

                q.pop();

                if(node -> left != NULL)
                {
                    q.push(node->left);
                }
                if(node -> right != NULL)
                {
                    q.push(node -> right);
                }
            }
            ans.push_back(current);
        }
        return ans;
    }
};