#include <string>
#include <vector>
#include<algorithm>
#define MAX 10000001

using namespace std;

bool arr[MAX];

int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    arr[0] = arr[1] = true;
    for(int i=2;i*i<MAX;i++){
        if(arr[i])continue;
        for(int j=i*i;j<MAX;j+=i)
            arr[j] = true;
    }
    sort(numbers.begin(),numbers.end());
    do{
        string str;
        for(int i=0;i<numbers.size();i++){
            str += numbers[i];
            v.push_back(stoi(str));
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    
//    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    
    for(int i=0;i<v.size();i++)if(!arr[v[i]])answer++;
    return answer;
}
