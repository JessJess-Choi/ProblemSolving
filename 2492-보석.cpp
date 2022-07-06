#include <iostream>
#include <vector>

using namespace std;

int N, M, T, K, X, Y, t1, t2, ans;
vector<pair<int,int>> v;

int f(int x, int y){
    int ret = 0;
    for(auto a : v)
        if(x <= a.first && y <= a.second && a.first <= x + K && a.second <= y + K)
            ret++;
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> T >> K;
    for(int i=0;i<T;i++){
        cin >> t1 >> t2;
        v.push_back({t1, t2});
    }
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            int x, y;
            if(v[i].first + K > N)x = N - K;
            else
                x = v[i].first;
            if(v[j].second + K > M)y = M - K;
            else
                y = v[j].second;
            int n = f(x,y);
            if(n > ans){
                ans = n;
                X = x;
                Y = y + K;
            }
        }
    }
    cout<<X<<" "<<Y<<"\n"<<ans;
    return 0;
}
