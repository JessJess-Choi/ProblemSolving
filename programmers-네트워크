#include <string>
#include <vector>
#include<queue>

using namespace std;

bool visit[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(!visit[i]){
            queue<int>q;
            answer++;
            q.push(i);
            visit[i] = true;
            while(!q.empty()){
                int vertex = q.front();q.pop();
                for(int j=0;j<n;j++){
                    if(computers[vertex][j] && !visit[j]){
                        visit[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    return answer;
}
