Q-Link : https://leetcode.com/problems/maximum-length-of-pair-chain/description/

LIS VARIANT

  class Solution {
public:
 int helper(vector<vector<int>>& nums,int idx,int prev, vector<vector<int>>&dp){
        if(idx==nums.size())return 0;

        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];

        int nontake=helper(nums,idx+1,prev,dp);
        int take=0;

        if(prev==-1 || nums[idx][0]>nums[prev][1]){
            take=1+helper(nums,idx+1,idx,dp);
        }

        return dp[idx][prev+1]=max(take,nontake);
    }

    int lengthOfLIS(vector<vector<int>>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(nums,0,-1,dp);
    }
    int findLongestChain(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        return lengthOfLIS(nums);
    }
};
