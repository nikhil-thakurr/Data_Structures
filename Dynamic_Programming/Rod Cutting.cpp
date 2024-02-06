Q-Link : https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

Approach 1 : Memo

class Solution{
  public:
    
    int helper(int price[], int n,int idx, vector<vector<int>>&dp){
        if(idx==0)return price[0]*n;
        if(dp[n][idx]!=-1)return dp[n][idx];
        int nontake=helper(price,n,idx-1,dp);
        int take=INT_MIN;
        if((idx+1)<=n)take=price[idx]+helper(price,n-idx-1,idx,dp);
        
        return dp[n][idx]=max(take,nontake);
        
        
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return helper(price,n,n-1,dp);
    }
};

Approach 2 : Tabulation 

  class Solution{
  public:
    
    int helper(int price[], int n,int idx, vector<vector<int>>&dp){
        if(idx==0)return price[0]*n;
        if(dp[n][idx]!=-1)return dp[n][idx];
        int nontake=helper(price,n,idx-1,dp);
        int take=INT_MIN;
        if((idx+1)<=n)take=price[idx]+helper(price,n-idx-1,idx,dp);
        
        return dp[n][idx]=max(take,nontake);
        
        
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return helper(price,n,n-1,dp);
    }
};




  
