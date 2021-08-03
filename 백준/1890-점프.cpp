#include<iostream>
using namespace std;
long long arr[101][101],dp[101][101];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    dp[0][0] = 1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(!dp[i][j] || (i == n-1 && j == n-1))continue;
            int down = arr[i][j] + i;
            int right = arr[i][j] + j;
            if(down < n)dp[down][j] += dp[i][j];
            if(right < n)dp[i][right] += dp[i][j];
        }
    cout<<dp[n-1][n-1];
    return 0;
}
