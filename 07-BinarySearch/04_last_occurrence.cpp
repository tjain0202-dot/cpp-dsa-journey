#include <iostream>
using namespace std;
int lastOccurence(int nums[], int size, int target)
{
    int l = 0;
    int r = size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] <= target)
        {
            l = mid + 1; 
        }
        else
        {
            r = mid - 1;
        }
    }
    return r;
}
int main()
{
    int nums[] = {1, 2, 2, 2, 2,2,2,2, 5, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 2;
    cout << lastOccurence(nums, size, target);
    return 0;
}