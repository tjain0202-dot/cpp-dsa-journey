#include<iostream>
using namespace std;

bool canShip(int weight[], int size, int k, int d){
    int days = 1;
    int current_weight = 0;
    for(int i=0;i<size;i++){
        if(current_weight + weight[i] > k){
            days++;
            current_weight = weight[i];
            }
            else {
                current_weight += weight[i]; 
            }
    }
    if(days<=d){
         return true;
    }
    else{
        return false;
    }
}
int shipWithinDays(int weight[], int size, int d){
    int l=0;
    int r=0;
    for(int i=0; i<size; i++){
        if(weight[i] > l){
            l = weight[i];
        }
        r += weight[i];
    }
    while(l<=r){
        int mid=l+(r-l)/2;
        if(canShip(weight,size,mid,d)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}

int main(){
    int weight[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(weight)/sizeof(weight[0]);
    int d=5;
    int k=15;
    cout<<canShip(weight,size,k,d)<<endl;
    cout<<shipWithinDays(weight,size,d)<<endl;
}
