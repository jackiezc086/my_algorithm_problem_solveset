//参考官方题解完成的，对于vector的相关函数还不够熟悉，需要查询官方文档
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){return nullptr;}
        if(nums.size() == 1){return new TreeNode(nums[0]);}

        auto it = max_element(nums.begin(), nums.end());
		vector<int> l(nums.begin(), it);
		vector<int> r(it + 1, nums.end());

        TreeNode* root = new TreeNode(*it);
        TreeNode* left = constructMaximumBinaryTree(l);
        TreeNode* right = constructMaximumBinaryTree(r);
        root -> left = left;
        root -> right = right;

        return root;
    }
};
