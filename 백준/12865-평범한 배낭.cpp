#include<iostream>
using namespace std;
int n,k,w[101],v[100001],dp[101][100001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            if(j<w[i])dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
    cout<<dp[n][k];
    return 0;
}
