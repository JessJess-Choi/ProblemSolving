#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int g[20001][20001];
int visit[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0,maxValue = 0;
    queue<int> q;
    for(auto a : edge)g[a[0]][a[1]] = g[a[1]][a[0]] = 1;
    q.push(1);
    visit[1] = 1;
    while(!q.empty()){
        int vertex = q.front();q.pop();
        for(int i=1;i<=n;i++)
            if(g[vertex][i] && !visit[i]){
                visit[i] = visit[vertex] + 1;
                q.push(i);
            }
    }
    for(int i=1;i<=n;i++)maxValue = max(maxValue,visit[i]);
    for(int i=1;i<=n;i++)if(maxValue == visit[i])answer++;
    return answer;
}
