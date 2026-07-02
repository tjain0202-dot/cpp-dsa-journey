#include<iostream>
using namespace std;

bool canFinish(int piles[], int size, int k, int h){
    int hours=0;
    for(int i=0;i<size;i++){
        hours+=(piles[i] + k -1)/k;
    }
    if(hours<=h){
         return true;
    }
    else{
        return false;
    }
}

int minEatingSpeed(int piles[], int size, int h){
    int l=1;
    // Finding the maximum pile to set a correct right bound (R)
    int r=0;
    for(int i=0; i<size; i++){
        if(piles[i] > r){
            r = piles[i];
        }
    }
    while(l<=r){
        int mid=l+(r-l)/2;
        if(canFinish(piles,size,mid,h)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}

int main(){
    int piles[]={3,5,7,11};
    int size=sizeof(piles)/sizeof(piles[0]);
    int h=8;
    int k=4;
    cout<<canFinish(piles,size,k,h)<<endl;
    cout<<minEatingSpeed(piles,size,h)<<endl;
}