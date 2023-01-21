#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long count = 0;
    
    void merge(int start,int mid,int end,vector<int>& nums1,int diff){
        int l = start,r=mid+1;
        while(l<=mid && r<=end){
             if(nums1[l]<=(nums1[r]+diff)){
                 count+=end-r+1;
                 l++;
             }else{
                 r++;
             }
        }
        sort(nums1.begin() + start, nums1.begin() + end + 1);  
        return;
    }
    void mergeSort(int s,int e,vector<int>& nums1,int diff){
        if(s>=e){
            return;
        }
        int mid = s+(e-s)/2;
        mergeSort(s,mid,nums1,diff);
        mergeSort(mid+1,e,nums1,diff);
        merge(s,mid,e,nums1,diff);
        return;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
          for(int i =0;i<nums1.size();i++){
              nums1[i]-=nums2[i];
          }
          mergeSort(0,nums1.size()-1,nums1,diff);
          return count;
    }
};