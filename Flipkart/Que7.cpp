#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Dijkatra(map<int,vector<pair<int,int>>>& mp,int n,int old,int node){
        vector<int>dist(n,1e9);
        dist[node]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node});
        while(!pq.empty()){
            int d = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for(auto it:mp[currNode]){
                if(d+it.second<dist[it.first]){
                    dist[it.first]=d+it.second;
                    pq.push({d+it.second,it.first});
                }
            }
        }
        int count = 0;
        for(int i =0;i<dist.size();i++){
            if(dist[i]<=old){
                count++;
            }
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int old) {
        map<int,vector<pair<int,int>>>mp;
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2]; 
            mp[u].push_back({v,wt});
            mp[v].push_back({u,wt});
        }
        
        int ans = INT_MAX;
        int index =-1;
        for(int i =0;i<n;i++){
            int curr =  Dijkatra(mp,n,old,i);
           // cout<<curr<<endl;
            if(curr<=ans){
                index= i;
                ans=curr;
            }
        }
        return index ;
    }
};