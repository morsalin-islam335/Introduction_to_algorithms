//program to implement find operation

#include<bits/stdc++.h>
using namespace std;

int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};

int find(int n)
{
    while(parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}
int main()
{
    for(int i = 1; i <= 7; i ++)
    {
        cout<<find(i)<<endl;
    }
    return 0;
}