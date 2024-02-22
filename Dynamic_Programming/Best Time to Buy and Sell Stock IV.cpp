Q-Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
int helper(vector<int>&prices,int idx,int n,int buy,int cap,vector<vector<vector<int>>>&dp){
        if(n==idx||cap==0)return 0;
  
        if(dp[idx][buy][cap]!=-1)return dp[idx][buy][cap];
  
        int profit=0;
  
        if(buy)profit=max(-1*prices[idx]+helper(prices,idx+1,n,0,cap,dp),helper(prices,idx+1,n,1,cap,dp));
        else profit=max(prices[idx]+helper(prices,idx+1,n,1,cap-1,dp),helper(prices,idx+1,n,0,cap,dp));

        return dp[idx][buy][cap]=profit;

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
      
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
      
        return helper(prices,0,n,1,k,dp);
    }
};
