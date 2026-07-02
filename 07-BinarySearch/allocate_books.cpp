#include<iostream>
using namespace std;
bool canallocate(int arr[],int size,int m,int s){
    int sum=0;
    int studentused=1;
    for(int i=0;i<size;i++){
        if(sum+arr[i]>s){
            if(arr[i]>s){
                return false;
            }
            studentused++;
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    return studentused <= m;
}
int allocatebooks(int arr[], int size, int m){
    int l=0;
    int r=0;
    for(int i=0;i<size;i++){
        if(arr[i]>l){
            l=arr[i];
        }
        r+=arr[i];
    }
    while(l<=r){
        int mid=l+(r-l)/2;
        if(canallocate(arr,size,m,mid)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}
int main(){
    int arr[]={12,34,67,90};
    int size=sizeof(arr)/sizeof(arr[0]);
    int m=2;
    int s=113;
    cout<<allocatebooks(arr,size,m)<<endl;
    cout<<canallocate(arr,size,m,s)<<endl;
}