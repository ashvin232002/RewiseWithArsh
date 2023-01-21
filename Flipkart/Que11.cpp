#include<bits/stdc++.h>
using namespace std;
class StockPrice {
public:
    
    multiset<int>sArr;
    map<int,int>dic;
    unordered_map<int,int>countDic;
    
    StockPrice() {
        sArr={};
        dic={};
    }
    
    void update(int timestamp, int price) {
        if(dic.count(timestamp)!=0){
            int val=dic[timestamp];
            sArr.erase(dic[timestamp]);
            countDic[val]--;
            int count=countDic[val];
            while(count--){
                sArr.insert(val);
            }
        }
        

            sArr.insert(price);
            dic[timestamp]= price;
            countDic[price]++;
        
    }
    
    int current() {
        return dic.rbegin()->second;
    }
    
    int maximum() {
        return *sArr.rbegin();
    }
    
    int minimum() {
        return *sArr.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
