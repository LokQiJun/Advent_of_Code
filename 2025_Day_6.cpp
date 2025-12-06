#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

typedef vector<pair<long, long>> vpll;
typedef vector<long> vl;
typedef vector<string> vs;
typedef vector< vl > vvl;
typedef vector< vs > vvs;

long firstPart();
long secondPart();
bool allSpaceAtIndex(vs v, int idx);

int main(){
  long a, b, c, d, count1=0, count2=0;
  string s1, s2, s3;
  char c1, c2, c3;
  
  vl input, temp;
  vs opera, holder;
  vvl inputs;
  vvl vert_inputs;
  
  // count1 = firstPart();
  count2 = secondPart();
  
  cout << endl << count1 << ' ' << count2;
  
  return 0;
}

long firstPart(){
  long a, b, count1=0;
  string s1;
  
  vl input, temp;
  vs opera;
  vvl inputs;
  
  while(cin >> s1){
    if (s1 == "*" || s1 == "+") break;
    
    input.push_back(stol(s1));
  }
  
  opera.push_back(s1);
  while(cin >> s1){
    opera.push_back(s1);
  }
  
  for(int i = 0; i < opera.size(); i++){
    a=i;
    while(a < input.size()) {
      temp.push_back(input[a]);
      a += opera.size();
    }
    
    inputs.push_back(temp);
    temp.clear();
  }
  
  // cout << opera.size() << ' ' << inputs.size() << ' ' << inputs[0].size() << ' ' << inputs[1].size() << endl;
  
  for(int i = 0; i < opera.size(); i++){
    a=0,b=1;
    if(opera[i] == "*") {
      // cout << "Entered * in: " << i << endl;
      for(auto inp: inputs[i]) b *= inp;
      count1 += b;
    } else if(opera[i] == "+") {
      // cout << "Entered + in: " << i << endl;
      for(auto inp: inputs[i]) a += inp;
      count1 += a;
    } else cout << "Weird output in operator list: " << i << endl;
  }
  
  return count1;
}

long secondPart() {
  long a, b, c, d, count2=0;
  string s1, s2, s3;
  char c1, c2, c3;
  
  vl temp;
  vs opera, holder, input, contain;
  vvs inputs;
  vvl vert_inputs;
  
  while(getline(cin, s1)) {
    if (s1.find('*') != s1.npos) break;
    // cout << s1 << endl;
    input.push_back(s1);
  }
  
  //Split Operators
  stringstream ss(s1);
  while (ss >> s2) {
      opera.push_back(s2);
  }
  // for(auto cha : opera) cout << cha << ' ';
  
  // Find Separating Column
  for(int i = 0; i < input[0].length(); i++){
    if(allSpaceAtIndex(input, i)) temp.push_back(i);
  }
  
  //Split by column found above
  for (auto line : input) {
    a = 0; 

    for (auto idx : temp) {
      if (idx > line.size()) break;
      if (a < idx) 
          holder.push_back(line.substr(a, idx - a)); // add substring before this index
      a = idx + 1; // skip the character at idx
    }
    if (a < line.size())
        holder.push_back(line.substr(a)); //last substr
  }
  for(int i = 0; i < opera.size(); i++){
    a=i;
    while(a < holder.size()) {
      contain.push_back(holder[a]);
      a += opera.size();
    }
    
    inputs.push_back(contain);
    contain.clear();
  }
  cout << inputs.size() << ' ' << holder.size() << ' ' << opera.size() << endl;
  for(auto vecs: inputs){ for(auto str: vecs) cout << '[' << str << "] "; cout << endl;}

  //Format number into up-down and add to vvl
  temp.clear();
  for(int i = 0; i < opera.size(); i++) {
    for(int j = 0; j < inputs[i][0].length(); j++) {
      s2 = "";
      for(int k = 0; k < inputs[i].size(); k++) {
        s2 += inputs[i][k][j];
      }
      temp.push_back(stol(s2));
      cout << stol(s2) << ' ';
    }
    vert_inputs.push_back(temp);
    temp.clear();
  }
  
  for(int i = 0; i < opera.size(); i++){
    a=0,b=1;
    if(opera[i] == "*") {
      // cout << "Entered * in: " << i << endl;
      for(auto inp: vert_inputs[i]) b *= inp;
      count2 += b;
    } else if(opera[i] == "+") {
      // cout << "Entered + in: " << i << endl;
      for(auto inp: vert_inputs[i]) a += inp;
      count2 += a;
    } else cout << "Weird output in operator list: " << i << endl;
  }
  
  return count2;
}

bool allSpaceAtIndex(vs v, int idx) {
    for (const auto &s : v) {
        // if string is too short OR char is not ' ', return false
        if (idx >= s.size() || s[idx] != ' ')
            return false;
    }
    return true;    // all had space
}
