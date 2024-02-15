Q-Link : https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution {
public:

    string PrintLCS(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  if(text1[i-1]==text2[j-1]) dp[i][j]=1 +dp[i-1][j-1];

                 else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }

    string LCS="";
      
      int i=text1.length(),j=text2.length();
      while(i>0 &&j>0){

        if(text1[i-1]==text2[j-1]){

          LCS.push_back(text1[i-1]);
          
          i--;
          j--;
          
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            LCS.push_back(text1[i-1]);
                i--;
        }
          else {
              LCS.push_back(text2[j-1]);
              j--;
              }

      }
      while(i>0){
          LCS.push_back(text1[i-1]);
          i--;
        
      }
      while(j>0){
          LCS.push_back(text2[j-1]);
          j--;
        
      }
      reverse(LCS.begin(),LCS.end());
      return LCS;

    }

    string shortestCommonSupersequence(string str1, string str2) {
        return PrintLCS(str1,str2);
    }
};
