#include <iostream>

using namespace std;

int T, C, K;

void EEA(int a, int b) {
	int s0 = 1, s1 = 0, t0 = 0, t1 = 1;
    while(b){
        int q = a/b, r = a%b;
        a = b;
        b = r;
        int s = s0 - q*s1;
        int t = t0 - q*t1;
        s0 = s1;
        s1 = s;
        t0 = t1;
        t1 = t;
    }
    t0 = (t0 % K + K) % K;
    if(a != 1 || t0 > 1e9)cout<<"IMPOSSIBLE\n";
    else cout<<t0<<"\n";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> K >> C;
        if(C == 1){
            if(K + 1 > 1e9)cout<<"IMPOSSIBLE\n";
            else cout<<K+1<<"\n";
        }
        else if(K == 1)
            cout<<"1\n";
        else
            EEA(K,C);
    }
    return 0;
}
