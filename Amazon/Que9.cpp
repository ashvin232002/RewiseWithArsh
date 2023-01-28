#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<string>> mostPopularCreator(vector<string>& cre, vector<string>& ids, vector<int>& views) {
        vector<vector<string>>ans;
        map<string,long long>mp;
        map<string,pair<long long,string>>mp2;
        
        
        for(int i =0;i<cre.size();i++){
            mp[cre[i]]+=views[i];
        }
        
        for(int i =0;i<cre.size();i++){
            
            if(mp2.find(cre[i])==mp2.end()){
                mp2[cre[i]]=(make_pair(views[i],ids[i]));
            }
            else{
                if(mp2.find(cre[i])!=mp2.end() && mp2[cre[i]].first<views[i]){
                     mp2[cre[i]]=(make_pair(views[i],ids[i]));
                }else if(mp2.find(cre[i])!=mp2.end() && mp2[cre[i]].first==views[i]){
                    if(mp2[cre[i]].second>ids[i]){
                         mp2[cre[i]]=(make_pair(views[i],ids[i]));
                    }else{
                        continue;
                    }
                }
            }
           
        }
       
        long long maxa = INT_MIN;
        for(auto it:mp){
            maxa = max(maxa,it.second);
        }
        
        for(auto it:mp){
            if(it.second==maxa){
                ans.push_back({it.first,mp2[it.first].second});
            }
        }
        return ans;
    }
};