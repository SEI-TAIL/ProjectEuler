#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void){
  map<int, string> table;
  table[1] = "one";
  table[2] = "two";
  table[3] = "three";
  table[4] = "four";
  table[5] = "five";
  table[6] = "six";
  table[7] = "seven";
  table[8] = "eight";
  table[9] = "nine";
  table[10] = "ten";
  table[11] = "eleven";
  table[12] = "twelve";
  table[13] = "thirteen";
  table[14] = "fourteen";
  table[15] = "fifteen";
  table[16] = "sixteen";
  table[17] = "seventeen";
  table[18] = "eighteen";
  table[19] = "nineteen";
  table[20] = "twenty";
  table[30] = "thirty";
  table[40] = "forty";
  table[50] = "fifty";
  table[60] = "sixty";
  table[70] = "seventy";
  table[80] = "eighty";
  table[90] = "ninety";
  table[100] = "hundred";
  table[1000] = "thousand";

  int arr[1001] = {0};
  
  //1-20
  for(int i=1; i<=20; i++){
    arr[i] = table[i].size();
  }

  // 21-99
  for(int i=20; i<=90; i+=10){
    int n = table[i].size();
    for(int j=0; j<=9; j++){
      arr[i+j] = n + arr[j];
    }
  }

  // 100-999
  int len100 = table[100].size();
  int len_and = string("and").size();
  for(int i=1; i<=9; i++){
    int len_upper = arr[i] + len100;
    int ix100 = i*100;
    arr[ix100] = len_upper;
    for(int j=1; j<=99; j++){
      arr[ix100+j] = len_upper + len_and + arr[j];
    }
  }

  // 1000
  arr[1000] = arr[1] + table[1000].size();

  // total
  int result = 0;
  for(int i=1; i<=1000; i++){
    result += arr[i];
  }

  cout << result << endl;

  return 0;
}
