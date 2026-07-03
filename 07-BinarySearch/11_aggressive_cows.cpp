#include<iostream>
#include<algorithm>
using namespace std;
bool canstall(int stalls[],int size,int m,int s){
    int lastcowplaced=stalls[0];
    int cowused=1;
    for(int i=1;i<size;i++){
        if(stalls[i]-lastcowplaced>=s){
            cowused++;
            lastcowplaced=stalls[i];
            if(cowused==m){
                return true;
            }   
        }
    }
    return false;
}
int allocatestalls(int stalls[], int size, int m){
    int l=1;
    int r=stalls[size-1]-stalls[0];
    while(l<=r){
        int mid=l+(r-l)/2;
        if(canstall(stalls,size,m,mid)){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return r;

}
int main(){
    int stalls[]={1, 4, 2, 8, 9};
    int size=sizeof(stalls)/sizeof(stalls[0]);
    int m=3;
    int s=3;
    sort(stalls,stalls+size);
    cout<<allocatestalls(stalls,size,m)<<endl;
    cout<<canstall(stalls,size,m,s)<<endl;
