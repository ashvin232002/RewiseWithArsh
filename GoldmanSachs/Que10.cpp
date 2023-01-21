#include<bits/stdc++.h>
using namespace std;

const int mod =1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>know(n+1,0);
        know[0]=1;
        for(int i =0;i<n;i++){
            for(int j =i+delay;j<min(n,i+forget);j++){
                know[j]=(know[i]+know[j])%mod;
            }
        }
        long long val =0;
        for(int j =max(0,n-forget);j<n;j++){
            val=(val+know[j])%mod;
        }
        return val%mod;
    }
};