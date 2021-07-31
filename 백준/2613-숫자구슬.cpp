#include<iostream>
#include<algorithm>
using namespace std;
int n,m,arr[301],ans[301];

bool f(int mid){
    int marble = 0,cnt = m;
    while(marble < n){
        int tmp = n - cnt + 1;
        while(marble < tmp && arr[tmp]-arr[marble] > mid)tmp--;
        if(marble == tmp)return true;
        ans[--cnt] = tmp - marble;
        marble = tmp;
    }
    return cnt!=0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=0;i<=n;i++)arr[i+1] += arr[i];
    int low = 1,high = 100*n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(f(mid))low = mid + 1;
        else
            high = mid - 1;
    }
    cout<<low<<'\n';
    f(low);
    reverse(ans,ans+m);
    for(int i=0;i<m;i++)cout<<ans[i]<<' ';
    return 0;
}
