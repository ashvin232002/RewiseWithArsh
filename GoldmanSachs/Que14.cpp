#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007;;
class Solution {
public:
    long long reverse(int n){
        long long ans =0;
        while(n){
            int rem = n%10;
            ans=(ans*10)+rem;
            n=n/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,long long>mp;
        long long ans = 0;
        for(int i =0;i<nums.size();i++){
            int val = nums[i];
            int val2 = reverse(val);
            // cout<<val<<" "<<val2<<endl;
            mp[val-val2]++;
        }

        for(auto it:mp){
            ans+=(long long)((it.second*(it.second-1))/2);
        }
        return ans%mod;
    }
};