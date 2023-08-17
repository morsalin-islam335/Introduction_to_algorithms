//program for find negative number from 2D vector
//problem link:  https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;

        int negativeNumber = 0;
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j < grid.front().size(); j++)
            {
                if(grid[i][j] <0) negativeNumber ++;
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return negativeNumber;
    }
};