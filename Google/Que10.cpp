#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i =0;i<times.size();i++){
            mp[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        dist[0]=0;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int s  = pq.top().second;
            int d =  pq.top().first;
            pq.pop();
            for(auto it:mp[s]){
                if(d+it.second<dist[it.first]){
                    dist[it.first]=d+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i =0;i<=n;i++){
            //cout<<dist[i]<<" ";
            if(dist[i]==1e9){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};