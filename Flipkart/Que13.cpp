#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
            return 1;
        }
        return 0;
    }
    void recursion(vector<vector<int>>& grid,int i,int j,int n,int m,int &area){
        area++;
        grid[i][j]=0;
        if(isValid(grid,i+1,j,n,m)){
            recursion(grid,i+1,j,n,m,area);
        }
        if(isValid(grid,i-1,j,n,m)){
            recursion(grid,i-1,j,n,m,area);
        }
        if(isValid(grid,i,j+1,n,m)){
            recursion(grid,i,j+1,n,m,area);
        }
        if(isValid(grid,i,j-1,n,m)){
            recursion(grid,i,j-1,n,m,area);
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans =0;
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                int area =0;
                if(grid[i][j]==1){
                    recursion(grid,i,j,n,m,area);
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};