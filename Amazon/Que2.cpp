#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int,unordered_map<int,int>>mp;
        for(auto e : flights)
            mp[e[0]][e[1]] = e[2];
        unordered_map<int,int>cost = mp[src];
        for(int i = 0; i < K; i++)
        {
            auto tmp = cost;
            for(auto e : tmp)
            {
                auto next = mp[e.first];
                for(auto f : next)
                {
                    if(cost.count(f.first))
                    {
                        cost[f.first] = min(cost[f.first], e.second + f.second);
                    }
                    else
                    {
                        cost[f.first] = e.second + f.second;                        
                    }
                }
            }
        }
        return cost.count(dst) ? cost[dst] : -1;
    }
};