#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    string ans = s;
    int n = s.size();

    for (int i = n - 1; i >= 1; --i) {
        if (s[i] == '0')
            continue; // No podemos elegir '0'
        char decreased_digit = s[i] - 1;

        // Intentamos mover el dígito a todas las posiciones a su izquierda
        for (int j = 0; j < i; ++j) {
            // Creamos una copia de la cadena original
            string temp = s;

            // Eliminamos el dígito de la posición i
            temp.erase(temp.begin() + i);

            // Insertamos el dígito disminuido en la posición j
            temp.insert(temp.begin() + j, decreased_digit);

            // Compararmos y actualizamos si es necesario
            if (temp > ans) {
                ans = temp;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}