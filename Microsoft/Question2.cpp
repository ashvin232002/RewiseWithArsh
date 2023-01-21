#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recursion(vector<vector<int>>& ans,vector<int>v,int n,int k,int start){
        if(k==0){
            if(n==0){
                ans.push_back(v);
                v.resize(0);
            }
            return;
        }
        if(k<0 || n<0){
            return;
        }
        for(int i =start;i<=9;i++){
            v.push_back(i);
            recursion(ans,v,n-i,k-1,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        int start = 1;
        recursion(ans,v,n,k,start);
        return ans;
    }
};