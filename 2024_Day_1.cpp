#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
  vector<int> vi_1, vi_2;
  int a, b, c, d, e, f;
  char c1, c2, c3;
  string s1, s2, s3;
  map<int, int> mii;
  
  //Part 1
  while(cin>> a){
    cin >> b;
    vi_1.push_back(a);
    vi_2.push_back(b);
  }
  
  sort(vi_1.begin(), vi_1.end());
  sort(vi_2.begin(), vi_2.end());
  
  d=0;
  for(int i = 0; i < vi_2.size(); i++){
    d += abs(vi_2[i] - vi_1[i]);
  }
  
  cout << d << endl;
  
  //Part 2
  d=0;
  for(int i = 0; i < vi_2.size(); i++){
    mii[vi_2[i]]++;
  }
  for(int i = 0; i < vi_1.size(); i++){
    d += mii[vi_1[i]] * vi_1[i];
  }
  
  cout << d;
  
  return 0;
}
