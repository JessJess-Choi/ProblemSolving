#include<iostream>
#include<cstring>
using namespace std;
int n,m,w[21],dp[10001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;cin>>T;
    while(T--){
        memset(w,0,sizeof(w));
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>w[i];
        cin>>m;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(j >= w[i])dp[j] += dp[j-w[i]];
        cout<<dp[m]<<'\n';
    }
    return 0;
}
