#include <iostream>
#include <queue>

using namespace std;

int N, tmp;
priority_queue<int, vector<int>, greater<int>> pqMin;
priority_queue<int, vector<int>, less<int>> pqMax;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while(N--){
        cin >> tmp;
        if(pqMax.size() > pqMin.size())pqMin.push(tmp);
        else
            pqMax.push(tmp);
        if(!pqMax.empty() && !pqMin.empty()){
            if(pqMax.top() > pqMin.top()){
                int min = pqMin.top(); pqMin.pop();
                int max = pqMax.top(); pqMax.pop();
                pqMin.push(max);
                pqMax.push(min);
            }
        }
        cout<<pqMax.top()<<"\n";
    }
    return 0;
}
