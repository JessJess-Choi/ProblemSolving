#include<iostream>
#include<algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;cin>>n;
    int arr1[100001],arr2[100001];
    for(int i=0;i<n;i++)cin>>arr1[i];
    cin>>m;
    for(int i=0;i<m;i++)cin>>arr2[i];
    sort(arr1,arr1+n);
    for(int i=0;i<m;i++)
        cout<<binary_search(arr1,arr1+n,arr2[i])<<'\n';
    return 0;
}
