#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& nums) {
        long long sum =0;
        int n = nums.size();
        int m = nums[0].size();

        int mini = INT_MAX;
        int count = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
               sum+=abs(nums[i][j]);
               mini=min(mini,abs(nums[i][j]));
               if(nums[i][j]<=0)count++;
            }
        }
        // cout<<sum<<endl;
        // cout<<mini<<endl;
        if(count%2==0){
            return sum;
        }
        return sum-2*mini;
    }
};