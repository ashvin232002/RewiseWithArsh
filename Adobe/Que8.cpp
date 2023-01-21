#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        map<string,int>mp;
        for(int i =0;i<bank.size();i++){
            mp[bank[i]]++;
        }
        if(mp.find(endGene)==mp.end()){
            return -1;
        }

        int count = 0;
        queue<string>q;
        q.push(startGene);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                    string curr = q.front();
                    q.pop();
                    if(curr==endGene){
                        return count;
                    }
                    for(int i =0;i<curr.size();i++){
                        string temp = curr;
                        vector<char>replace = {'A','C','G','T'};
                        for(int j =0;j<4;j++){
                            temp[i]=replace[j];
                            if(curr==temp)continue;
                            if(mp.find(temp)==mp.end()){
                                continue;
                            }else{
                                q.push(temp);
                                mp.erase(temp);
                            }
                        }
                    }
            }
            count++;
        }
        return -1;
    }
};