给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //动态规划！先加满上面和下面（因为是固定的），然后向右下，每次看是加左还是加上比较小
        int n= grid[0].size();
        int m= grid.size();
        //cout<<m<<","<<n<<endl;
        for(int i=1;i<n;i++) grid[0][i]=grid[0][i-1]+ grid[0][i];
        for(int i=1;i<m;i++) grid[i][0]=grid[i-1][0]+ grid[i][0];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
              grid[i][j]=min(grid[i-1][j]+grid[i][j],grid[i][j-1]+grid[i][j]) ; 
            }
        }
        return grid[m-1][n-1];
        
    }
};