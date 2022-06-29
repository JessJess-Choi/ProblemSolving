#include <iostream>
#define INF 1e9

using namespace std;

int n, arr[3][1001], dp[3][1001], ans = INF;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            if(i == j)dp[j][1] = arr[j][1];
            else dp[j][1] = INF;
        for(int j=2;j<=n;j++){
            dp[0][j] = arr[0][j] + min(dp[1][j-1], dp[2][j-1]);
            dp[1][j] = arr[1][j] + min(dp[0][j-1], dp[2][j-1]);
            dp[2][j] = arr[2][j] + min(dp[1][j-1], dp[0][j-1]);
        }
        for(int j=0;j<3;j++)
            if(i != j)
                ans = min(ans, dp[j][n]);
    }
    cout<<ans;
    return 0;
}
