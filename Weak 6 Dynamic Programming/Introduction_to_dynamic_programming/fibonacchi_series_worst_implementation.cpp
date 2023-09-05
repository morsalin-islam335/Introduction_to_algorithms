//program to find out fibonacci number
//this program complexity is 2^n
#include<bits/stdc++.h>
using namespace std;

long long fibonacci(int n)
{
    if(n <= 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main()
{
    int n; cin >> n;
    cout<<fibonacci(n);
    return 0;
}