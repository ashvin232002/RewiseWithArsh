#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        int mini = INT_MAX;
        int maxa = INT_MIN;

        for(int i =0;i<n;i++){
            if(i==0){
                if(nums[i]>nums[i+1]){
                    mini=min(mini,nums[i]);
                    maxa=max(maxa,nums[i]);
                }
            }else if(i==n-1){
                if(nums[i]<nums[i-1]){
                    mini=min(mini,nums[i]);
                    maxa=max(maxa,nums[i]);
                }
            }else{
                if(nums[i]<nums[i-1] || nums[i]>nums[i+1]){
                    mini=min(mini,nums[i]);
                    maxa=max(maxa,nums[i]);
                }
            }
        }

        if(mini==INT_MAX || maxa==INT_MIN){
            return 0;
        }
        int i,j;
        for(i=0;i<n && nums[i]<=mini;i++);
        for(j=n-1;j>=0 && nums[j]>=maxa;j--);
        return j-i+1;
    }
};