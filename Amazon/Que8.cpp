#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        bool flag=true;
        long long sum =mass;
        for(int i =0;i<n;i++){
            if(a[i]>sum){
                flag=false;
                break;
            }else{
                 sum+=a[i]*1ll;
            }
        }
        return flag;
    }
};