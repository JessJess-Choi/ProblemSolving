#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;
int arr[1000001],indx[1000001],dp[1000001],l;
vector<int> ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++){
		auto it = lower_bound(dp,dp+l,arr[i]);
		if(*it == 0)l++;
		*it = arr[i];
		indx[i] = it-dp;
	}
	cout<<l<<'\n';
	for(int i=n-1;i>=0;i--)
		if(indx[i] == l-1){
			ans.push_back(arr[i]);
			l--;
		}
	reverse(ans.begin(),ans.end());
	for(auto a : ans)cout<<a<<' ';
    return 0;
}
