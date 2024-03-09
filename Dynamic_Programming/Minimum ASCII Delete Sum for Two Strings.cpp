Q-Link : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

Approach : MEMOIZATION

  class Solution {
public:

    int helper(string& s1,string &s2,int n,int m,  vector<vector<int>>&dp){

        if(n>=s1.length()){
            int val=0;
            while(m<s2.length()){
                val+=s2[m++];
            }
            return val;
        }

        if(m>=s2.length()){
            int val=0;
            while(n<s1.length()){
                val+=s1[n++];
            }
            return val;
        }

        if(dp[n][m]!=-1)return dp[n][m];

        int ans=0;

        if(s1[n]==s2[m]){
            ans=helper(s1,s2,n+1,m+1,dp);
        }
        else{
            ans=min(s2[m]+helper(s1,s2,n,m+1,dp),s1[n]+helper(s1,s2,n+1,m,dp));
        }

        return dp[n][m]=ans;

    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return helper(s1,s2,0,0,dp);
    }
};
