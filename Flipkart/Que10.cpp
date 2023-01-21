#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int>ans;
        map<int,int>mp;
        for(int i =0;i<barcodes.size();i++){
            mp[barcodes[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        while(pq.size()>=2){
            auto top1  = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            ans.push_back(top1.second);
            ans.push_back(top2.second);
            if(top1.first-1>0){
                pq.push({top1.first-1,top1.second});
            }
            if(top2.first-1>0){
                pq.push({top2.first-1,top2.second});
            }
        }

        if(!pq.empty()){
            auto top= pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};