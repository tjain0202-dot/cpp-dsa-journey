#include<iostream>
using namespace std;
int searchInsert(int nums[], int size, int target){
    int l = 0;
    int r = size - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return l;
}
int main(){
    int nums[] = {1,3,5,6};
    int size = sizeof(nums)/sizeof(nums[0]);
    int target = -1;
    cout<<searchInsert(nums,size,target);

}