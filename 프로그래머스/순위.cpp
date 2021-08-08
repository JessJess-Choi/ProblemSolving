#include <vector>

using namespace std;

int g[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(auto a : results)g[a[0]][a[1]] = 1;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            for (int k = 1; k <= n; k++) 
                if (g[j][i] && g[i][k]) 
                    g[j][k] = true;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (g[i][j] || g[j][i]) count++;
        }
        if (count == n - 1) answer++;
    }
    return answer;
}
