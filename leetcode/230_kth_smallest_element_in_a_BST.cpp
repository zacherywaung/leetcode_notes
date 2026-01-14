// leetcode 230  mid


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
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        int ret = 0;
        dfs(root, count, ret);
        return ret;
    }

    void dfs(TreeNode* root, int& count, int& ret)
    {
        if(root == nullptr)
        {
            return;
        }
        dfs(root->left, count, ret);
        --count;
        if(count == 0)
        {
            ret = root->val;
            return;
        }
        dfs(root->right, count, ret);
    }
};