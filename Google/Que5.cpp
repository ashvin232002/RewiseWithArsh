#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recursion(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1||grid[i][j]==2){
            return;
        }
        grid[i][j]=2;
        recursion(i+1,j,grid);
        recursion(i-1,j,grid);
        recursion(i,j+1,grid);
        recursion(i,j-1,grid);
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<n;i++){
            if(grid[i][0]==0){
                recursion(i,0,grid);
            }
            if(grid[i][m-1]==0){
                recursion(i,m-1,grid);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==0){
                recursion(0,j,grid);
            }
            if(grid[n-1][j]==0){
                recursion(n-1,j,grid);
            }
        }

        int count = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==0){
                    count++;
                    recursion(i,j,grid);
                }
            }
        }
        return count;
    }

};