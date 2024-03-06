Q-Link : https://leetcode.com/problems/delete-and-earn/description/


PRoblem is similar like house robber and can be solved by that method plus LIS as well 

Approach 1 : House Robber

class Solution {
public:
        int helper(vector<int>&nums,int idx,vector<int>&dp){
        if(idx==0)return nums[idx];
        if(idx<0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int take=INT_MIN;
        if(idx>=1)take=nums[idx]+helper(nums,idx-2,dp);

        int non_take=helper(nums,idx-1,dp);

        return dp[idx]=max(take,non_take);
         }

    int deleteAndEarn(vector<int>& nums) {
        int maxi=0;
        for(auto&x : nums)maxi=max(maxi,x);
        vector<int>vec(maxi+1,0);

        for(int i=0;i<nums.size();i++){
            vec[nums[i]]+=nums[i];
        }
        int n=vec.size();
        vector<int>dp(n,-1);
        return helper(vec,n-1,dp);
    }
};

Approach 2 : By Sorting

class Solution {
public: 

    int helper(vector<int>&nums,int idx,  vector<int>&dp){
        if(idx>=nums.size())return 0;

        int currval=nums[idx];
        int index=idx+1;
        int total=nums[idx];

        if(dp[idx]!=-1)return dp[idx];

        while(index<nums.size() && nums[index]==currval){
            
            total+=nums[index];
            index++;
        }

        while(index<nums.size() && nums[index]==currval+1){
            index++;
        }

        return dp[idx]=max(total+helper(nums,index,dp),helper(nums,idx+1,dp));

    }

    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size()+1,-1);
        return helper(nums,0,dp);
    }
};
