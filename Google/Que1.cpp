#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        int ans = INT_MIN;
        sort(special.begin(),special.end());
        int i =0;
        while(i<special.size()-1){
            ans=max(ans,special[i+1]-special[i]-1);
            i++;
        }
        ans=max(ans,special[0]-bottom);
        ans=max(ans,top-special[n-1]);
        return ans;
    }
};