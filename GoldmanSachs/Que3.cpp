
#include<bits/stdc++.h>
using namespace std;

//First Approach
class Solution {
public:
    
    int trailingZeroes(int n) {

       int count = 0;

        for(int i = 5; i<=n;i=i*5)
        {
            count = count + n/i;
        }
        return count;
    }
};

//Second Approach
class Solution {
public:
    int count(int n){
        int count = 0;
        while(n){
            if(n%5==0){
                n=n/5;
                count++;
            }else{
                break;
            }
        }
        return count;
    }
    int trailingZeroes(int n) {
        vector<int>a(n+1);
        a[0]=0;
        for(int i =1;i<=n;i++){
            if(i%5!=0){
                a[i]=a[i-1];
            }else{
                int val = count(i);
                a[i]=a[i-1]+val;
            }
        }
        return a[n];
    }
};