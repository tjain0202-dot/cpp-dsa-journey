#include<iostream>
using namespace std;
int sumdivisiblebym(int arr[],int size,int k,int m){
    int sum=0;
    int divisiblebym=0;
    for(int i=0;i<size;i++){
        if(i<k){
            sum+=arr[i];
        }
        else{
            sum+=arr[i]-arr[i-k];
        }
        if(i>=k-1&&sum%m==0){
            divisiblebym++;
        }
    }
    return divisiblebym;
}
int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    int m=3;
    cout<<sumdivisiblebym(arr,size,k,m)<<endl;
    return 0;
}