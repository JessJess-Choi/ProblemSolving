#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;cin>>k>>n;
    int arr[10001];
    ll low=1,high=3e10;
    ll ans = 0;
    for(int i=0;i<k;i++)
        cin>>arr[i];
    while(low <= high){
        ll mid = (low + high) / 2;
        ll value = 0;
        for(int i=0;i<k;i++)value += arr[i] / mid;
        if(value >= n){
            low = mid + 1;
            ans = max(ans,mid);
        }
        else
            high = mid - 1;
    }
    cout<<ans;
    return 0;
}
