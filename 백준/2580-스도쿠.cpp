#include <iostream>
#include <vector>

using namespace std;

int N, arr[10][10];
vector<pair<int,int>> v;

bool check(int x, int y, int n){
    for(int i=0;i<9;i++)
        if(arr[x][i] == n || arr[i][y] == n)
            return false;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(arr[x / 3 * 3 + i][y / 3 * 3 + j] == n)
                return false;
    return true;
}

void dfs(int n){
    if(n == v.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }
        exit(0);
    }
    for(int i=1;i<=9;i++){
        int x = v[n].first;
        int y = v[n].second;
        if(check(x,y,i)){
            arr[x][y] = i;
            dfs(n + 1);
            arr[x][y] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            cin >> arr[i][j];
            if(!arr[i][j])v.push_back({i,j});
        }
    dfs(0);
    
    return 0;
}
