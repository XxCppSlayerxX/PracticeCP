#include <bits/stdc++.h>
using namespace std;

bool comp(vector<float>& a, vector<float>& b) {
    return a[3] < b[3];
}
bool comp2(vector<float> &a, vector<float> &b)
{
    return a[4] < b[4];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int books;
    cin >> books;
    vector<vector<float>> pages(books);

    for(int i = 0; i < books; ++i){
        float pag;
        cin >> pag;
        
        pages[i].push_back(pag);
    }

    for (int i = 0; i < books; ++i)
    {
        float pag;
        cin >> pag;

        pages[i].push_back(pag);
    }

    for (int i = 0; i < books; ++i)
    {
        float pag;
        cin >> pag;

        pages[i].push_back(pag);
    }

    for(int i = 0; i < books; ++i){
        float p;
        float e;
        p = pages[i][0] / pages[i][1];
        e = pages[i][0] / pages[i][2];
        pages[i].push_back(p);
        pages[i].push_back(e);
    }

    //sortear basado en placer y numero
    int placer = 0;

    sort(pages.begin(), pages.end(), comp);

    int min = 0;
    int i = 0;

    while(min <= 480){
        if (i > books)
        {
            break;
        }
        min += pages[i][0] * 3;
        if(min > 480){
            min -= pages[i][0] * 3;
            int tempPages = pages[i][0];
            while (min <= 780){ // tenemos que leer pagina por pagina
                min += 3;
                tempPages--;
            }
            if(tempPages <= 0){
                placer += pages[i][1];
            }
            break;
        }else{
            placer += pages[i][1];
        }
        i++;
    }


    // sortear en enjoyment
    int enjoy = 0;

    sort(pages.begin(), pages.end(), comp2);

    min = 0;
    i = 0;

    while (min <= 480)
    {
        if(i > books){
            break;
        }
        min += pages[i][0] * 3;
        if (min > 480)
        {
            min -= pages[i][0] * 3;
            int tempPages = pages[i][0];
            while (min <= 780)
            { // tenemos que leer pagina por pagina
                min += 3;
                tempPages--;
            }
            if (tempPages <= 0)
            {
                enjoy += pages[i][2];
            }
            break;
        }
        else
        {
            enjoy += pages[i][2];
        }
        i++;
    }

    if(placer > enjoy){
        cout << "PLEASURE" << "\n";
    }else if(enjoy > placer){
        cout << "FAME" << "\n";
    }else{
        cout << "EITHER" << "\n";
    }

    return 0;
}