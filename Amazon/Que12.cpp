#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    int dp[1001][1001];
    int recursion(vector<int>&nums1,vector<int>&nums2,int i,int j){
        if(i>=nums1.size() || j>=nums2.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res = 0;
        if(nums1[i]==nums2[j]){
            res=recursion(nums1,nums2,i+1,j+1)+1;
            ans = max(ans,res);
        }
         recursion(nums1,nums2,i+1,j);
         recursion(nums1,nums2,i,j+1);
        
        
        return dp[i][j]=res;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        for(int i =0;i<1001;i++){
            for(int j =0;j<1001;j++){
                dp[i][j]=-1;
            }
        }
        recursion(nums1,nums2,0,0);
        return ans;
    }
};