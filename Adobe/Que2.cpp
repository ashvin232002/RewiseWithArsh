#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>mini(n);
        vector<int>maxa(n);

        stack<int>s;
        for(int i =0;i<n;i++){
            if(s.empty()){
                mini[i]=-1;
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
                    mini[i]=-1;
                    s.push(i);
                }else{
                    mini[i]=s.top();
                    s.push(i);
                }
            }
        }
        while(!s.empty()){
            s.pop();
        }

        for(int i =n-1;i>=0;i--){
            if(s.empty()){
                maxa[i]=-1;
                s.push(i);
            }else{
                while(!s.empty()){
                    if(nums[s.top()]<=nums[i]){
                        s.pop();
                    }else{
                        break;
                    }
                }
                if(s.empty()){
                    maxa[i]=-1;
                    s.push(i);
                }else{
                    maxa[i]=s.top();
                    s.push(i);
                }
            }
        }
        
        for(int i =0;i<n;i++){
            if(mini[i]!= -1 && maxa[i]!=-1){
                return true;
            }
        }
        return false;
    }
};