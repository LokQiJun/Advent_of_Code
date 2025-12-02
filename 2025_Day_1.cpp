#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
  long a, b, c, count1 = 0, count2 = 0;
  char c1, c2, c3;
  string s1, s2, s3;
  b = 50;
  
  while(cin >> s1) {
    c1 = s1[0];
    a = stoi(s1.substr(1));
    // cout << a << ' ' << a/100 << ' ';
    count2 += a/100;
    a %=100;
    // cout << a << endl;
    if(c1 == 'L') {
      if(b-a < 0 && b!=0) {count2++;}
      b = (b + 100 - a) % 100;
    }
    else if (c1 =='R') {
      if(b+a > 100) {count2++;}
      b = (b + a) % 100;
    }
    
    if(b == 0) count1++;
  }
  
  cout << count1 << ' ' << count2+count1;
  
  return 0;
}
