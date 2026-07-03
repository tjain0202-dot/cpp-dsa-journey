#include<iostream>
using namespace std;
bool duplicate(int arr[],int size,int target){
    int l=0;
    int r=size-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==target){
            return true;
        }
        if (arr[l] == arr[mid] && arr[mid] == arr[r]) {
            l++;
            r--;
            continue;
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
    }return false;
}
int main(){
    int arr[]={1,1,1,0,1,1,1,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target=0;
    cout<<duplicate(arr,size,target)<<"\n";
}