Q-Link ; https://leetcode.com/problems/count-sorted-vowel-strings/description/

Approach 1 : Recursion : 

class Solution {
public:

    int helper(int idx,int n){
        if(n==0)return 1;
        if(idx>=5)return 0;

        int pick=helper(idx,n-1);
        int nonpick=helper(idx+1,n);

        return pick+nonpick;
        
    }

    int countVowelStrings(int n) {
       
        
        return helper(0,n);
    }
};

Approach 2 : Memo

  class Solution {
public:

    int helper(int idx,int n, vector<vector<int>>&dp){
        if(n==0)return 1;
        if(idx>=5)return 0;
        if(dp[idx][n]!=-1)return dp[idx][n];
        int pick=helper(idx,n-1,dp);
        int nonpick=helper(idx+1,n,dp);

        return dp[idx][n]=pick+nonpick;
        
    }

    int countVowelStrings(int n) {
       
       vector<vector<int>>dp(5,vector<int>(n+1,-1));
        
        return helper(0,n,dp);
    }
};

Approach 3 : Tabulation 

  class Solution {
public:

   

    int countVowelStrings(int n) {
       
       vector<vector<int>>dp(5,vector<int>(n+1,0));

       for(int idx=0;idx<5;idx++)dp[idx][0]=1;

       for(int i=4;i>=0;i--){
           for(int j=1;j<=n;j++){
                int pick=dp[i][j-1];
                int nonpick=0;
                if(i<4)nonpick=dp[i+1][j];
                 dp[i][j]=pick+nonpick;
           }
       }
        
        return dp[0][n];
    }
};

Approach 4 : Space Optimization

class Solution {
public:
    int countVowelStrings(int n) {
       
       vector<int>dp(5,1);

       while(--n){
           for(int i=3;i>=0;i--){
               dp[i]+=dp[i+1];
           }
       }
       int sum=0;

       for(auto& x : dp)sum+=x;
        
        return sum;
    }
};

Approach 5 : O(1) Space

class Solution {
public:
    int countVowelStrings(int n) {
       
       int a=1,e=1,i=1,o=1,u=1;

       while(--n){
           o+=u;
           i+=o;
           e+=i;
           a+=e;
       }
        
        return a+e+i+o+u;
    }
};
