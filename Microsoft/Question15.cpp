#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        map<char,int>mp;
        int n = s.size();
        int i =0;
        int j =0;
        while(j<n && i<n){
            if(mp.size()<3){
                mp[s[j]]++;
                j++;
            }else{
                count+=(n-j+1);
                // cout<<count<<" ";
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;

            }
        }
        while(i<n){
            if(mp.size()==3){
                count++;
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }else{
                break;
            }
        }
        return count;
    }
};