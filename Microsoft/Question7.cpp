#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool recursion(vector<int>& visited,map<int,vector<int>>&mp,int node){
        if(visited[node]==2){
            return true;
        }
        visited[node]=2;
        for(auto it:mp[node]){
            if(visited[it]!=1){
                if(recursion(visited,mp,it)){
                    return true;
                }
            }
        }
        visited[node]=1;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        map<int,vector<int>>mp;
        for(int i =0;i<pre.size();i++){
            mp[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int>visited(num,0);
        for(int i =0;i<num;i++){
            if(!visited[i]){
                if(recursion(visited,mp,i)){
                    return false;
                }
            }
        }
        return true;
    }
};