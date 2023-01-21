#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(int i =0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector<pair<int,string>>v;
        vector<string>ans;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),[&](pair<int,string>& a,pair<int,string>&b){
              if(a.first==b.first){
                  return a.second<b.second;
              }
              return a.first>b.first;
        });
        for(int i =0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};