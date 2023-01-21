#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        int n  = nums.size();
        if(n==0){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        for(int i =1;i<n;i++){
            for(int j =0;j<i;j++){
                   if(nums[i]%nums[j]==0){
                        if(dp[j]+1>dp[i]){
                            dp[i]=dp[j]+1;
                        }
                   }
            }
        }

        int maxa = *max_element(dp.begin(),dp.end());
        int prev =-1;
        for(int i =dp.size()-1;i>=0;i--){
            if(dp[i]==maxa && (prev==-1 || prev%nums[i]==0)){
                  ans.push_back(nums[i]);
                  maxa=maxa-1;
                  prev=nums[i];
            }
        }
        return ans;
    }
};