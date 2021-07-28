#include<iostream>
#include<algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;cin>>n;
    int arr[500001];
    for(int i=0;i<n;i++)cin>>arr[i];
    int m;cin>>m;
    sort(arr,arr+n);
    while(m--){
        int a;cin>>a;
        cout<<upper_bound(arr,arr+n,a) - lower_bound(arr,arr+n,a)<<' ';
    }
    return 0;
}
