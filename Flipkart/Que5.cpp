#include<bits/stdc++.h>
using namespace std;
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
**/
class MountainArray {
  public:
    int get(int index);
    int length();
};


class Solution {
public:
    int binarySearch1(int start,int end,MountainArray &arr,int target){
           int mid = start+(end-start)/2;
           while(start<=end){
               if(arr.get(mid)==target){
                   return mid;
               }else if(arr.get(mid)<target){
                   start=mid+1;
               }else{
                   end=mid-1;
               }
               mid = start+(end-start)/2;
           }
           return -1;
    }
    int binarySearch2(int start,int end,MountainArray &arr,int target){
           int mid = start+(end-start)/2;
           while(start<=end){
               if(arr.get(mid)==target){
                   return mid;
               }else if(arr.get(mid)<target){
                   end=mid-1;
               }else{
                   start=mid+1;
               }
               mid = start+(end-start)/2;
           }
           return -1;
    }
    int pivotElement(int start,int end,MountainArray &arr){
        int mid = start+(end-start)/2;
        int peak=0;
        while(start<end){
            if(arr.get(mid)<arr.get(mid+1)){
                start = mid+1;
                peak=start;
            }else{
                end=mid;
            }
            mid = start+(end-start)/2;
        }
        return peak;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int pivot = pivotElement(0,n-1,mountainArr);
        int ans1 = binarySearch1(0,pivot,mountainArr,target);
        if(ans1!=-1)return ans1;
        int ans2 = binarySearch2(pivot+1,n-1,mountainArr,target);

        if(ans1==-1 && ans2!=-1){
            return ans2;
        }
        if(ans2==-1 && ans1!=-1){
            return ans1;
        }
        if(ans1==-1 && ans2==-1){
            return -1;
        }
        return min(ans1,ans2);
    }
};