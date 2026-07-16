// #include <iostream>
// using namespace std;
// int findmaxSum(int arr[], int size , int k){
//     int sum =0;
//     int maxsum =INT_MIN;
//     for(int i=0; i<size ; i++){
//         if(i<k){
//             sum+=arr[i];
//         }
//         else{
//             sum+=arr[i]-arr[i-k];
//         }
//         if(i>=k-1 && sum>maxsum){
//             maxsum = sum;
//         }
//     }
//     return maxsum;
// }
// int main(){
//     int arr[] ={-9,-2,-8};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     int k = 2;
//     cout << findmaxSum(arr, size, k) << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
float findmaxaverage(int arr[], int size , int k){
    int sum =0;
    int maxsum =INT_MIN;
    for(int i=0; i<size ; i++){
        if(i<k){
            sum+=arr[i];
        }
        else{
            sum+=arr[i]-arr[i-k];
        }
        if(i>=k-1 && sum>maxsum){
            maxsum = sum;
        }
    }
    return (float)maxsum/k;
}
int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << findmaxaverage(arr, size, k) << endl;
    return 0;
}