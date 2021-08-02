#include<iostream>
using namespace std;
int dp[41],arr[41];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,ans=1,tmp=0;cin>>n>>m;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<41;i++)dp[i] = dp[i-1] + dp[i-2];
    for(int i=0;i<m;i++)cin>>arr[i];
    for(int i=0;i<m;i++){
        ans *= dp[arr[i] - tmp - 1];
        tmp = arr[i];
    }
    cout<<ans * dp[n - tmp];
    return 0;
}
