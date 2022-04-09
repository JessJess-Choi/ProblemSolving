#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int,int>> q;
    int sum = 0, time = 0;
    for(int n : truck_weights){
        time++;
        if(time == q.front().second + bridge_length){
            sum -= q.front().first;
            q.pop();
        }
        while(sum + n > weight){
            time = q.front().second + bridge_length;
            sum -= q.front().first;
            q.pop();
        }
        sum += n;
        q.push({n,time});
    }
    return q.back().second + bridge_length;
}
