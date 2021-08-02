#include<iostream>
#define MOD 1000000009
using namespace std;
long long dp[3][100001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;cin>>T;
    dp[0][1] = dp[1][2] = dp[0][3] = dp[1][3] = dp[2][3] = 1;
    for(int i=4;i<100001;i++){
        dp[0][i] = (dp[1][i-1] + dp[2][i-1]) % MOD;
        dp[1][i] = (dp[0][i-2] + dp[2][i-2]) % MOD;
        dp[2][i] = (dp[0][i-3] + dp[1][i-3]) % MOD;
    }
    while(T--){
        int n;cin>>n;
        cout<<(dp[0][n] + dp[1][n] + dp[2][n]) % MOD<<'\n';
    }
    return 0;
}
