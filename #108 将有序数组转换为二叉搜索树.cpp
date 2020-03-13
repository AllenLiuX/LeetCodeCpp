Tags: 二叉树, 递归, 构造, 简单
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> Num;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        Num = nums;
        return helper(0, nums.size()-1);
    }
    
    TreeNode* helper(int lo, int hi){
        if(lo>hi)
            return nullptr;
        int mid = lo + (hi-lo)/2;
        TreeNode* t = new TreeNode(Num[mid]);
        t->left = helper(lo, mid-1);
        t->right = helper(mid+1, hi);
        return t;
    }
};