#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string>ans;
   bool isValid(string t){
        if(t[0]=='0' && t.size()>1){
            return false;
        }
        if(stoi(t)>255){
            return false;
        }
        return true;
   }
    void recursion(string &s,string temp,int curr,int k){
        if(k==4 && curr==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        if(curr==s.size() || k==4){
            return;
        }

        for(int len=1;len<=3 && curr+len<=s.size();len++){
            string  t = s.substr(curr,len);
            if(isValid(t)){
                recursion(s,temp+t+".",curr+len,k+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
       recursion(s,"",0,0);
       return ans;
    }
};