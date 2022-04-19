#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);
    bool check = false;
    for(auto a : arr)
        for(auto b : a)
            if(b != arr[0][0]){
                check = true;
                break;
            }
    if(check){
        vector<vector<int>> v1;
        vector<vector<int>> v2;
        vector<vector<int>> v3;
        vector<vector<int>> v4;
        vector<int> tmp;
        for(int i=0;i<arr.size()/2;i++){
            vector<int> v;
            for(int j=0;j<arr.size()/2;j++)
                v.push_back(arr[i][j]);
            v1.push_back(v);
        }
        for(int i=arr.size()/2;i<arr.size();i++){
            vector<int> v;
            for(int j=0;j<arr.size()/2;j++)
                v.push_back(arr[i][j]);
            v2.push_back(v);
        }
        for(int i=0;i<arr.size()/2;i++){
            vector<int> v;
            for(int j=arr.size()/2;j<arr.size();j++)
                v.push_back(arr[i][j]);
            v3.push_back(v);
        }
        for(int i=arr.size()/2;i<arr.size();i++){
            vector<int> v;
            for(int j=arr.size()/2;j<arr.size();j++)
                v.push_back(arr[i][j]);
            v4.push_back(v);
        }
        tmp = solution(v1);
        answer[0] += tmp[0];
        answer[1] += tmp[1];
        tmp = solution(v2);
        answer[0] += tmp[0];
        answer[1] += tmp[1];
        tmp = solution(v3);
        answer[0] += tmp[0];
        answer[1] += tmp[1];
        tmp = solution(v4);
        answer[0] += tmp[0];
        answer[1] += tmp[1];
    }
    else
        answer[arr[0][0]]++;
    return answer;
}
