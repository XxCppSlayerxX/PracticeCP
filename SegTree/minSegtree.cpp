// suboptimal implementation of a segment tree that supports point updates and range queries is below, easier tho

#include "bits/stdc++.h"
using namespace std;

struct segtree{

    int size;
    vector<long long> values;

    void init(int n){
        size = 1;
        while(size < n) size *= 2; // so we have a power of 2
        values.assign(2*size, 0LL); // initialize the values vector with 0
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){ 
            values[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2*x+1, lx, m); 
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        values[x] = min(values[2*x+1], values[2*x+2]);
    }
    

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    // in this case fn is the sum of the elements in the range [l, r)
    long long fn(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) return LLONG_MAX; // return neutral element
        if(lx >= l && rx <= r) return values[x]; // if the range is inside the query range 
        
        int m = (lx + rx) / 2;
        long long s1 = fn(l, r, 2*x+1, lx, m);
        long long s2 = fn(l, r, 2*x+2, m, rx);
        return min(s1, s2);
    }

    long long fn(int l, int r){
        return fn(l, r, 0, 0, size);
    }

    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()){
                values[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        values[x] = min(values[2*x+1], values[2*x+2]);
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
            int i, v; cin >> i >> v;
            st.set(i, v);
        }else{
            int l, r; cin >> l >> r;
            cout << st.fn(l, r) << endl;
        }
    }
    cout << endl;


    return 0;
}







/*
#include "bits/stdc++.h"
using namespace std;

struct segtree{

    int size;
    vector<long long> values;

    void init(int n){
        size = 1;
        while(size < n) size *= 2; // so we have a power of 2
        values.assign(2*size, 0LL); // initialize the values vector with 0
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){ 
            values[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2*x+1, lx, m); 
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        values[x] = min(values[2*x+1], values[2*x+2]);
    }
    

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    // in this case fn is the sum of the elements in the range [l, r)
    long long fn(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) return LLONG_MAX; // return neutral element
        if(lx >= l && rx <= r) return values[x]; // if the range is inside the query range 
        
        int m = (lx + rx) / 2;
        long long s1 = fn(l, r, 2*x+1, lx, m);
        long long s2 = fn(l, r, 2*x+2, m, rx);
        return min(s1, s2);
    }

    long long fn(int l, int r){
        return fn(l, r, 0, 0, size);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    segtree st;
    st.init(n);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        st.set(i, v);
    }

    while(m--){
        int op; cin >> op;
        if(op == 1){
            int i, v; cin >> i >> v;
            st.set(i, v);
        }else{
            int l, r; cin >> l >> r;
            cout << st.fn(l, r) << endl;
        }
    }
    cout << endl;


    return 0;
}
*/