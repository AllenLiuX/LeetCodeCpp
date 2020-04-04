# Tags: 中等, python, 递归, 深度遍历
# 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
#
# 示例:
#
# 输入: [1,2,3,null,5,null,4]
# 输出: [1, 3, 4]
# 解释:
#
#    1            <---
#  /   \
# 2     3         <---
#  \     \
#   5     4       <---
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# ---
#
# # Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = []
        def dfs(cur, depth):
            if cur==None:
                return
            if depth > len(res):
                res.append(cur.val)
            dfs(cur.right, depth+1)
            dfs(cur.left,  depth+1)
        dfs(root, 1)
        return res
    
 