Q-Link : https://leetcode.com/problems/coin-change-ii/description/

Approach 1 : Recursion

class Solution {
public:

    int helper(int amount, vector<int>& coins,int idx){
       
        if(idx==0)return (amount%coins[0]==0);
  

        int nontake=helper(amount,coins,idx-1);
        int take=0;
        if(coins[idx]<=amount)take=helper(amount-coins[idx],coins,idx);

        return take+nontake;
    }

    int change(int amount, vector<int>& coins) {
        
        return helper(amount,coins,coins.size()-1);
    }
};

Approach 2 : Memo

  class Solution {
public:

    int helper(int amount, vector<int>& coins,int idx,vector<vector<int>>&dp){
       
        if(idx==0)return (amount%coins[0]==0);
        
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        int nontake=helper(amount,coins,idx-1,dp);
        int take=0;
        if(coins[idx]<=amount)take=helper(amount-coins[idx],coins,idx,dp);

        return dp[idx][amount]=take+nontake;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return helper(amount,coins,coins.size()-1,dp);
    }
};

Approach 3 : Tabulation
  class Solution {
public:

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        for(int i=0;i<=amount;i++)dp[0][i]=(i%coins[0]==0);
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                 int nontake=dp[i-1][j];
                int take=0;
                if(coins[i]<=j)take=dp[i][j-coins[i]];

                 dp[i][j]=take+nontake;
            }
        } 
       return dp[coins.size()-1][amount];
    }
};


Approach 4 : Space Optimization

class Solution {
public:

    int change(int amount, vector<int>& coins) {
        
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++)prev[i]=(i%coins[0]==0);
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                 int nontake=prev[j];
                int take=0;
                if(coins[i]<=j)take=curr[j-coins[i]];

                 curr[j]=take+nontake;
            }
            prev=curr;
        } 
       return prev[amount];
    }
};
