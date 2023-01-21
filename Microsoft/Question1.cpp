#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<long long>st;
      long long ans  =0;
      for(int i =0;i<tokens.size();i++){
            string temp = tokens[i];
            if(temp!="/" && temp!="+" && temp!="-" && temp!="*"){
                st.push(stoi(temp));
            }else if(temp=="+"){
                int top2 = st.top();
                st.pop();
                int top1 = st.top();
                st.pop();
                st.push(top1+top2);
            }else if(temp=="-"){
                int top2 = st.top();
                st.pop();
                int top1 = st.top();
                st.pop();
                st.push(top1-top2);
            }else if(temp=="/"){
                int top2 = st.top();
                st.pop();
                int top1 = st.top();
                st.pop();
                st.push(top1/top2);
            }else{
                int top2 = st.top();
                st.pop();
                int top1 = st.top();
                st.pop();
                st.push(top1*top2);
            }
      }
       return st.top();
    }
};