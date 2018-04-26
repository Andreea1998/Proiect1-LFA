#include <cstring>
using namespace std;

void citirematrice(char v[100][100][100], int &p) {
	ifstream f("fisier.in");
	int x, y;
	int i, j;
	int n;
	char w;
	f >> p;
	for (i = 0; i < p; i++)
		for (j = 0; j < p; j++)
			v[i][j][0] = '\0';
	while (f >> x >> y >> w){
        n=strlen(v[x][y]);
        v[x][y][n] = w;
        v[x][y][n+1]='\0';
	}
}

void afismatrice(char v[100][100][100], int p) {
	int i, j;
	for (i = 0; i < p; i++) {
		for (j = 0; j < p; j++)
            if(v[i][j][0]=='\0')
                cout<<0<<" ";
			else cout << v[i][j] << " ";
		cout << endl;
	}
}

bool cautare(int starif[50], int j, int m) {
	int nr;
	for (nr = 1; nr <= m; nr++)
		if (j == starif[nr]) return true;
	return false;
}

bool cautare_litera(char c[21],char l){
    int i;
    int n=strlen(c);
    for(i=0;i<n;i++)
        if(c[i]==l) return 1;
    return 0;
}

void AFN(char v[100][100][100], char cuv[21], int starif[50], int poz, int m, int p, int i, int &k) {
	int j;
	if (cuv[i] != NULL) {
		for (j = 0; j < p; j++)
			if (cautare_litera(v[poz][j],cuv[i])==1) {
				if (cautare(starif, j, m) && cuv[i + 1] == NULL) {
					k = 1;
					return;
				}
				else AFN(v, cuv, starif, j, m, p, i + 1, k);
			}
		if (k == 0 && j == p) {
			k = -1;
			return;
		}
	}
}

int main() {
	char cuv[21], v[100][100][100];
	int nr, i, c, j, m, p, k, starif[50];
	citirematrice(v, p);
	afismatrice(v, p);
	cout << "Dati cuvantul:" << " ";
	cin.get(cuv, 21);
	cout << "Dati numarul de stari finale:" << " ";
	cin >> m;
	for (nr = 1; nr <= m; nr++) {
		cout << "Stare finala" << nr << ":";
		cin >> starif[nr];
	}
	k = 0;
	AFN(v, cuv, starif, 0, m, p, 0, k);
	if (k == 1) cout << "Este cuvant";
	else cout << "Nu este cuvant";
return 0;
}
