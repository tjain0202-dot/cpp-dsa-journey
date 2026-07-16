#include<iostream>
using namespace std;
int findNoOfEvenDigits(int arr[],int size,int k){
    int evenDigits=0;
    int maxEvenDigits=0;
    for(int i=0;i<size;i++){
        if(i<k){
            if(arr[i]%2==0){
                evenDigits++;
            }
        }
        else{
            if(arr[i]%2==0){
                evenDigits++;
            }
            if(arr[i-k]%2==0){
                evenDigits--;
            }
        }
        if(i>=k-1&&evenDigits>maxEvenDigits){
            maxEvenDigits=evenDigits;
        }
    }
    return maxEvenDigits;
}
int main(){
    int arr[]={12,34,56,77,90};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    cout<<findNoOfEvenDigits(arr,size,k)<<endl;
    return 0;
}