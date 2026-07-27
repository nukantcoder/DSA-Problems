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
    int maxDepth(TreeNode* root) {
        //Using BFS Traversal

        if(root == NULL)
        {
            return 0;
        }
        int depth = 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int levelsize = q.size();
            for(int i = 0;i < levelsize;i++)
            {
                TreeNode*current = q.front();
                q.pop();
                if(current -> left != NULL)
                {
                    q.push(current -> left);
                }
                if(current -> right != NULL)
                {
                    q.push(current -> right);
                }
            }
            depth = depth + 1;
        }
        return depth;
    }
};