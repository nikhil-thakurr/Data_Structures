Q-Link  : https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

class Solution{
		

	public:
	  int helper(int i,int j,string &s,string &t,  vector<vector<int>>&dp){
        if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])return dp[i][j]=1+helper(i-1,j-1,s,t,dp);

        else return dp[i][j]=max(helper(i-1,j,s,t,dp),helper(i,j-1,s,t,dp));
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string text1, string text2)
    {
        // your code here
        int i=text1.size();
        int j=text2.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));

        return helper(i-1,j-1,text1,text2,dp);
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    return str1.size()+str2.size()-2*lcs(str1.size(),str2.size(),str1,str2);
	    
	} 
};
