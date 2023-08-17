//program for sort an array by using divide and conquer or merge sort
//problem link:  https://leetcode.com/problems/sort-an-array

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int>v;
    void merge_sort(int left, int right)
    {
        if(left == right) return; // base case
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, right, mid);
    }
    void merge(int left,int right, int mid)
    {
        vector<int>leftSubArray,rightSubArray;
        for(int i = left; i <= mid; i++)//push on left sub-array
        {
            leftSubArray.push_back(v[i]);
        }
        leftSubArray.push_back(INT_MAX);

        for(int i = mid + 1; i<= right; i++) //  prepare right-sub array
        {
            rightSubArray.push_back(v[i]);
        }
        rightSubArray.push_back(INT_MAX);
        // now merge them
        int leftPointer = 0, rightPointer = 0;
        for(int i = left; i <= right; i++)
        {
            if(leftSubArray[leftPointer] <= rightSubArray[rightPointer])
            {
                v[i] = leftSubArray[leftPointer];
                leftPointer ++;
            }
            else
            {
                v[i]= rightSubArray[rightPointer];
                rightPointer ++;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 0)
        {
            vector<int>vc;
            return vc;
        }
        v = nums;
        merge_sort(0, nums.size() - 1);
        return v;
    }
};

int main()
{
    Solution s;
    int n; cin >> n;
    vector<int>v;
    while(n --)
    {
        int val; cin >> val;
        v.push_back(val);
    }
    vector<int>Sort;
    Sort = s.sortArray(v);
    for(int val: Sort) cout<< val<<" ";

    return 0;
}