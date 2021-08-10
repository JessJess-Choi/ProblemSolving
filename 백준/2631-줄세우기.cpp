#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;
int arr[201];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	vector<int> v;
	v.push_back(-INF);
	for(int i=0;i<n;i++)
		if(v.back() < arr[i])v.push_back(arr[i]);
		else{
			auto it = lower_bound(v.begin(),v.end(),arr[i]);
			*it = arr[i];
		}
	cout<<n - v.size() + 1<<'\n';
    return 0;
}
