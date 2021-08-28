#include<iostream>
using namespace std;
int w[101],cost[101],dp[101][10001],sum,ans=1e9;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)cin>>cost[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=10000;j++){
            if(j < cost[i])dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-cost[i]]+w[i]);
            if(dp[i][j] >= m)ans = min(ans,j);
        }
    cout<<ans;
    return 0;
}
