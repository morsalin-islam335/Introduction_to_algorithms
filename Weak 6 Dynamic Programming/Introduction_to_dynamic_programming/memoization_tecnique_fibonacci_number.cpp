//program to find out fibonacci number by using memoization technique
//this program complexity is O(N)

#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e5;
ll save[N];

ll fibonacci(ll n)
{
    if(n <= 1) return 1;
    
    if(save[n] != -1) return save[n];
    save[n] = fibonacci(n-1) + fibonacci(n-2);
    return save[n];
}
int main()
{
    ll n; cin >> n;
    for(int i = 0; i <= n; i++) save[i] = -1;

    cout<<fibonacci(n);
    return 0;
}
