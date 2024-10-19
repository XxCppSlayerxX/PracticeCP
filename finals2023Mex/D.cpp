#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n, m;
    cin >> n;

    string wordD;  
    cin >> wordD;

    vector<string> a(n - 1);  
    unordered_map<char, int> validL;  

    int j = 0;
    for (auto c : wordD) {
        validL[c] = j; 
        j++;
    }

    for (int i = 0; i < n - 1; ++i) {
        string temp;
        cin >> temp;
        a[i] = temp;
    }

    cin >> m;
    vector<string> chars(m);  
    for (int i = 0; i < m; ++i) {
        cin >> chars[i];  
    }

    for (int k = 0; k < m; ++k) {
        int ans = 0;  
        if(chars[k] == "*****"){
            ans++;
            cout << ans << endl;
            continue;
        }
        for (int l = 0; l < a.size(); ++l) {
            
            string word = a[l];  
            bool isValid = true;
             

            for (int i = 0; i < 5; ++i) {
                char currentChar = word[i];  

                if (chars[k][i] == '*') {  
                    if (validL.find(currentChar) == validL.end() || validL[currentChar] != i) { 
                        isValid = false;
                        break;
                    }
                }
                else if (chars[k][i] == 'X') {  
                    if (validL.find(currentChar) != validL.end()) {  
                        isValid = false;
                        break;
                    }
                }
                else if (chars[k][i] == '!') { 
                    if (validL.find(currentChar) == validL.end() || validL[currentChar] == i) {
                        isValid = false;
                        break;
                    }
                }
            }

            if (isValid) {  
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
