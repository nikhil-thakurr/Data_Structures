Q-Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

class Solution {
public:
 int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        // return helper(i-1,j-1,text1,text2,dp);
        for(int i=0;i<n;i++)dp[i][0]=0;
        for(int j=0;j<m;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];

        else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string A) {
         string b=A;
        reverse(b.begin(),b.end());
        return longestCommonSubsequence(A,b);
    }
    int minInsertions(string s) {
        return s.length()-longestPalindromeSubseq(s);
    }
};
