#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    unordered_set<char> setS(s.begin(), s.end());
    cout << s.size() - setS.size() << endl;
}