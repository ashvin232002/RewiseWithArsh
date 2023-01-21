#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<vector<double>>>dp;
    vector<double>dr,dc;

    double recursion(int n,int k,int row,int col){
        if(row<0 || col<0 || row>=n || col>=n ){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[row][col][k]!=-1){
            return dp[row][col][k];
        }
        double ans = 0;
        for(int i=0;i<dr.size();i++){
            ans+=recursion(n,k-1,row+dr[i],col+dc[i]);
        }
        return dp[row][col][k]=ans/8;
    }
    double knightProbability(int n, int k, int row, int column) {
       dp.resize(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
       dr = {2,2,1,1,-1,-1,-2,-2};
       dc = {-1,1,-2,2,-2,2,-1,1};
       return recursion(n,k,row,column);
    }
};