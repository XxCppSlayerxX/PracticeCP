#include <bits/stdc++.h>
using namespace std;

const double pi = 3.141592653589793;

bool comp(vector<double>& a, vector<double>& b){
    if(a[0] == b[0]){
        return a[2] < b[2];
    }else{
        return a[0] < b[0];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n; cin >> t >> n;
    vector<vector<double>> a(n, vector<double>(3));
    double tangente = tan(t*pi/180);
    double x = 0; double h = 0;
    double catetoAdyacente = 0;
    for(int i = 0; i < n; ++i){ // x, altura, cateto adyacente
        cin >> x >> h;
        catetoAdyacente = h / tangente;
        a[i] = {x,h,catetoAdyacente};
    }
    sort(a.begin(), a.end());
    
    double reached = a[0][0];
    
    double notCovered = 0;
    if(reached != 0){
        notCovered += reached;
    }
    double newReach = 0;
    for(int i = 0; i < n; ++i){
        newReach = a[i][0] + a[i][2];
        if(reached < a[i][0]){
            notCovered += a[i][0] - reached;
        }
        
        if(newReach > reached){
            reached = newReach;
        }
    }

    cout << fixed << reached - notCovered << endl;
    return 0;
}