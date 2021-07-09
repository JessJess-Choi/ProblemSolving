#include <string>
#include <vector>
#include<map>
#include<queue>

using namespace std;

bool g[100][100];
int visit[100];

bool compareString(string str1,string str2){
    bool ret = false;
    for(int i=0;i<str1.size();i++)
        if(str1[i] != str2[i]){
            if(ret)return false;
            else
                ret = true;
        }
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int index = 0,n = words.size();
    map<string,int> m;
    queue<int> q;
    
    for(auto a : words)m[a] = ++index;
    for(int i=0;i<words.size();i++)
        for(int j=i+1;j<words.size();j++)
            if(compareString(words[i],words[j]))
                g[m[words[i]]][m[words[j]]] = g[m[words[j]]][m[words[i]]] = true;

    for(int i=0;i<words.size();i++)
        if(compareString(words[i],begin)){
            begin = words[i];
            break;
        }
    q.push(m[begin]);
    visit[m[begin]] = 1;
    while(!q.empty()){
        int vertex = q.front();q.pop();
        for(int i=1;i<=n;i++)
            if(g[vertex][i] && !visit[i]){
                visit[i] = visit[vertex] + 1;
                q.push(i);
            }
    }
    return visit[m[target]];
}
