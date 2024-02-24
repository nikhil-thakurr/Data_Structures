Q-Link : https://leetcode.com/problems/longest-increasing-subsequence/description/

Approach 1 : Recursion

class Solution {
public:

    int helper(vector<int>&nums,int idx,int prev){
        if(idx==nums.size())return 0;

        int nontake=helper(nums,idx+1,prev);
        int take=0;

        if(prev==-1 || nums[idx]>nums[prev]){
            take=1+helper(nums,idx+1,idx);
        }

        return max(take,nontake);
    }

    int lengthOfLIS(vector<int>& nums) {
        return helper(nums,0,-1);
    }
};

Approach 2 : Memo

  class Solution {
public:

    int helper(vector<int>&nums,int idx,int prev, vector<vector<int>>&dp){
        if(idx==nums.size())return 0;

        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];

        int nontake=helper(nums,idx+1,prev,dp);
        int take=0;

        if(prev==-1 || nums[idx]>nums[prev]){
            take=1+helper(nums,idx+1,idx,dp);
        }

        return dp[idx][prev+1]=max(take,nontake);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(nums,0,-1,dp);
    }
};

Approach 3 : Tabulation

  class Solution {
public:


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                 int nontake=dp[i+1][j+1];
                 int take=0;

                    if(j==-1 || nums[i]>nums[j]){
                        take=1+dp[i+1][i+1];
                    }
                    dp[i][j+1]=max(take,nontake);
            }
            
        }

        return dp[0][0];
    }
};

Approach 4 : Space Optimisation

class Solution {
public:


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n+1,0),curr(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                 int nontake=next[j+1];
                 int take=0;

                    if(j==-1 || nums[i]>nums[j]){
                        take=1+next[i+1];
                    }
                   curr[j+1]=max(take,nontake);
            }
            next=curr;
            
        }

        return curr[0];
    }
};

Approach 5 : 1D array Space optimization

class Solution {
public:


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }

        int maxi=-1;

        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};

Approach 6 : Not Intuitive

class Solution {
public:


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
                
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};

