Q-Link : https://leetcode.com/problems/minimum-path-sum/description/

Approach 1 : Memo

class Solution {
public:

    int helper(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&dp){
        if(row==0 && col==0)return grid[row][col];
        if(row<0 || col<0) return 1e8;

        if(dp[row][col]!=-1)return dp[row][col];

        return dp[row][col]= grid[row][col]+min(helper(grid,row,col-1,dp)
                                                ,helper(grid,row-1,col,dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(grid,n-1,m-1,dp);
    }
};

Approach 2 : Tabulation 

  class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[0][0]=grid[0][0];
                    continue;
                }
                else{
                    int up=1e9;
                    int left=1e9;

                    if(i>0)up=grid[i][j]+dp[i-1][j];
                    if(j>0)left=grid[i][j]+dp[i][j-1];

                    dp[i][j]=min(up,left);
                }
            }
        }

        return dp[n-1][m-1];

    }
};

Approach 3 : Space Optimization 

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       
        
        vector<int>prev(m,-1);

        for(int i=0;i<n;i++){

             vector<int>curr(m,-1);
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    curr[0]=grid[0][0];
                    continue;
                }
                else{
                    int up=1e9;
                    int left=1e9;

                    if(i>0)up=grid[i][j]+prev[j];
                    if(j>0)left=grid[i][j]+curr[j-1];

                    curr[j]=min(up,left);
                }
            }
            prev=curr;
        }

        return prev[m-1];

    }
};
