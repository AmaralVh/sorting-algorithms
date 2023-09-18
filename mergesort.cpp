#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int> &vetor, vector<int> &vetorAux, int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio+1;
    int k = inicio;

    while((i <= meio) && (j <= fim)) {
        if(vetor[i] <= vetor[j]) {
            vetorAux[k] = vetor[i];
            i++;
        }
        else {
            vetorAux[k] = vetor[j];
            j++;
        }
        k++;
    }

    while(i <= meio) {
        vetorAux[k] = vetor[i];
        i++;
        k++;
    }

    while(j <= fim) {
        vetorAux[k] = vetor[j];
        j++;
        k++;
    }

    for(int m = inicio; m <= fim; m++) {
        vetor[m] = vetorAux[m];
    }
}


void divide(vector<int> &vetor, vector<int> &vetorAuxiliar, int inicio, int fim) {
    if(inicio < fim) {
        int meio = (inicio + fim) / 2;

        // cout << inicio << " " << meio << " " << fim << endl;

        divide(vetor, vetorAuxiliar, inicio, meio);
        divide(vetor, vetorAuxiliar, meio+1, fim);

        merge(vetor, vetorAuxiliar, inicio, meio, fim);
    }
}


void mergesort(vector<int> &vetor) {
    int n = vetor.size();

    vector<int> vetorAuxiliar;
    vetorAuxiliar.resize(n);

    divide(vetor, vetorAuxiliar, 0, n-1);
}


void printa_vetor(vector<int> vetor) {
    int n = vetor.size();

    for(int i = 0; i < n; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
 }


int main() {
    int n = 0;
    vector<int> vetor;

    cin >> n;

    int numero = 0;

    vetor.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    mergesort(vetor);

    printa_vetor(vetor);

    return 0;
}