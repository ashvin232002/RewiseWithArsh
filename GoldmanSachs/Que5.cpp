#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
         map<int,int>freq;
        map<int,int>available;
        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i =0;i<nums.size();i++){
            if(freq[nums[i]]==0){
                continue;
            }
            freq[nums[i]]--;
            if(available[nums[i]-1]>0){
                available[nums[i]-1]--;
                available[nums[i]]++;
            }else if(freq[nums[i]+1]>0 && freq[nums[i]+2]>0){
                freq[nums[i]+1]--;
                freq[nums[i]+2]--;
                available[nums[i]+2]++;
            }else{
               return false;
            }
        }
        return true;
    }
};