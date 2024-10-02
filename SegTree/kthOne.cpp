#include "bits/stdc++.h"
using namespace std;

struct node{
    long long c;
};

struct segtree{

    int size;
    vector<node> values;

    node NEUTRAL = {0};

    node merge(node a, node b){
        return {a.c + b.c};
    }

    node single(int v){
        return {v};
    }

    void init(int n){
        size = 1;
        while(size < n) size *= 2; // so we have a power of 2
        values.resize(2 * size); // initialize the values vector with 0
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){ 
            values[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2*x+1, lx, m); 
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }
    

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    node fn(int k, int x, int lx, int rx){
        if(rx - lx == 1) return {lx};
        int m = (lx + rx) / 2;
        if(values[2*x+1].c > k){
            return fn(k, 2*x+1, lx, m); // go to the left child and no need to subtract the value
        }else{
            return fn(k - values[2*x+1].c, 2*x+2, m, rx);
        }
    }

    node fn(int k){
        return fn(k, 0, 0, size);
    }

    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()){
                values[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }

    void build(vector<int> &a){
        build(a, 0, 0, size);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    segtree st;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    st.build(a);
    while(m--){
            int op; cin >> op;
            if(op == 1){
                int i; cin >> i;
                a[i] = 1 - a[i];
                st.set(i, a[i]);
            }else{
                int k; cin >> k;
                cout << st.fn(k).c << endl;
            }
            
        }
    cout << endl;

    return 0;
}
 
