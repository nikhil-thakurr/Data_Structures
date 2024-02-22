Q-Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:

    int helper(vector<int>&prices,int idx,int n,int buy, vector<vector<int>>&dp,int fee){
        if(n==idx)return 0;
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        int profit=0;
        if(buy)profit=max(-1*prices[idx]+helper(prices,idx+1,n,0,dp,fee),helper(prices,idx+1,
        n,1,dp,fee));
        else profit=max(prices[idx]-fee+helper(prices,idx+1,n,1,dp,fee),helper(prices,idx+1,n,0,dp,fee));

        return dp[idx][buy]=profit;

    }
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,0,n,1,dp,fee);
    }
};
