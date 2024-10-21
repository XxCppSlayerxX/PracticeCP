#include "bits/stdc++.h"
using namespace std;

int main(){
    int q;
    cin >> q;

    while(q){
        q--;
        int a, b;
        cin >> a >> b;

        if(a >= b){ cout << a << endl; continue;}
        int dif;

        dif = (b - a);
        
                
        if(a - dif > 0){
            cout << a - dif << endl;
        }else{
            cout << 0 << endl;
        }
    }

    return 0;
}