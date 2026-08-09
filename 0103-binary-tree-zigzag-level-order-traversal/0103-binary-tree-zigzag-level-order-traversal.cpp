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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
            int levelsize = q.size();
            vector<int>current;
            for(int i = 0;i < levelsize;i++)
            {
                TreeNode*node = q.front();
                current.push_back(node -> val);
                q.pop();

                if(node -> left != NULL)
                {
                    q.push(node -> left);
                }
                if(node -> right != NULL)
                {
                    q.push(node -> right);
                }
            }
            if(level % 2 != 0)
            {
                reverse(current.begin(),current.end());
            }
            ans.push_back(current);
            level++;
        }
        return ans;
    }
};