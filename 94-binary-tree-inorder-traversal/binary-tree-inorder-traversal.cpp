
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        // Visit Left subtree
        inorder(root->left, ans);

        // Visit Root
        ans.push_back(root->val);

        // Visit Right subtree
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
