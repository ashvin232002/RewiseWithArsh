#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i =1;i<=n-2;i++){
            for(int j=1;j<=m-2;j++){
                 int sum = 0;
                 sum+=(grid[i][j]+grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1]);
                 ans=max(ans,sum);
            }
        }
        return ans;
    }
};