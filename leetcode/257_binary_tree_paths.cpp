// leetcode 257

#include<string>
#include<vector>
using namespace std;
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string path;
        dfs(root, ret, path);
        return ret;
    }

    void dfs(TreeNode* root, vector<string>& ret, string path)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            path += to_string(root->val);
            ret.push_back(path);
            return;
        }
        path += to_string(root->val);
        path += "->";
        dfs(root->left, ret, path);
        dfs(root->right, ret, path);
    }
};