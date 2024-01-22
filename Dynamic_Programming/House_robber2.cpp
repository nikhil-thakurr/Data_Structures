Q-Link : https://leetcode.com/problems/house-robber-ii/description/

Approach 1 : Memo

class Solution {
public:

    int helper(vector<int>&nums,int st,int end, vector<int>&dp){
        if(st==end)return nums[end];
        if(st<end)return 0;
        if(dp[st]!=-1)return dp[st];
        int take=nums[st] +helper(nums,st-2,end,dp);
        int nontake=helper(nums,st-1,end,dp);

        return dp[st]=max(take,nontake);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        int end=0;
        int end2=1;
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        vector<int>dp2(n,-1);
     return max(   helper(nums,n-1,end2,dp),
        helper(nums,n-2,end,dp2));
    }
};

Approach 2 : Tabulation

  class Solution {
public:
    int helper2(vector<int>&arr){

        vector<int>dp(arr.size(),-1);

        dp[0]=arr[0];

        for(int i=1;i<arr.size();i++){
            int take=arr[i];
            if(i>=2)take+=dp[i-2];

            int nontake=dp[i-1];

            dp[i]=max(take,nontake);
        }
        return dp[arr.size()-1];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

         vector<int>temp1,temp2;

         for(int i=0;i<n;i++){
             if(i!=n-1)temp1.push_back(nums[i]);
             if(i!=0)temp2.push_back(nums[i]);
         }

        return max(helper2(temp1),helper2(temp2));
   
    }
};

Approach 3 : Space Optimization 

class Solution {
public:
    int helper2(vector<int>&arr){

       

        int prev=arr[0];
        int prev2=0;

        for(int i=1;i<arr.size();i++){
            int take=arr[i];
            if(i>=2)take+=prev2;

            int nontake=prev;

           int cur=max(take,nontake);

           prev2=prev;
           prev=cur;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

         vector<int>temp1,temp2;

         for(int i=0;i<n;i++){
             if(i!=n-1)temp1.push_back(nums[i]);
             if(i!=0)temp2.push_back(nums[i]);
         }

        return max(helper2(temp1),helper2(temp2));
   
    }
};
