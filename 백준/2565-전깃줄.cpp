#include<iostream>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	vector<pair<int,int>> v;
	vector<int> dp;
	dp.push_back(-INF);
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
		if(dp.back() < v[i].second)dp.push_back(v[i].second);
		else{
			auto it = lower_bound(dp.begin(),dp.end(),v[i].second);
			*it = v[i].second;
		}
	cout<<n - dp.size() + 1;
    return 0;
}
