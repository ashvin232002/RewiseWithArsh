#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
      int n = s.size();
      if(n==0){
          return "";
      }
      vector<int>prefix(n,0);
      int i =0;
      int j =1;
      while(j<n){
          if(s[i]==s[j]){
              prefix[j]=i+1;
              i++;
              j++;
          }else{
              if(i==0){
                  j++;
              }else{
                  i = prefix[i-1];
              }
          }
      }
      return s.substr(0,i);
    }
};