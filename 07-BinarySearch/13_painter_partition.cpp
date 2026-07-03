#include<iostream>
using namespace std;
bool canpaint(int arr[],int size,int k,int m){
    int paintercount =1;
    int totaltime =0;
    for(int i=0;i<size;i++){
        if(arr[i]+totaltime>m){
            paintercount++;
            totaltime=arr[i];
            if(arr[i]>m || paintercount>k){
                return false;
            }
        }
        else{
            totaltime+=arr[i];
        }
    }
    return true;
}
int confirmtime(int arr[],int size,int k){
    int l=0;
    int r=0;
    for(int i=0;i<size;i++){
        if(arr[i]>l){
            l=arr[i];
        }
            r+=arr[i];
    }
    while(l<=r){
        int m=l+(r-l)/2;
        if(canpaint(arr,size,k,m)){
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return l;
}
int main(){
    int arr[]={10,20,30,40};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    cout<<confirmtime(arr,size,k)<<endl;
}