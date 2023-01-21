#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        map<long long,vector<pair<long long,long long>>>mp;
        for(int i =0;i<roads.size();i++){
            mp[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            mp[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,1e18);
        vector<long long>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            long long distance = top.first;
            long long node = top.second;
            for(auto it:mp[node]){
                if((distance+it.second)<dist[it.first]){
                    dist[it.first]=distance+it.second;
                    pq.push({dist[it.first],it.first});
                    ways[it.first]=ways[node];
                }else if(dist[it.first]==distance+it.second){
                    ways[it.first]=(ways[it.first]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};