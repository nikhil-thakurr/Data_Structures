Q-Link : https://leetcode.com/problems/distinct-subsequences/description/

Approach 1 : Recursion 

class Solution {
public:

    int helper(string& s,string& t,int n,int m ,int i,int j){
        if(j<0)return 1;
        if(i<0)return 0;

        if(s[i]==t[j])return helper(s,t,n,m,i-1,j-1)+helper(s,t,n,m,i-1,j);
        return helper(s,t,n,m,i-1,j);
    }

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();

        return helper(s,t,n,m,n-1,m-1);
    }
};

Approach 2 : Memo

  class Solution {
public:

    int helper(string& s,string& t,int n,int m ,int i,int j,vector<vector<int>>&dp){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])return dp[i][j]= helper(s,t,n,m,i-1,j-1,dp)+helper(s,t,n,m,i-1,j,dp);
        return dp[i][j]=helper(s,t,n,m,i-1,j,dp);
    }

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return helper(s,t,n,m,n-1,m-1,dp);
    }
};

Approach 3 : Tabu

  class Solution {
public:

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();

        vector<vector<double>>dp(n+1,vector<double>(m+1,-1));

        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=m;i++)dp[0][i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
                 else dp[i][j]=dp[i-1][j];
            }
        }

        return (int)dp[n][m];
    }
};

Approach 4 : Space Optimization 2D ARRAY

class Solution {
public:

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double>prev(m+1),curr(m+1);

        prev[0]=curr[0]=1;
        

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]= prev[j-1]+prev[j];
                 else curr[j]=prev[j];
            }
            prev=curr;
        }

        return (int)prev[m];
    }
};

Approach 5 : Space Optimization 1D ARRAY

class Solution {
public:

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double>curr(m+1);

        curr[0]=1;
        

        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]) curr[j]= curr[j-1]+curr[j];
            }
        }

        return (int)curr[m];
    }
};
