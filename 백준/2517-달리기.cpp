#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define P pair<int,int>

using namespace std;

int N, indx = 1, indxTree[1024 * 1024], tmp;
vector<P> v;
ll arr[500001];

void update(int i, ll a){
    i += indx - 1;
    indxTree[i] = a;
    while(i >>= 1)
        indxTree[i] = indxTree[i*2] + indxTree[i*2+1];
}

ll sum(int ia, int ib){
    ia += indx - 1;
    ib += indx - 1;
    ll ret = 0;
    while(ia <= ib){
        if(ia & 1)ret += indxTree[ia];
        if(!(ib & 1))ret += indxTree[ib];
        ia = (ia + 1) >> 1;
        ib = (ib - 1) >> 1;
    }
    return ret;
}

bool cmp1(P a, P b){
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        v.push_back({tmp,i+1});
    }
    sort(v.begin(),v.end(),cmp1);
    while(indx < N)indx <<= 1;
    for(int i=0;i<N;i++){
        update(v[i].second,1);
        arr[v[i].second] = sum(1,v[i].second);
    }
    for(int i=1;i<=N;i++)cout<<arr[i]<<"\n";
    return 0;
}
