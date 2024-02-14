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
      int len=dp[n][m];
      len--;
      for(int i=0;i<;len;i++){
        LCS+="$";
      }
      int i=text1.length()-1,j=text2.length()-1;
      while(i>0 &&j>0){

        if(text1[i-1]==text2[j-1]){

          LCS[len]=text1[i-1];
          len--;
          i--;
          j--;
          
        }
        else if(dp[i-1][j]>dp[i][j-1]){
                i--;
        }
          else j--;
      }
      
      return LCS;
    }
};
