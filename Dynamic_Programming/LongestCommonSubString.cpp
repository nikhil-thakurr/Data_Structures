It is same as that of normal lcs but we dont have to carry our past soo put zero when they dont match

class Solution{
    public:
    
    int longestCommonSubstr (string text1, string text2, int n, int m)
    {
        // your code here
        int ans=0;
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));

          for(int i=0;i<n;i++)dp[i][0]=0;
        for(int j=0;j<m;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(text1[i-1]==text2[j-1]){
                     
                  dp[i][j]=1+dp[i-1][j-1];
                  ans=max(ans,dp[i][j]);
                 }

        else  dp[i][j]=0;
            }
        }
        return ans;
    }
};
