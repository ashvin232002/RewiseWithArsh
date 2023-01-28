#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    #define mod 1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        long long ans = INT_MIN;
        int n= nums.size();
        vector<long long>sum(n,0);
        sum[0]=nums[0];
        for(int i =1;i<n;i++){
            sum[i]=sum[i-1]+nums[i];
            ans=max(ans,1ll*nums[i]*nums[i]);
        }
        stack<int>s;
        vector<int>right(n);
        vector<int>left(n);
        for(int i =n-1;i>=0;i--){
            if(s.empty()){
                 right[i]=-1;
                 s.push(i);
            }else{
                while(!s.empty()){
                     if(nums[s.top()]>=nums[i]){
                         s.pop();
                     }else{
                         break;
                     }
                }
                if(s.empty()){
                    right[i]=-1;
                    s.push(i);
                }else{
                    right[i]=s.top();
                    s.push(i);
                }
            }
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i =0;i<n;i++){
            if(s.empty()){
                left[i]=-1;
                s.push(i);
            }else{
                while(!s.empty()){
                    if(nums[s.top()]>=nums[i]){
                        s.pop();
                    }else{
                        break;
                    }
                }
                if(s.empty()){
                    left[i]=-1;
                    s.push(i);
                }else{
                    left[i]=s.top();
                    s.push(i);
                }
            }
        }

        for(int i =0;i<n;i++){
            if(left[i]==-1 && right[i]==-1){
                ans=max(ans,sum[n-1]*nums[i]*1ll);
            }else if(left[i]==-1){
                int index=right[i];
                ans=max(ans,(sum[index-1])*nums[i]*1ll);
            }else if(right[i]==-1){
                  int index=left[i];
                 ans=max(ans,(sum[n-1]-sum[index])*nums[i]*1ll);
            }else{
                int index1=left[i];
                int index2=right[i];
                ans=max(ans,(sum[index2-1]-sum[index1])*nums[i]*1ll);
            }
        }
        return ans%1000000007;
    }
};