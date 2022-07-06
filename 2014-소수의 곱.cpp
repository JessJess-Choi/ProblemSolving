#include <iostream>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

int N, K;
ll tmp, now;
priority_queue<ll, vector<ll>, greater<ll>> pq;
vector<ll> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K >> N;
    for(int i=0;i<K;i++){
        cin >> tmp;
        pq.push(tmp);
        v.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        now = pq.top(); pq.pop();
        for(ll l : v){
            ll next = now * l;
            pq.push(next);
            if(now % l == 0)break;
        }
    }
    cout<<now;
    return 0;
}
