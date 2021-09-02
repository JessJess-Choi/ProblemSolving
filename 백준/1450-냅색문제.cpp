#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
vector<ll> v1,v2;
ll ans,n,c,w[31];
void dfs(int s,int e,vector<ll>& v,ll sum){
    if(s > e){
        v.push_back(sum);
        return;
    }
    else{
        dfs(s+1,e,v,sum);
        dfs(s+1,e,v,sum+w[s]);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>c;
    for(int i=0;i<n;i++)cin>>w[i];
    dfs(0,n/2,v1,0);
    dfs(n/2+1,n-1,v2,0);
    sort(v2.begin(),v2.end());
    for(auto a : v1)
        ans += upper_bound(v2.begin(),v2.end(),c-a) - v2.begin();
    cout<<ans;
    return 0;
}
