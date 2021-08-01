#include<iostream>
#define ll long long
using namespace std;
ll dp[100];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;cin>>n;
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<100;i++)dp[i] = dp[i-1] + dp[i-2];
    cout<<dp[n];
    return 0;
}
