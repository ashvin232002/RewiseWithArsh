#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0]=true;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int row = top.second.first;
            int col = top.second.second;
            int val = top.first;
            if(row==n-1 && col==n-1 ){
                return max(val,grid[n-1][n-1]);
            }
            if(isValid(row+1,col,n,m) && visited[row+1][col]==false){
                if(grid[row+1][col]>val){
                    pq.push({grid[row+1][col],{row+1,col}});
                }else{
                    pq.push({val,{row+1,col}});
                }
                visited[row+1][col]=true;
            }
            if(isValid(row-1,col,n,m) && visited[row-1][col]==false){
                if(grid[row-1][col]>val){
                    pq.push({grid[row-1][col],{row-1,col}});
                }else{
                     pq.push({val,{row-1,col}});
                }
                visited[row-1][col]=true;
            }
            if(isValid(row,col+1,n,m) && visited[row][col+1]==false){
                if(grid[row][col+1]>val){
                    pq.push({grid[row][col+1],{row,col+1}});
                }else{
                    pq.push({val,{row,col+1}});
                }
                visited[row][col+1]=true;
            }
            if(isValid(row,col-1,n,m) && visited[row][col-1]==false){
                if(grid[row][col-1]>val){
                    pq.push({grid[row][col-1],{row,col-1}});
                }else{
                    pq.push({val,{row,col-1}});
                }
                visited[row][col-1]=true;
            }
        }
        return -1;
    }
};