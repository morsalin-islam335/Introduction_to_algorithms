//program to merge 2 sorted array
//problem link:  https://leetcode.com/problems/merge-sorted-array

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0)
        {
            nums1 = nums2;
            return;
        }
        
        // make a array which will contain 2 array's all value
        vector<int>full_vector;
        
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        nums1[m] = INT_MAX;
        nums2[n]= INT_MAX;
        int nums1_index = 0, nums2_index = 0;

        for(int i = 0; i< n+m; i++)
        {
            if(nums1[nums1_index] < nums2[nums2_index])
            {
                full_vector.push_back(nums1[nums1_index]);
                nums1_index ++;
            }
            else 
            {
                full_vector.push_back(nums2[nums2_index]);
                nums2_index ++;
            }
        }


        nums1 = full_vector;

    }
};