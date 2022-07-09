#include <iostream>
#include <algorithm>
#define MAX 1e9

using namespace std;

int N, M, K, dp[201][101];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    K--;
    dp[0][0] = 1;
    for(int i=1;i<=N+M;i++){
        dp[i][0] = 1;
        if(i <= M)
            dp[i][i] = 1;
        for(int j=1;j<i;j++){
            if(j > M)break;
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            if(dp[i][j] > MAX)dp[i][j] = MAX;
        }
    }
    if(dp[N + M][M] <= K){
        cout<<-1;
        return 0;
    }
    for(int i=N+M-1;i>=0;i--){
        if(i >= M && dp[i][M] > K)cout<<"a";
        else{
            cout<<"z";
            K -= dp[i][M];
            M--;
        }
    }
    return 0;
}
