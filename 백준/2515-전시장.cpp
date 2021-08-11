#include<iostream>
#include<vector>
#include<algorithm>
#define P pair<int,int>
using namespace std;
int index[300001],dp[300001];
vector<P> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,s;cin>>n>>s;
	v.push_back({0,0});
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		for(index[i]=index[i-1]+1;index[i]<i;index[i]++)
			if(v[i].first-v[index[i]].first < s)break;
		index[i]--;
	}
	for(int i=1;i<=n;i++){
		dp[i] = dp[index[i]] + v[i].second;
		dp[i] = max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
    return 0;
}
