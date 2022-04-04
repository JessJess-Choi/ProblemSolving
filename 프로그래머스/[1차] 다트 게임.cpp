#include <string>

using namespace std;

int solution(string dartResult) {
    int first = 0, second = 0, third = 0, index = 0;
    if(dartResult[index] == '1' && dartResult[index + 1] == '0'){
        first = 10;
        index += 2;
    }
    else
        first = dartResult[index++] - '0';
    if(dartResult[index] == 'D')first = first * first;
    else if(dartResult[index] == 'T')first = first * first * first;
    index++;
    if(dartResult[index] < '0' || dartResult[index] > '9'){
        if(dartResult[index] == '*')first *= 2;
        else if(dartResult[index] == '#') first = -first;
        index++;
    }
    if(dartResult[index] == '1' && dartResult[index+1] == '0'){
        index += 2;
        second = 10;
    }
    else
        second = dartResult[index++] - '0';
    if(dartResult[index] == 'D')second = second * second;
    else if(dartResult[index] == 'T')second = second * second * second;
    index++;
    if(dartResult[index] < '0' || dartResult[index] > '9'){
        if(dartResult[index] == '*'){
            first *= 2;
            second *= 2;
        }
        else if(dartResult[index] == '#') second = -second;
        index++;
    }
    if(dartResult[index] == '1' && dartResult[index+1] == '0'){
        third = 10;
        index += 2;
    }
    else
        third = dartResult[index++] - '0';
    if(dartResult[index] == 'D')third = third * third;
    else if(dartResult[index] == 'T')third = third * third * third;
    index++;
    if(dartResult[index] < '0' || dartResult[index] > '9'){
        if(dartResult[index] == '*'){
            third *= 2;
            second *= 2;
        }
        else if(dartResult[index] == '#') third = -third;
        index++;
    }
    return first + second + third;
}
