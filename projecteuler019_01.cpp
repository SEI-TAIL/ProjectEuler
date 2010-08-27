#include <iostream>
using namespace std;

int days[20];
bool leap(int year){
	if(year % 4)return false;
	if(year % 400 && year % 100 == 0)return false;
	return true;
}
int feb(int year){
	if(leap(year))return 29;
	return 28;
}

int main(){
	for(int i=1;i<=12;i++)days[i] = 31;
	days[9] = days[4] = days[6] = days[11] = 30;
	
	int week = 1;
	int sum = 0;
	for(int i=1;i<=12;i++)if(i==2)sum += feb(1900); else sum += days[i];
	
	week = (week + sum) % 7;
	
	int ret = 0;
	for(int year=1901;year<=2000;year++){
		days[2] = feb(year);
		
		for(int i=1;i<=12;i++){
			if(week == 0)ret++;
			
			week = (week + days[i]) % 7;
		}
	}
	
	cout << ret;
	
	return 0;
}
