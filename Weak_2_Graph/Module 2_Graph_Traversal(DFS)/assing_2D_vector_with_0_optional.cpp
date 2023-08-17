//program for assign 2D vector all value with  0
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>v(4,vector<int>(5,5));
    for(int i = 0; i<4; i++)
    {
        for(int val:v[i])
        {
            cout<< val<<" ";
        }
        cout<<endl;
    }
    return 0;
}