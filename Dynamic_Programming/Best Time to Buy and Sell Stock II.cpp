Q-Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

Approach 1 : Recursion

class Solution {
public:

    int helper(vector<int>&prices,int buy,int idx){
        if(idx==prices.size())return 0;

        int profit=0;

        if(buy){
            profit=max(-prices[idx]+helper(prices,0,idx+1),0+helper(prices,1,idx+1));
        }
        else profit=max(prices[idx]+helper(prices,1,idx+1),helper(prices,0,idx+1));

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return helper(prices,1,0);
    }
};

Approach 2 : Memo

  class Solution {
public:

    int helper(vector<int>&prices,int buy,int idx, vector<vector<int>>&dp){
        if(idx==prices.size())return 0;

        int profit=0;

        if(dp[idx][buy]!=-1)return dp[idx][buy];

        if(buy){
            profit=max(-prices[idx]+helper(prices,0,idx+1,dp),0+helper(prices,1,idx+1,dp));
        }
        else profit=max(prices[idx]+helper(prices,1,idx+1,dp),helper(prices,0,idx+1,dp));

        return dp[idx][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return helper(prices,1,0,dp);
    }
};

Approach 3 : Tabulation

  class Solution {
public:


    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));

        dp[prices.size()][0]=dp[prices.size()][1]=0;

        for(int idx=prices.size()-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;

                if(buy){
                    profit=max(-prices[idx]+dp[idx+1][0],0+dp[idx+1][1]);
                }
                else profit=max(prices[idx]+dp[idx+1][1],dp[idx+1][0]);

                 dp[idx][buy]=profit;
            }
        }

        return dp[0][1];
    }
};

Approach 4 : Space Optimization

class Solution {
public:


    int maxProfit(vector<int>& prices) {
        vector<int>prev(2),curr(2);

        prev[0]=prev[1]=0;

        for(int idx=prices.size()-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;

                if(buy){
                    profit=max(-prices[idx]+prev[0],0+prev[1]);
                }
                else profit=max(prices[idx]+prev[1],prev[0]);

                 curr[buy]=profit;
            }
            prev=curr;
        }

        return prev[1];
    }
};

Approach 5 : Greedy

  class Solution {
public:


    int maxProfit(vector<int>& prices) {
            int n=prices.size();
            int ans=0;
                for(int i=1; i<=n-1; ++i){
                    int diff=prices[i]-prices[i-1];
                    if(diff>0){ans+=diff;}
                }
                return ans;
    }
};
