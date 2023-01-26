#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int i =0;
        int j =0;
        int n = fruits.size();
        map<int,int>mp;
        while(i<n){
            if(mp.find(fruits[i])==mp.end() && mp.size()==2){
                ans=max(ans,i-j);
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0){
                    mp.erase(fruits[j]);
                }
                j++;
            }else if(mp.find(fruits[i])!=mp.end()){
                mp[fruits[i]]++;
                i++;
            }else if(mp.find(fruits[i])==mp.end() && mp.size()<2){
                mp[fruits[i]]++;
                i++;
            }
        }
        ans=max(ans,i-j);
        return ans;
    }
};