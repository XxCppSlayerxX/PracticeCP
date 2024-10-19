#include <bits/stdc++.h>
using namespace std;



int main()
{
    int N, M, O;
    cin >> N >> M >> O;

    vector<int> cantIngre(N); // Cantidad de ingredientes por cada N ingredientes
    for (int i = 0; i < N; i++)
    { // Guardar cantidad de ingredientes
        int qi;
        cin >> qi;
        cantIngre[i] = qi;
    }

    // for (int i = 0; i < N; i++)
    // { // Guardar cantidad de ingredientes
    //     cout << cantIngre[i] << "\n";
    // }

    vector<vector<pair<int, int>>> Menu(M); // Menu que tiene ingrediente N y cantidad necesaria
    for (int i = 0; i < M; i++)
    { // Guardar platillos
        int mi;
        cin >> mi;
        for (int j = 0; j < mi; j++)
        { // Guarda ingredientes por platillos
            int Ii, Qmi;
            cin >> Ii >> Qmi;
            Menu[i].push_back({Ii, Qmi});
        }
    }

    // for (int i = 0; i < M; i++)
    // { // Guardar cantidad de ingredientes
    //     for (int j = 0; j < Menu[i].size(); j++)
    //     { // Guardar cantidad de ingredientes
    //         cout << Menu[i][j].first << " " << Menu[i][j].second << "\n";
    //     }
    // }

    queue<queue<int>> Ordenes;
    queue<int> Platillo;
    vector<int> cantPlatillos;
    // vector<vector<int>> Ordernes(O); // Pedido que tiene orden que tiene platillos
    for (int i = 0; i < O; i++)
    { // Guardar cantidad de platillos en la orden n
        int oi;
        cin >> oi;
        // cout << "muere?" << "\n";
        for (int j = 0; j < oi; j++)
        { // Guardar platillos de la orden n
            int di;
            cin >> di;
            Platillo.push(di);
            
            // cout << Platillo.front() << "\n";
        }
        Ordenes.push(Platillo);
        while(!Platillo.empty()){
            Platillo.pop();
        }
    }

    // cout << "antes ciclo" << "\n";
    // cout << Menu[(Ordenes.front().front())].size() << "x\n";
    int totalOrdenes = 0;
    int ingrediente_valido = true;
    for(int i = 0; i < O; ++i){ // ordenes
        queue<int> query = Ordenes.front();
        int querySize = query.size();
        for (int j = 0; j < querySize; j++) { // platillo
            int noPlatillo = query.front();
            int noIngredientes = Menu[noPlatillo - 1].size();
            //guardar copia del inventario
            for (int k = 0; k < noIngredientes; k++) {
                // cout << "k " << k << "\n";
                int ingrediente = Menu[noPlatillo - 1][k].first; // tipo de ingrediente 
                int cantidadIngrediente = Menu[noPlatillo - 1][k].second; // cantidad ingrediente x platillo
                if (cantIngre[ingrediente - 1] - cantidadIngrediente >= 0) { // inventario - necesarios vaido
                    cantIngre[ingrediente - 1] -= cantidadIngrediente; // ingrediente valido
                } else {
                    // ingrediente invalido
                    ingrediente_valido = false;
                    break;
                }
            }
            if (!ingrediente_valido) {
                // cantIngre = tempN;
                break;
            }
            if (querySize - j == 1) {
                totalOrdenes++;
            }
            query.pop();
        }
        if (!ingrediente_valido)
        {
            // cantIngre = tempN;
            break;
        }
        Ordenes.pop();
    }

    // totalOrdenes = O - Ordenes.size();
    cout << totalOrdenes << "\n";
    return 0;
}