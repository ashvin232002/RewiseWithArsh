#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string>st;
        int sz = nums.size();
        for(int i =0;i<sz;i++){
            for(int j =i;j<sz;j++){
                string temp;int cnt = 0;
                for(int m =i;m<=j;m++){
                    temp.push_back(nums[m]);
                    if(nums[m]%p==0){
                        cnt++;
                    }
                    if(cnt>k){
                        break;
                    }
                }
                if(cnt<=k){
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};