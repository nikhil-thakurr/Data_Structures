Q-Link : https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

Approach 1 : Recursion 

class Solution{
public:
    
    int helper(int idx, int W, int val[], int wt[]){
        
        if(idx==0){
            return (W/wt[0])*val[0];
        }
        
        int nontake=helper(idx-1,W,val,wt);
        int take=INT_MIN;
        if(wt[idx]<=W)take=val[idx]+helper(idx,W-wt[idx],val,wt);
        
        return max(take,nontake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        return helper(N-1,W,val,wt);
    }
};

Approach 2 : Memo

  class Solution{
public:
    
    int helper(int idx, int W, int val[], int wt[], vector<vector<int>>&dp){
        
        if(idx==0){
            return (W/wt[0])*val[0];
        }
        if(dp[idx][W]!=-1)return dp[idx][W];
        int nontake=helper(idx-1,W,val,wt,dp);
        int take=INT_MIN;
        if(wt[idx]<=W)take=val[idx]+helper(idx,W-wt[idx],val,wt,dp);
        
        return dp[idx][W]=max(take,nontake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return helper(N-1,W,val,wt,dp);
    }
};

Approach 3 : Tabulation

  class Solution{
public:
    
   

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        for(int i=0;i<=W;i++){
            dp[0][i]= (i/wt[0])*val[0];
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                 int nontake=dp[i-1][j];
                 int take=INT_MIN;
                 if(wt[i]<=j)take=val[i]+dp[i][j-wt[i]];
        
                  dp[i][j]=max(take,nontake);
            }
        }
        return dp[N-1][W];
    }
};

Approach 4 : Space Optimization

class Solution{
public:
    
   

    int knapSack(int N, int W, int val[], int wt[])
    {
       
        vector<int>prev(W+1,0),curr(W+1,0);
        for(int i=0;i<=W;i++){
            prev[i]= (i/wt[0])*val[0];
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                 int nontake=prev[j];
                 int take=INT_MIN;
                 if(wt[i]<=j)take=val[i]+curr[j-wt[i]];
        
                  curr[j]=max(take,nontake);
            }
            prev=curr;
        }
        return prev[W];
    }
};
