#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int n;
    string s;
    int res;
     set<string>ss; 
    int maxUniqueSplit(string g) {
        s=g;
        res=0;
        n=s.length();
       
        check(0);
        return res;
    }
    void check(int x)
    {
        if(x==n)
        {
            int r=ss.size();
            res=max(res,r); 
            return;
        }
        string g="";
        for(int i=x;i<n;i++)
        {
           g+=s[i];  
           if(ss.find(g)==ss.end())
           {
               ss.insert(g);  
               check(i+1); 
               //cout<<g<<endl;
               ss.erase(g);
           }
       }
    }
};