#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,d; cin >> t;
    while(t--) {
        cin >> n >> d;

        cout << "1 ";

        if (n > 2 || d % 3 == 0) 
            cout << "3 ";

        if (d == 5) 
            cout << "5 ";

        if (n > 2 || d == 7) 
            cout << "7 ";

        if ((d == 9) || (n > 2 && d % 3 == 0) || n >= 6) 
            cout << "9 ";

        cout << endl;
    }

    return 0;
}