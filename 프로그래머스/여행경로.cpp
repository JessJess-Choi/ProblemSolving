#include <string>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<string> answer,tmp;
bool visit[10001];
int n;

bool dfs(string str,vector<vector<string>>& tickets,int cnt){
    tmp.push_back(str);
    if(cnt == tickets.size()){
        answer = tmp;
        return true;
    }
    for(int i=0;i<n;i++){
        if(tickets[i][0] == str && !visit[i]){
            visit[i] = true;
            if(dfs(tickets[i][1],tickets,cnt+1))return true;
            visit[i] = false;
        }
    }
    tmp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());
    n = tickets.size();
    dfs("ICN",tickets,0);
    return answer;
}
