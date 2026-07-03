#include<iostream>
using namespace std;
bool cansplit(int arr[],int size,int k,int m){
    int sum=0;
    int subarraycount=1;
    for(int i=0;i<size;i++){
        if(arr[i]+sum>m){
            subarraycount++;
            sum=arr[i];
            if(arr[i]>m || subarraycount>k){
                return false;
            } 
        }
        else{
            sum+=arr[i];
        }
    }
    return true;
}
int confirmsplit(int arr[],int size,int k){
    int l=0;
    int r=0;
    for(int i=0;i<size;i++){
        if(arr[i]>l){
            l=arr[i];
            r+=arr[i];
        }
        else{
            r+=arr[i];
        }
    }
    while(l<=r){
        int m=l+(r-l)/2;
        if(cansplit(arr,size,k,m)){
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return l;
}
int main(){
    int arr[]={7,2,5,10,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    cout<<confirmsplit(arr,size,k)<<endl;
}