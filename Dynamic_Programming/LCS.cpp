Q-Link : https://leetcode.com/problems/longest-common-subsequence/description/


Approach 1 : Memo

class Solution {
public:

    int helper(string &text1, string &text2,int idx1,int idx2, vector<vector<int>>&dp){
        if(idx1<0 || idx2<0)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2])return dp[idx1][idx2]=1 +helper(text1,text2,idx1-1,idx2-1,dp);

        return dp[idx1][idx2]=max(helper(text1,text2,idx1,idx2-1,dp),helper(text1,text2,idx1-1,idx2,dp));
    }    

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        return helper(text1,text2,n-1,m-1,dp);
    }
};


Approach 2 : Tabu

  class Solution {
public:  

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  if(text1[i-1]==text2[j-1]) dp[i][j]=1 +dp[i-1][j-1];

                 else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }

        return dp[n][m];
    }
};


Approach 3 : Space Optimization

class Solution {
public:  

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<int>prev(m+1,0),curr(m+1,0);
        
       
        for(int i=0;i<=m;i++)prev[i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  if(text1[i-1]==text2[j-1]) curr[j]=1 +prev[j-1];

                 else curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }

        return prev[m];
    }
};

