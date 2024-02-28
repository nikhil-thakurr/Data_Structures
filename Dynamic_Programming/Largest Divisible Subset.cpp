Q-Link : https://leetcode.com/problems/largest-divisible-subset/description/

class Solution {
public:

  vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        
        vector<int>dp(n,1),hash(n);
        int maxi=-1;
        int last_Idx=0;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
                
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last_Idx=i;
            }
        }
        
        vector<int>ans;
        
        while(hash[last_Idx]!=last_Idx){
            ans.push_back(nums[last_Idx]);
            last_Idx=hash[last_Idx];
        }
        ans.push_back(nums[last_Idx]);
        reverse(ans.begin(),ans.end());
        
        return ans;

  }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return longestIncreasingSubsequence(nums.size(),nums);
    }
};
