#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i=1;i<n;i++){
        int sum = i, j = i+1;
        while(true){
            sum += j++;
            if(sum == n)answer++;
            if(sum >= n)break;
        }
    }
    return answer;
}
