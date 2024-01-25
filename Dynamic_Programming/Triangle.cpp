Q-Link : https://leetcode.com/problems/triangle/description/

Approach 1 : recursion

class Solution {
public:

    int helper(vector<vector<int>>&triangle,int row,int col,int n){
        if(row==n-1)return triangle[row][col];

        int down=triangle[row][col]+helper(triangle,row+1,col,n);
        int right=triangle[row][col]+helper(triangle,row+1,col+1,n);

        return min(down,right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        int idx=0;
        return helper(triangle,idx,idx,n);
    }
};

Approach 2 : Memo

  class Solution {
public:

    int helper(vector<vector<int>>&triangle,int row,int col,int n, vector<vector<int>>&dp){
        if(row==n-1)return triangle[row][col];

        if(dp[row][col]!=-1)return dp[row][col];

        int down=triangle[row][col]+helper(triangle,row+1,col,n,dp);
        int right=triangle[row][col]+helper(triangle,row+1,col+1,n,dp);

        return dp[row][col]=min(down,right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int idx=0;
        return helper(triangle,idx,idx,n,dp);
    }
};

Approach 3 : Tabulation

  class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++)dp[n-1][i]=triangle[n-1][i];

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int right=triangle[i][j]+dp[i+1][j+1];

                dp[i][j]=min(down,right);
            }
        }    
        
        return dp[0][0];
    }
};

Approach 4 : Space Optimization

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();

        vector<int>front(n,-1);

        for(int i=0;i<n;i++)front[i]=triangle[n-1][i];

        for(int i=n-2;i>=0;i--){
              vector<int>curr(n,-1);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+front[j];
                int right=triangle[i][j]+front[j+1];

               curr[j]=min(down,right);
            }
            front=curr;
        }    
        
        return front[0];
    }
};
