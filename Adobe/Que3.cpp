#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        int fib[31];
        fib[0]=1;
        fib[1]=2;
        for(int i =2;i<30;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        int ans = 0;
        int count = 30;
        int prev_bit =0;
        while(count>=0){
            if(n & (1<<count)){
                ans+=fib[count];
                if(prev_bit)return ans;
                prev_bit=1;
            }else{
                prev_bit=0;
            }
            count--;
        }
        return ans+1;
    }
};


