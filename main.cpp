#include <iostream>
#include <fstream>
using namespace std;

struct vector{
    char litera, stare1, stare2;
};

bool stare_lamda (char stare, vector v[100], int n){
    int i;
    if (stare=='0')
        return 1;
    for (i=0; i<n; i++)
        if (v[i].stare1==stare && v[i].litera=='0')
            return 1;
    return 0;
}

void repetitie(vector v[100], char stare, char cuv[21], int &j, int &ok, int n){
    if(ok==0 && cuv[j]!=NULL && stare!='0'){
        int i;
        for(i=0;i<n; i++)
            if(v[i].stare1==stare && cuv[j]==v[i].litera)
                j++, repetitie(v, v[i].stare2, cuv, j, ok, n);
    }
    else
    if (cuv[j]==NULL && stare_lamda(stare, v, n)==1)
        ok=1;

}

void functie( vector v[100], char cuv[21]){
    ifstream fin("fisier.in");
    int n,i;
    char x,y,z;
    fin>>n;
    for(i=0;i<n;i++){
        fin>>x>>y>>z;
        v[i].litera=x;
        v[i].stare1=y;
        v[i].stare2=z;
    }
    int j, stare_initiala;
    j=0;
    int ok=0;
    stare_initiala=v[0].stare1;
    repetitie(v,stare_initiala, cuv, j, ok, n);
    if (ok==1)
        cout<<"E cuvant";
    else cout<<"Nu";
}

int main() {
    char cuv[21];
    vector v[100];
    cout << "Dati cuvantul:" << " ";
    cin.get(cuv, 21);
    functie(v,cuv);
    return 0;
}
