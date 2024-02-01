Q-Link : https://leetcode.com/problems/coin-change/description/

Approach 1 : Recursion 

class Solution {
public:

    int helper(vector<int>& coins, int amount,int idx){
        if(amount==0)return 0;
        if(idx==0){
            
            if(amount%coins[0]==0)return amount/coins[0];

            else return 1e9;
        }
        int nonTake=helper(coins,amount,idx-1);
        int take=1e9;
        if(coins[idx]<=amount)take=1+helper(coins,amount-coins[idx],idx);

        return min(nonTake,take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(begin(coins),end(coins));
        int val= helper(coins,amount,n-1);

        return (val>=1e9)?-1:val;
    }
};

Approach 2 : Memo

  class Solution {
public:

    int helper(vector<int>& coins, int amount,int idx,  vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(idx==0){
            
            if(amount%coins[0]==0)return amount/coins[0];

            else return 1e9;
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        int nonTake=helper(coins,amount,idx-1,dp);
        int take=1e9;
        if(coins[idx]<=amount)take=1+helper(coins,amount-coins[idx],idx,dp);

        return dp[idx][amount]= min(nonTake,take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int val= helper(coins,amount,n-1,dp);

        return (val>=1e9)?-1:val;
    }
};

Approach 3 : Tabulation

  class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        // for(int i=0;i<n;i++)dp[i][0]=0;
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
        int nonTake=dp[i-1][j];
        int take=1e9;
        if(coins[i]<=j)take=1+dp[i][j-coins[i]];

       dp[i][j]= min(nonTake,take);
            }
        }

        int ans =dp[n-1][amount];
        if(ans>=1e9)return -1;
        return ans;
    }
};

Approach 4 : Space Optimization 

class Solution {
public:

    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
       
        vector<int>prev(target+1,0),curr(target+1,0);
        // for(int i=0;i<n;i++)dp[i][0]=0;
        for(int i=0;i<=target;i++){
            if(i%coins[0]==0)prev[i]=i/coins[0];
            else prev[i]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
        int nonTake=prev[j];
        int take=1e9;
        if(coins[i]<=j)take=1+curr[j-coins[i]];

       curr[j]= min(nonTake,take);
            }
            prev=curr;
        }

        int ans =prev[target];
        if(ans>=1e9)return -1;
        return ans;
    }
};
