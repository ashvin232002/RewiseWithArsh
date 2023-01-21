#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>v;
        for(int i =0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
         sort(v.begin(), v.end(), [&](const pair<int, int>&a, const pair<int, int>&b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        // for(auto it:v){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        priority_queue<pair<int,int>>pq;
        long long score = 0;
        int i =0;
        while(k>0 ){
            while(i<n){
                if(v[i].first<=w){
                    pq.push({v[i].second,v[i].first});
                    i++;
                }else{
                    break;
                }
            }
            if(!pq.empty()){
                auto top= pq.top();
                pq.pop();
                w+=top.first;
            }
            k--;
        }
        return w;
    }
};