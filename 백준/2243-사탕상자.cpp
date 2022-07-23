#include <iostream>
#define MAX 1 << 21

using namespace std;

int N, A, B, C, indx = 1 << 20, indexTree[MAX];

void update(int i, int a){
    i += indx - 1;
    indexTree[i] += a;
    while(i >>= 1)
        indexTree[i] = indexTree[i*2] + indexTree[i*2+1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while(N--){
        cin >> A >> B;
        if(A == 1){
            int tmp = 1;
            while(tmp < MAX){
                if(B > indexTree[tmp])B -= indexTree[tmp++];
                tmp <<= 1;
            }
            B = tmp / 2 - indx + 1;
            cout<<B<<"\n";
            C = -1;
        }
        else if(A == 2){
            cin >> C;
        }
        update(B, C);
    }
    return 0;
}
