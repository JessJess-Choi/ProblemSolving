#include <string>
#include <vector>

using namespace std;

int get_distance(int a,int b){
    if(a == b)return 0;
    if(b == '*' || b == '#'){
        if(a == 0)return 1;
        else if(a == 8)return 2;
        else if(a == 5)return 3;
        else if(a == 2)return 4;
    }
    if(a == 0){
        if(b == 1 || b == 3)return 4;
        else if(b == 2 || b == 4 || b == 6)return 3;
        else if(b == 5 || b == 7 || b == 9)return 2;
        else if(b == 8)return 1;
    }
    else if(a == 2){
        if(b == 0 || b == 7 || b == 9)return 3;
        else if(b == 4 || b == 6 || b == 8)return 2;
        else if(b == 1 || b == 3 || b == 5)return 1;
    }
    else if(a == 5){
        if(b == 2 || b == 4 || b == 6 || b == 8)return 1;
        else if(b == 1 || b == 3 || b == 7 || b == 9 || b == 0)return 2;
    }
    else if(a == 8){
        if(b == 5 || b == 7 || b == 9 || b == 0)return 1;
        else if(b == 2 || b == 4 || b == 6)return 2;
        else if(b == 1 || b == 3)return 3;
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int right_now = '#', left_now = '*';
    for(int a : numbers){
        if(a % 3 == 1){
            answer += 'L';
            left_now = a;
        }
        else if(a % 3 == 0 && a){
            answer += 'R';
            right_now = a;
        }
        else{
            int right_distance = get_distance(a,right_now);
            int left_distance = get_distance(a,left_now);
            if(right_distance > left_distance){
                left_now = a;
                answer += 'L';
            }
            else if(right_distance < left_distance){
                right_now = a;
                answer += 'R';
            }
            else{
                if(hand == "right"){
                    right_now = a;
                    answer += 'R';
                }
                else{
                    left_now = a;
                    answer += 'L';
                }
            }
        }
    }
    return answer;
}
