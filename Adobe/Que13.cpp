
#include<bits/stdc++.h>
using namespace std;
//Recursion + Memoization
class Solution {
public:
    int recursion(vector<vector<int>>& nums,int i ,int j,int n,int m, vector<vector<int>>&dp){
        if(i>=n || j>=m){
            return 1e6;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==n-1 && j==m-1){
            if(nums[i][j]>0){
                return dp[i][j]=1;
            }
            return abs(nums[i][j])+1;
        }

        int ch1 = recursion(nums,i+1,j,n,m,dp);
        int ch2 = recursion(nums,i,j+1,n,m,dp);

        if(nums[i][j]>=min(ch1,ch2)){
            return dp[i][j]=1;
        }
        return dp[i][j]=min(ch1,ch2)-nums[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& points) {
       int n = points.size();
       int m = points[0].size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return recursion(points,0,0,n,m,dp);
    }
};

















//Tabulation

class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int>>& nums) {
       int n = nums.size();
       int m = nums[0].size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
       dp[n-1][m-1]= nums[n-1][m-1]>0 ? 1: abs(nums[n-1][m-1])+1;

       for(int i =n-2;i>=0;i--){
           dp[i][m-1]= max(dp[i+1][m-1]-nums[i][m-1],1);
       }

       for(int i = m-2;i>=0;i--){
           dp[n-1][i]=max(dp[n-1][i+1]-nums[n-1][i],1);
       }

       for(int i =n-2;i>=0;i--){
           for(int j =m-2;j>=0;j--){
               dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-nums[i][j],1);
           }
       }
       return dp[0][0];
    }
};