// leetcode 2331   easy


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }

    bool dfs(TreeNode* root)
    {
        
        if(root->val == 0 ||root->val == 1)
        {
            return root->val;
        }
        bool answerleft = dfs(root->left);
        bool answerright = dfs(root->right);
        if(root->val == 2)
        {
            return answerleft || answerright;
        }

        return answerleft && answerright;
    }
};