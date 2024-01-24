Q-Link : https://leetcode.com/problems/unique-paths-ii/description/

Approach 1 : Memo

class Solution {
public:

    int helper(vector<vector<int>>& grid,int row,int col, vector<vector<int>>&dp){
        if(row==0 && col==0)return 1;
        if(row<0 || col<0)return 0;

        if(grid[row][col]==1)return 0;

        if(dp[row][col]!=-1)return dp[row][col];

        return dp[row][col]=helper(grid,row,col-1,dp)+helper(grid,row-1,col,dp);
    }    

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1)return 0;
        if(grid[n-1][m-1]==1)return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(grid,n-1,m-1,dp);

    }
};

Approach 2 : Tabulation 

  class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1)return 0;
        if(grid[n-1][m-1]==1)return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));

        vector<int>prev(m,-1);
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[0][0]=1;
                }
                else{
                    int up=0;
                    int left=0;

                    if(grid[i][j]==1){
                        dp[i][j]=0;
                        continue;
                    }

                   if(i>0) up=dp[i-1][j];
                   if(j>0)left=dp[i][j-1];

                    dp[i][j]=up+left;
                }
            }
        }

        return dp[n-1][m-1];

    }
};


Approach 3 : Space Optimization

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1)return 0;
        if(grid[n-1][m-1]==1)return 0;

        vector<int>prev(m,-1);
 
        for(int i=0;i<n;i++){
            vector<int>curr(m,-1);
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    curr[0]=1;
                }
                else{
                    int up=0;
                    int left=0;

                    if(grid[i][j]==1){
                        curr[j]=0;
                        continue;
                    }

                   if(i>0) up=prev[j];
                   if(j>0)left=curr[j-1];

                    curr[j]=up+left;
                }
            }
            prev=curr;
        }

        return prev[m-1];

    }
};
