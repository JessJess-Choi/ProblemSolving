#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001],dp[1001],sum[1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++){
		dp[i] = 1;
		sum[i] = arr[i];
		for(int j=0;j<i;j++)
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i],dp[j]+1);
				sum[i] = max(sum[i],arr[i] + sum[j]);
			}
	}
	sort(sum,sum+n);
	cout<<sum[n-1];
    return 0;
}
