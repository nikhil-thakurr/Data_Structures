Q-Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=prices[0];

        for(int i=1;i<prices.size();i++){
           
            profit=max(profit,prices[i]-mini);
             if(mini>prices[i]){
                mini=prices[i];
                
            }
        }

        return profit;
    }
};
