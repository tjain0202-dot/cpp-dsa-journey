#include <iostream>
using namespace std;
int firstOcurence(int nums[], int size, int target)
{
    int l = 0;
    int r = size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] >= target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
int main()
{
    int nums[] = {1, 2, 2, 2, 2, 5,5,5,5,5,5, 6,6,6,6,6};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    cout << firstOcurence(nums, size, target);
}