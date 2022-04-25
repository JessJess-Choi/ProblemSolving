#include <algorithm>
#include <vector>
using namespace std;

int f(int a,int b,int c){
    int arr[3] = {a,b,c};
    sort(arr,arr+3);
    return arr[2];
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int arr[100001][4];
    arr[0][0] = land[0][0];
    arr[0][1] = land[0][1];
    arr[0][2] = land[0][2];
    arr[0][3] = land[0][3];
    for(int i=1;i<land.size();i++){
        arr[i][0] = land[i][0] + f(arr[i-1][1],arr[i-1][2],arr[i-1][3]);
        arr[i][1] = land[i][1] + f(arr[i-1][0],arr[i-1][2],arr[i-1][3]);
        arr[i][2] = land[i][2] + f(arr[i-1][0],arr[i-1][1],arr[i-1][3]);
        arr[i][3] = land[i][3] + f(arr[i-1][0],arr[i-1][1],arr[i-1][2]);
    }
    for(int i=0;i<4;i++)
        answer = max(arr[land.size()-1][0],f(arr[land.size()-1][1],arr[land.size()-1][2],arr[land.size()-1][3]));
    return answer;
}
