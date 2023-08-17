//program for implementation merge sort
#include<bits/stdc++.h>
using namespace std;

const int  N = 1e5+7;
int nums[N];


void merge(int l, int r, int mid)//l-mid = left array index sequence, mid+1 - r = right array sequence
{
    int left_size = mid;
    int right_size = r - mid;
    int leftSubArray[left_size + 1];
    int rightSubArray[right_size + 1];

    int j = 0;
    for(int i = l; i<= mid; i++)// prepare left Sub-array
    {
        leftSubArray[j] = nums[i];
        j++;
    }

    j= 0;

    for(int i = mid + 1; i <= r; i++)// prepare right sub-array
    {
        rightSubArray[j] = nums[i];
        j++;
    }
    leftSubArray[left_size] = INT_MAX;
    rightSubArray[right_size] = INT_MAX;

    int leftPointer = 0, rightPointer = 0;
    for(int i = l; i<= r; i++)
    {
        if(leftSubArray[leftPointer] < rightSubArray[rightPointer])
        {
            nums[i] = leftSubArray[leftPointer];
            leftPointer ++;
        }
        else 
        {
            nums[i] = rightSubArray[rightPointer];
            rightPointer ++;
        }
    }
}
void mergeSort(int l, int r)
{
    if(l == r) return; //base case
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    merge(l,r,mid);
}


int main()
{

    int n; cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> nums[i];
    }
    // sort(nums, nums+n);
    mergeSort(0,n-1);
    for(int i = 0; i < n; i++) cout<< nums[i]<<endl;
    return 0;
}