Q-Link : https://leetcode.com/problems/unique-paths/description/

Approach 1 : Memo

class Solution {
public:

    int helper(int m,int n, vector<vector<int>>&dp){
        if(m==0 && n==0)return 1;
        if(m<0 || n<0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        int up=helper(m-1,n,dp);
        int left=helper(m,n-1,dp);

        return dp[m][n]=up+left;
    }

    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return helper(m-1,n-1,dp);

    }
};

Approach 2 : Tabulation

  class Solution {
public:

    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j]=1;
                else{
                    int up=0;
                    int left=0;

                    if(i>0)up=dp[i-1][j];
                    if(j>0)left=dp[i][j-1];

                    dp[i][j]=up+left;
                }
            }
        }

        return dp[m-1][n-1];

    }
};

Approach 3 : Space Optimisation

class Solution {
public:

    int uniquePaths(int m, int n) {
        
        vector<int>prev(n,0);

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0)curr[j]=1;
                else{
                    int up=0;
                    int left=0;

                    if(i>0)up=prev[j];
                    if(j>0)left=curr[j-1];

                    curr[j]=up+left;
                }
            }
            prev=curr;
        }

        return prev[n-1];

    }
};
