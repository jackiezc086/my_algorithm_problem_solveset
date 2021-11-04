//用bfs或者dfs遍历整个二叉树，用全局数组来存储每个节点的父亲节点和深度
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
    int d[105], fa[105];

    void dfs(TreeNode* root){
        if(root -> left){
            d[root -> left -> val] = d[root -> val] + 1;
            fa[root -> left -> val] = root -> val;
            dfs(root -> left);
        }
        if(root -> right){
            d[root -> right -> val] = d[root -> val] + 1;
            fa[root -> right -> val] = root -> val;
            dfs(root -> right);
        }
        return;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        d[root -> val] = 0;
        fa[root -> val] = 0;
        dfs(root);

        return d[x] == d[y] && fa[x] != fa[y];
    }
};

