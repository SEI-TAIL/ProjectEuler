#include <iostream>
#include <fstream>
using namespace std;

int in[110][110];
int dp[110][110] = {0};

int main(){
	ifstream cin("input.txt");
	
	int n = 100;
	for(int i=0;i<n;i++)for(int j=0;j<=i;j++)cin >> in[i][j];
	
	dp[0][0] = in[0][0];
	for(int i=0;i<n-1;i++){
		for(int j=0;j<=i;j++){
			dp[i+1][j] >?= dp[i][j] + in[i+1][j];
			dp[i+1][j+1] >?= dp[i][j] + in[i+1][j+1];
		}
	}
	
	int ret = -1;
	for(int i=0;i<n;i++)ret >?= dp[n-1][i];
	
	cout << ret;
	return 0;
}
