#include <iostream>
#define MOD 100000

using namespace std;

int w, h, dp[101][101][4];
//dp [0] 동북, [1] 동동, [2] 북동, [3] 북북
//h : x, w : y
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> w >> h;
    for(int i=1;i<101;i++)
        dp[i][1][3] = dp[1][i][1] = 1;
    for(int i=2;i<=h;i++){
        for(int j=2;j<=w;j++){
            dp[i][j][0] = dp[i-1][j][1];
            dp[i][j][1] = (dp[i][j-1][1] + dp[i][j-1][2]) % MOD;
            dp[i][j][2] = dp[i][j-1][3];
            dp[i][j][3] = (dp[i-1][j][0] + dp[i-1][j][3]) % MOD;
        }
    }
    cout<<(dp[h][w][0] + dp[h][w][1] + dp[h][w][2] + dp[h][w][3]) % MOD;
    return 0;
}
