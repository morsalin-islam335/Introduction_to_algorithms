//program to implement 0-1 knapsack by using recursion with memoization technique

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 6;
vector<vector<int>>dp(N, vector<int>(N,-1));

int knapsack(int n, int s, int v[], int w[])
{
      //base case
      if(n == 0 || s == 0) return 0;
      if(dp[n][s] != -1) return dp[n][s];
      if( w[n-1] <= s)
      {
          int opt1 = knapsack(n-1, s - w[n-1], v, w) + v[n-1];
          int opt2 = knapsack(n-1, s, v, w);
          return dp[n][s] = max(opt1, opt2);
      }
      else return dp[n][s] =  knapsack(n-1, s, v, w);
}
int main()
{
    int n; cin >> n;
    int v[n], w[n];
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> w[i];

    int  size; cin >> size;
    cout<<knapsack(n, size, v, w);
    return 0;
}