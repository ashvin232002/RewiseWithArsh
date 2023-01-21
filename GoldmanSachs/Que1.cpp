#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2){
            return n;
        }
        int ans  =0;
        for(auto it: points){
            unordered_map<double,int>mp;
            double x1 = it[0];
            double y1 = it[1];
            double slope=0;
            for(auto it2: points){
                 if(it==it2)continue;
                 double x2 = it2[0];
                 double y2 = it2[1];
                 if(x2-x1==0){
                     slope=INT_MAX;
                 }else{
                     slope = ((y2-y1)/(x2-x1));
                 }
                 mp[slope]++;
                 ans=max(ans,mp[slope]);
            }
        }
        return ans+1;
    }
};