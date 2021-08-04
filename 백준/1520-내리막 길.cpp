#include<iostream>
using namespace std;
int dp[501][501],arr[501][501],n,m;
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
int dfs(int i,int j){
    if(i==0 && j==0)return 1;
    if(i<0 && j<0 && i>=n && j>=m)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    dp[i][j] = 0;
    for(int d=0;d<4;d++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if(arr[ni][nj] > arr[i][j])
            dp[i][j] += dfs(ni,nj);
    }
    return dp[i][j];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            dp[i][j] = -1;
        }
    cout<<dfs(n-1,m-1);
    return 0;
}
