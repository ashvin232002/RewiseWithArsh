#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls =0 ;
        for(int i =0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
        }
        map<int,int>mp;
        int cow = 0;
        for(int i =0;i<secret.size();i++){
            mp[secret[i]]++;
        }
        for(int i =0;i<guess.size();i++){
            if(mp.find(guess[i])!=mp.end()){
                mp[guess[i]]--;
                if(mp[guess[i]]==0){
                    mp.erase(guess[i]);
                }
                cow++;
            }
        }
        cow = cow-bulls;
        return to_string(bulls)+"A"+to_string(cow)+"B";
    }
};