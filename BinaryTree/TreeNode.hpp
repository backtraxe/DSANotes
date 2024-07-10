#pragma once

template <typename T>
class TreeNode {
public:
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : val(val), left(left), right(right) {}
};
