#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int ans,n,arr[501][501],dp[501][501];
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
int dfs(int x,int y){
    if(dp[x][y])return dp[x][y];
    dp[x][y] = 1;
    for(int i=0;i<4;i++){
        int ni = x + di[i];
        int nj = y + dj[i];
        if(ni>=0 && nj>=0 && ni<n && nj<n)
            if(arr[x][y] < arr[ni][nj])
                dp[x][y] = max(dp[x][y],dfs(ni,nj)+1);
    }
    return dp[x][y];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans = max(ans,dfs(i,j));
    cout<<ans;
    return 0;
}
