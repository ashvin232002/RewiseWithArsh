#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        map<int,vector<int>>mp;
        for(int i =0;i<pre.size();i++){
            mp[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int>Indegree(num,0);
        for(auto it:mp){
            for(auto i:it.second){
                Indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>temp;
        for(int i =0;i<Indegree.size();i++){
            if(Indegree[i]==0){
                q.push(i);
                temp.push_back(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:mp[node]){
                Indegree[it]--;
                if(Indegree[it]==0){
                    q.push(it);
                    temp.push_back(it);
                }
            }
        }
        return  temp.size()==num;
    }
};