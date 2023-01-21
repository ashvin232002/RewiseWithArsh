#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int curr =numsDivide[0];
        for(int i =1;i<numsDivide.size();i++){
            curr=__gcd(curr,numsDivide[i]);
        }
        // cout<<curr<<endl;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i =0;i<nums.size();i++){
            if(curr%nums[i]==0){
                return count;
            }else if(nums[i]>curr){
                return -1;
            }else{
                count++;
            }
        }
        return -1;
    }
};