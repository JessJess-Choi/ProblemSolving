#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int arr[100001],n,m;
bool f(int mid){
    int money = 0,cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > mid)return false;
        if(money - arr[i] < 0){
            money = mid;
            cnt++;
        }
        money -= arr[i];
    }
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    int low=0,high=1e9;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    while(low <= high){
        int mid = (low + high) / 2;
        if(f(mid))high = mid - 1;
        else
            low = mid + 1;
    }
    cout<<low;
    return 0;
}
