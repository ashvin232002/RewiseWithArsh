#include<bits/stdc++.h>
using namespace std;


//Gives TLE

// class Solution {
// public:
//     bool solve(vector<int>& nums,vector<int>& visited,int start,int k,int currSum,int subsetSum){
//         if(k==0){
//             return true;
//         }
//         if(currSum>subsetSum)return false;
//         if(currSum==subsetSum){
//             return solve(nums,visited,0,k-1,0,subsetSum);
//         }

//         for(int i =start;i<nums.size();i++){
//             if(visited[i])continue;
//             visited[i]=1;
//             if(solve(nums,visited,i+1,k,currSum+nums[i],subsetSum))return true;
//             visited[i]=0;
//         }
//         return false;
//     }
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int n = nums.size();
//         if(n<k)return false;
//         if(k==1)return true;
//         int sum =0;
//         for(int i =0;i<n;i++){
//             sum+=nums[i];
//         }
//         if(sum%k!=0)return false;
//         int SubsetSum = sum/k;
//         vector<int>visited(n,0);
//         return solve(nums,visited,0,k,0,SubsetSum);
//     }
// };


class Solution {
public:
    unordered_map<int, bool> memo; // avoid repetitive situations
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k>nums.size()) {
            // if the number of subsets is more than the numbers in nums, then return false.
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % k != 0)
            // if remainder exists, then return false.
            return false;
        int target = sum / k;
        int used = 0;
        return backtracking(k, nums, 0, used, target, 0);
    }
    
    bool backtracking(int k, vector<int>& nums, int start, int used, int target, int total) {
        if (k == 0) {
            // must be true
            return true;
        }
        if (memo.count(used))
            return memo[used];
        if(target == total) {
            bool res = backtracking(k-1, nums, 0, used, target, 0);
            memo[used]=res;
            return res;
        }
        for (int i = start; i < nums.size(); i++) {
            if (((used >> i) & 1) == 1) {
                // the i-th number have been used.
                continue;
            }
            if (nums[i]+total > target) {
                continue;
            }
            
            used = used | (1 << i); // OR -> make choice
            total += nums[i];
            
            if (backtracking(k, nums, i+1, used, target, total)){
                return true;
            }
            
            used = used ^ (1 << i); // XOR -> withdraw choice
            total -= nums[i];
        }
        
        return false;
    }
};