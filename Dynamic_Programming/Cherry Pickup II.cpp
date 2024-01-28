Q-Link : https://leetcode.com/problems/cherry-pickup-ii/description/

Approach 1 : Memo

class Solution {
public:

    int helper(vector<vector<int>>& grid,int row,int c1,int c2,int n,int m, vector<vector<vector<int>>>&dp){
        if(c1<0 || c2<0 || c1>=m || c2>=m )return -1e9;

        if(row==n-1){
            if(c1==c2)return grid[row][c1];
            return grid[row][c1]+grid[row][c2]; 
        }

        if(dp[row][c1][c2]!=-1)return dp[row][c1][c2];

        int val=0;

        int maxi=-1e8;

        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                 if(c1!=c2)val=grid[row][c2]+grid[row][c1];
                 else  val=grid[row][c1];

                val+=helper(grid,row+1,c1+i,c2+j,n,m,dp);

                maxi=max(maxi,val);
            }
        }

        return dp[row][c1][c2]=maxi;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int idx=0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(grid,idx,idx,m-1,n,m,dp);
    }
};

Approach 2 :Tabulation

  class Solution {
public:

    int helper(vector<vector<int>>& grid,int row,int c1,int c2,int n,int m, vector<vector<vector<int>>>&dp){
        if(c1<0 || c2<0 || c1>=m || c2>=m )return -1e9;

        if(row==n-1){
            if(c1==c2)return grid[row][c1];
            return grid[row][c1]+grid[row][c2]; 
        }

        if(dp[row][c1][c2]!=-1)return dp[row][c1][c2];

        int val=0;

        int maxi=-1e8;

        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                 if(c1!=c2)val=grid[row][c2]+grid[row][c1];
                 else  val=grid[row][c1];

                val+=helper(grid,row+1,c1+i,c2+j,n,m,dp);

                maxi=max(maxi,val);
            }
        }

        return dp[row][c1][c2]=maxi;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int idx=0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));

        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
               if(j1!=j2) dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
               else dp[n-1][j1][j2]=grid[n-1][j2];

            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                     int maxi=-1e8;
                            for(int di=-1;di<=1;di++){
                                int val=0;
                               for(int dj=-1;dj<=1;dj++){
                                    if(j1!=j2)val=grid[i][j1]+grid[i][j2];
                                    else  val=grid[i][j1];

                                  if(j1+di<m && j2+dj<m&&j1+di>=0&&j2+dj>=0)  val+=dp[i+1][j1+di][j2+dj];
                                    else val+=-1e9;
                                    maxi=max(maxi,val);
            }
        }
        dp[i][j1][j2]=maxi;
                }
            }
        }

        return dp[0][0][m-1];
        
    }
};
