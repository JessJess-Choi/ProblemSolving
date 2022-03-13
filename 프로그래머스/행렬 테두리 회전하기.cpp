#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int g[101][101];
    for(int i=0;i<rows;i++)
        for(int j=0;j<columns;j++)
            g[i][j] = i * columns + j + 1;
    for(auto a : queries){
        int x1 = a[0] - 1, y1 = a[1] - 1, x2 = a[2] - 1, y2 = a[3] - 1;
        int ans = 1e7, tmp = g[x1][y2];
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                if(i == x1 || i == x2 || j == y1 || j == y2)
                    ans = min(ans, g[i][j]);
        answer.push_back(ans);
        for(int i=y2;i>y1;i--)g[x1][i] = g[x1][i - 1];
        for(int i=x1;i<x2;i++)g[i][y1] = g[i + 1][y1];
        for(int i=y1;i<y2;i++)g[x2][i] = g[x2][i + 1];
        for(int i=x2;i>x1;i--)g[i][y2] = g[i - 1][y2];
        g[x1 + 1][y2] = tmp;
    }
    return answer;
}
