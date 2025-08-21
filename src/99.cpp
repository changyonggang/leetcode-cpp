#include <vector>
#include "tree/tree.h"

using namespace std;

/*
! 99. 恢复二叉搜索树
中等
相关标签
premium lock icon
相关企业
给你二叉搜索树的根节点 root ，该树中的 恰好
两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。
*/

// 中序遍历二叉树,找到乱序的两个数据,再找到两个Node修改数值
class Solution99 {
   private:
    vector<int> datas;
    pair<TreeNode*, TreeNode*> nodes;

   public:
    void recoverTree(TreeNode* root) {
        middle_sort(root);
        auto two_datas = find_two_data();
        find_nodes(two_datas.first, two_datas.second, root);

        nodes.first->val = two_datas.second;
        nodes.second->val = two_datas.first;
    }

    void middle_sort(TreeNode* root) {
        if (!root) {
            return;
        }
        middle_sort(root->left);
        datas.push_back(root->val);
        middle_sort(root->right);
    }

    pair<int, int> find_two_data() {
        int len = datas.size();
        int pre = datas.at(0);

        int first_idx = -1, second_idx = -1;
        bool first_found = false, second_found = false;
        for (int idx = 1; idx < len; idx++) {
            if (!first_found && datas.at(idx) < pre) {
                first_idx = idx - 1;
                first_found = true;
            } else if (datas.at(idx) < pre) {
                second_idx = idx;
                second_found = true;
                break;
            }
            pre = datas.at(idx);
        }
        if (!second_found) {
            second_idx = first_idx + 1;
        }

        return {datas.at(first_idx), datas.at(second_idx)};
    }

    void find_nodes(int first, int second, TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->val == first) {
            nodes.first = root;
        } else if (root->val == second) {
            nodes.second = root;
        }
        find_nodes(first, second, root->left);
        find_nodes(first, second, root->right);
    }
};