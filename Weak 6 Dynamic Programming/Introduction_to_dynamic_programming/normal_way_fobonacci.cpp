//program to calculate fibonacci number by using loop

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n; cin >> n;
    ll fibo[n+1];
    fibo[0] = 1; fibo[1] = 1;
    for(ll i = 2; i<= n; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout<<fibo[n];
    return 0;
}
