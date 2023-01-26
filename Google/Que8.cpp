#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> m;
    random_device rd;
public:
    Solution(vector<int> w) {
        m = move(w);
        for (int i = 1; i < m.size(); ++i)
            m[i] += m[i-1];
    }
    int pickIndex() {
        return lower_bound(m.begin(), m.end(), rd() % m.back() + 1) - m.begin();
    }
};