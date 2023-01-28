#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define mod 1000000007
     int dp[3001][1001];
     long long recursion(int start,int end,int k){
            if(start==end && k==0){
                return 1;
            }
            if(k<=0){
                return 0;
            }
             if(dp[start+1000][k]!=-1){
                 return dp[start+1000][k];
             }
          long long ch1  = recursion(start+1,end,k-1)%mod;
          long long ch2  = recursion(start-1,end,k-1)%mod;
         return dp[start+1000][k]=(ch1 +ch2)%mod;
    }
    int numberOfWays(int start, int end, int k) {
        for(int i =0;i<3001;i++){
            for(int j =0;j<1001;j++){
                dp[i][j]=-1;
            }
        }
         long long count =0;
        count =recursion(start,end,k);
        return count;
    }
    
};