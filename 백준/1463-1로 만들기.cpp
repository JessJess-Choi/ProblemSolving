#include<iostream>
#include<algorithm>
using namespace std;
int dp[1000001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x;cin>>x;
    dp[1] = 0;
    for(int i=2;i<=x;i++)
        if(i%6 == 0)
            dp[i] = min(dp[i-1],min(dp[i/3],dp[i/2])) + 1;
        else if(i%3 == 0)
            dp[i] = min(dp[i-1],dp[i/3]) + 1;
        else if(i%2 == 0)
            dp[i] = min(dp[i-1],dp[i/2]) + 1;
        else
            dp[i] = dp[i-1] + 1;
    cout<<dp[x];
    return 0;
}
