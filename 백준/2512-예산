#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;cin>>n;
    int arr[10001];
    ll low=0,high=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        high = max(high,(ll)arr[i]);
    }
    cin>>m;
    while(low <= high){
        ll mid = (low + high) / 2;
        ll value = 0;
        for(int i=0;i<n;i++)
            value += min((ll)arr[i],mid);
        if(value <= m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout<<high;
    return 0;
}
