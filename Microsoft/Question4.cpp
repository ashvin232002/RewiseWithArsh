/*   The basic Idea Behind this problem would be we have to take the sum.
     suppose  --->nums[4,3,2,6]
              -->sum = 15 ,  n=4
              so now we calculate the dp[0] by brute force.
              but when we proceed for the dp[1] we use dp[1] = dp[0]+(sum-(n*(lastelement)))
*/ 
              
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long  sum  = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
        }
        vector<long long>dp(n,0);
        for(int i =0;i<n;i++){
             dp[0]+=i*nums[i];
        }
        int j = n-1;
        for(int i =1;i<n;i++){
            dp[i]=dp[i-1]+(sum-(n*nums[j]));
            j--;
        }
        return *max_element(dp.begin(),dp.end());
    }
};