// #include<iostream> 
// using namespace std; 
// int findLargestSubarray(int arr[],int size,int k){ 
//     int sum=0; 
//     int l=0; 
//     int maxlength=0; 
//     for(int r =0;r<size;r++){ 
//         sum += arr[r];
//         while(sum > k){
//             sum-=arr[l]; 
//             l++; 
//         } 
//         if(sum<=k){ 
//             maxlength = max(maxlength, r - l + 1); 
//         } 
//     }
//     return maxlength; 
// } 
// int main(){ 
//     int arr[]={1,2,3,4,5}; 
//     int size=sizeof(arr)/sizeof(arr[0]); 
//     int k=7; 
//     cout<<findLargestSubarray(arr,size,k)<<endl; 
//     return 0; 
// }

#include<iostream> 
using namespace std; 
int findsmallestSubarray(int arr[],int size,int k){ 
    int sum=0; 
    int l=0; 
    int minlength=size+1; 
    for(int r =0;r<size;r++){ 
        sum += arr[r];
        while(sum >= k){
            minlength = min(minlength, r - l + 1); 
            sum-=arr[l]; 
            l++; 
        } 
    }
    if(minlength == size + 1){
    return 0;
    }
    return minlength;
} 
int main(){ 
    int arr[]={2,3,1,2,4,3}; 
    int size=sizeof(arr)/sizeof(arr[0]); 
    int k=7; 
    cout<<findsmallestSubarray(arr,size,k)<<endl; 
    return 0; 
}