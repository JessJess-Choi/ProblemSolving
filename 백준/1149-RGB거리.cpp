#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int N,R,G,B,check,tmp;
	cin >> N;
	int arr[3][N];
	cin >> arr[0][0] >> arr[1][0] >> arr[2][0];
	for(int i=1;i<N;i++){
		cin >> R >> G >> B;
		arr[0][i] = R + min(arr[1][i-1],arr[2][i-1]);
		arr[1][i] = G + min(arr[0][i-1],arr[2][i-1]);
		arr[2][i] = B + min(arr[0][i-1],arr[1][i-1]);
	}
	check = arr[0][N-1];
	tmp = min(arr[1][N-1],arr[2][N-1]);
	cout << min(check,tmp);
	return 0;
}
