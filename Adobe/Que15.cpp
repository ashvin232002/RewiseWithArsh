#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i =0;i<queries.size();i++){
            vector<string>temp = nums;
            for(int j =0;j<temp.size();j++){
                temp[j]=temp[j].substr(temp[j].size()-queries[i][1]);
            }
            vector<pair<string,int>>v;
            for(int k =0;k<temp.size();k++){
                v.push_back({temp[k],k});
            }
            sort(v.begin(),v.end());
            ans.push_back(v[queries[i][0]-1].second);
        }
        return ans;
    }
};