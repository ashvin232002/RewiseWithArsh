#include<bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* root = new ListNode(0);
        root->next =  head;
        unordered_map<int,ListNode*>mp;
        mp[0]=root;
        int sum =0;
        while(head!=NULL){
            sum+=head->val;
            if(mp.find(sum)!=mp.end()){
                ListNode* prev = mp[sum];
                ListNode* start = prev;
                int curr = sum;
                while(prev!=head){
                     prev=prev->next;
                     curr+=prev->val;
                     if(prev!=head)mp.erase(curr);
                }
                start->next=head->next;
            }else{
                mp[sum]=head;
            }
            head=head->next;
        }
        return root->next;
    }
};