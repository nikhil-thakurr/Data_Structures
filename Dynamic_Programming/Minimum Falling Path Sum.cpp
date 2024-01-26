Q-Link : https://leetcode.com/problems/minimum-falling-path-sum/description/

Approach 1: Memo

class Solution {
public:

    int helper(vector<vector<int>>& matrix,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i<0||j<0 || j>=m || i>=n)return 1e9;
        if(i==n-1)return matrix[i][j];

        
        if(dp[i][j]!=-1)return dp[i][j];
        // cout<<"Hey"<<" ";

        int down=matrix[i][j]+helper(matrix,i+1,j,n,m,dp);
        int right=matrix[i][j]+helper(matrix,i+1,j+1,n,m,dp);
        int left=matrix[i][j]+helper(matrix,i+1,j-1,n,m,dp);

        return dp[i][j]=min(down,min(right,left));
        
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int maxi=INT_MAX;
        int row=0;
        for(int i=0;i<m;i++){
            maxi=min(maxi,helper(matrix,row,i,n,m,dp));
        }

        return maxi;
    }
};

Approach 2 : Tabulation 

  class Solution {
public:

    int helper(vector<vector<int>>& matrix,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i<0||j<0 || j>=m || i>=n)return 1e9;
        if(i==n-1)return matrix[i][j];

        
        if(dp[i][j]!=-1)return dp[i][j];
        // cout<<"Hey"<<" ";

        int down=matrix[i][j]+helper(matrix,i+1,j,n,m,dp);
        int right=matrix[i][j]+helper(matrix,i+1,j+1,n,m,dp);
        int left=matrix[i][j]+helper(matrix,i+1,j-1,n,m,dp);

        return dp[i][j]=min(down,min(right,left));
        
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
           dp[n-1][i]=matrix[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){

                 int left=1e9,right=1e9,down=1e9;   

                  down=matrix[i][j]+dp[i+1][j];
                  if( j<m-1) right=matrix[i][j]+dp[i+1][j+1];
                  if(j>0) left=matrix[i][j]+dp[i+1][j-1];

                   dp[i][j]=min(down,min(right,left));
            }
        }
        int maxi=dp[0][0];

        for(int i=0;i<m;i++)maxi=min(maxi,dp[0][i]);

        return maxi;
    }
};

Approach 3 : Space Optimization 

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(m,-1);
        for(int i=0;i<m;i++){
           prev[i]=matrix[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
             vector<int>curr(m,-1);
            for(int j=m-1;j>=0;j--){

                 int left=1e9,right=1e9,down=1e9;   

                  down=matrix[i][j]+prev[j];
                  if( j<m-1) right=matrix[i][j]+prev[j+1];
                  if(j>0) left=matrix[i][j]+prev[j-1];

                   curr[j]=min(down,min(right,left));
            }
            prev=curr;
        }
        int maxi=prev[0];

        for(int i=0;i<m;i++)maxi=min(maxi,prev[i]);

        return maxi;
    }
};
