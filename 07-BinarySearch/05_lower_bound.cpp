#include<iostream>
using namespace std;
int lowerbound(int nums[], int size,int target){
    int l=0;
    int r= size-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]>=target){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}
int main(){
    int nums[]={1,2,3,3,3,4,5,6,9};
    int size=sizeof(nums)/sizeof(nums[0]);
    int target =7;
    int m=lowerbound(nums,size,target);
    cout<<m<<endl;
    cout<<nums[m]<<endl;
}