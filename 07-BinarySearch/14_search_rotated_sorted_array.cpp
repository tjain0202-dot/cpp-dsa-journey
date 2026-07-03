#include<iostream>
using namespace std;
int rotatedarray(int arr[],int size,int target){
    int l=0;
    int r=size-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[l]<=arr[mid]){
            if(target>=arr[l] && target<arr[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else{
            if(target<=arr[r] && target>arr[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }   
    }return -1;
}
int main(){
    int arr[]={4,5,6,7,0,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target=5;
    cout<<rotatedarray(arr,size,target)<<"\n";
}
