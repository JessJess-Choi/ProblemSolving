#include <iostream>

using namespace std;

int N, col[16], ans;

bool check(int n){
    for(int i=0;i<n;i++)
        if(col[i] == col[n] || abs(i - n) == abs(col[i] - col[n]))
            return false;
    return true;
}

void nqueen(int n){
    if(n == N)ans++;
    else{
        for(int i=0;i<N;i++){
            col[n] = i;
            if(check(n))
                nqueen(n + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    nqueen(0);
    cout<<ans;
    return 0;
}
