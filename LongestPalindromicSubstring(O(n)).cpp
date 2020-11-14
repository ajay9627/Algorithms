#include<bits/stdc++.h>
using namespace std;

int longestPalindromicSubstring(string s) {
  vector<int> p(s.length(), 0);
  int C = 0, R = 0, mirr;

  for(int i = 1; i < s.length(); i++) {
      
      mirr = 2 * C  - i;

      if(i < R)
          p[i] = min(R - i, p[mirr]);

      while(i - (1 + p[i]) >=0 && (i + 1 + p[i]) < s.length() && s[i + (1 + p[i])] == s[i - (1 + p[i])]) {
          p[i]++;
      }

      if(i + p[i] > R){
          C = i;
          R  = i + p[i];
      }
  }
  int ans = 1;
  for(int i = 0 ; i < s.length(); i++) {
    ans = max(ans, p[i]);
  }
  return ans;
}


int main() {
  string s = "";
  cout << "Enter the string :";
  cin >> s;

  string str = "#";
  for(int i = 0; i < s.length(); i++) {
    str += s[i];
    str += "#";
  }
  int ans = longestPalindromicSubstring(str);
  cout<<"The Length of longest palindromic Substring :" << ans;
  return 0;
}
