#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>v(right+1,1);
        v[1]=0;
        v[0]=0;
        for(int i =2;i*i<=right;i++){
            if(v[i]==1){
                for(int j =i*i;j<=right;j+=i){
                    v[j]=0;
                }
            }
        }
        vector<int>primes;
        for(int i =left;i<=right;i++){
            if(v[i]==1){
                primes.push_back(i);
            }
        }
        
        if(primes.size()<=1){
            return {-1,-1};
        }
        
        int mini = INT_MAX;
        vector<int>ans;
        sort(primes.begin(),primes.end());
        for(int i =1;i<primes.size();i++){
            if(primes[i]-primes[i-1]<mini){
                ans={primes[i-1],primes[i]};
                mini=primes[i]-primes[i-1];
            }
        }
        return ans;
    }
};