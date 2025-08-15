/*
98. 验证二叉搜索树

给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。


示例 1：


输入：root = [2,1,3]
输出：true
示例 2：


输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。


提示：

树中节点数目范围在[1, 104] 内
-231 <= Node.val <= 231 - 1
*/

#include <vector>
#include "tree.h"

class Solution98 {
   public:
    bool isValidBSTError(TreeNode* root) {
        // 1. root 节点 val 大于左子树; val 小于右子树
        if (root == nullptr) {
            return true;
        }
        if ((root->left != nullptr && root->val <= root->left->val) ||
            (root->right != nullptr && root->val >= root->right->val)) {
            return false;
        }

        // 2. 检查左子树和右子树
        return isValidBSTError(root->left) && isValidBSTError(root->right);
    }

    // 中序遍历是升序
    bool isValidBST(TreeNode* root) {
        std::vector<int> result;
        inorderTraversal(root, result);

        // check 是否为升序

        if (result.size() < 2) {
            return true;
        }
        int pre = result[0];
        for (int idx = 1; idx < result.size(); idx++) {
            if (result[idx] <= pre) {
                return false;
            }
            pre = result[idx];
        }

        return true;
    }

    void inorderTraversal(TreeNode* root, std::vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
};