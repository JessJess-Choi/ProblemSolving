#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> pq;
    int answer = 0;
    for(auto a : scoville)pq.push(a);
    while(pq.top() < K){
        if(pq.size()==1 && pq.top()<K)return -1;
        int first,second;
        first = pq.top();pq.pop();
        second = pq.top();pq.pop();
        pq.push(first+second*2);
        answer++;
    }
    return answer;
}
