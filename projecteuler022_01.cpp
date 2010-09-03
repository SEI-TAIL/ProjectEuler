#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
	ifstream cin("names.txt");
	vector<string> names;
	
	string in, tmp, name;
	cin >> in;
	
	for(int i=0;i<in.size();i++){
		if(in[i]=='"')continue;
		if(in[i]==',')tmp += ' '; else tmp += in[i];
	}
	
	stringstream ss(tmp);
	while(ss >> name)names.push_back(name);
	
	sort(names.begin(),names.end());
	
	int sum = 0;
	for(int i=0;i<names.size();i++){
		int score = 0;
		for(int j=0;j<names[i].size();j++)score += names[i][j]-'A' + 1;
		sum += score * (i + 1);
	}
	
	cout << sum << endl;
	return 0;
}
