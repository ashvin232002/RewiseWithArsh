#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end(),greater<int>());
        int i =0;
        int j =1;
        int k =n-1;
        int ans = 0;
        while(j<k && i<k){
            ans+=piles[j];
            j+=2;
            i+=2;
            k--;
        }
        return ans;
    }
};