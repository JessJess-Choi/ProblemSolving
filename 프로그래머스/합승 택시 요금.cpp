#include <string>
#include <vector>
#define INF 1e9
using namespace std;
int g[301][301];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    fill(&g[0][0],&g[300][300],INF);
    for(int i=0;i<=n;i++)g[i][i] = 0;
    for(auto a : fares){
        g[a[0]][a[1]] = a[2];
        g[a[1]][a[0]] = a[2];
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(g[i][k]!=INF && g[k][j]!=INF)
                    g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
    answer = g[s][a] + g[s][b];
    for(int i=1;i<=n;i++)
        if(g[s][i]!=INF && g[i][a]!=INF && g[i][b]!=INF)
            answer = min(answer,g[s][i]+g[i][a]+g[i][b]);
    return answer;
}
