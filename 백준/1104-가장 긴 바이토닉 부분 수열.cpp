#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;
int arr[1001],dp[2][1001],ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		dp[0][i] = dp[1][i] = 1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(arr[j] < arr[i])
				dp[0][i] = max(dp[0][i],dp[0][j]+1);
	for(int i=n-1;i>=0;i--)
		for(int j=n-1;j>=i;j--)
			if(arr[j] < arr[i])
				dp[1][i] = max(dp[1][i],dp[1][j]+1);
	for(int i=0;i<n;i++)
		ans = max(ans,dp[0][i]+dp[1][i]-1);
	cout<<ans;
    return 0;
}
