/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void printInorder(TreeNode* node, int& total_sum) {
        if (node == NULL)
            return;

        printInorder(node->left, total_sum);

        total_sum += node->val;

        printInorder(node->right, total_sum);
    }

private:
    int max_sub_tree(TreeNode* node, long long & max_idx, int& total_sum) {
        if (node == NULL)
            return 0;

        int leftSum = max_sub_tree(node->left, max_idx, total_sum);
        int rightSum = max_sub_tree(node->right, max_idx, total_sum);
        int currentSum = leftSum + rightSum + node->val;
        max_idx = max((long long)(total_sum - currentSum) * currentSum, max_idx);
        return currentSum;
    }

public:
    int maxProduct(TreeNode* root) {
        int total_sum = 0;
        long long max_idx = LLONG_MIN;
        printInorder(root, total_sum);
        max_sub_tree(root, max_idx, total_sum);
        return max_idx % ((int)1e9 + 7);
    }
};