#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>>mp;
        for(int i =0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        int count = 0;
        for(int i =0;i<words.size();i++){
            string curr = words[i];
            int index =-1;
            bool flag=true;
            for(int j =0;j<curr.size();j++){
                char temp = curr[j];
                if(mp.find(temp)!=mp.end()){
                     auto currIndex=  upper_bound(mp[temp].begin(),mp[temp].end(),index);
                     if(currIndex==mp[temp].end()){
                         flag=false;
                         break;
                     }else{
                         index = *currIndex;
                     }
                }else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                //cout<<curr<<endl;
                count++;
            }
        }
        return count;
    }
};