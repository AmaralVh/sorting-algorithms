#include <iostream>
#include <vector>

using namespace std;


void troca(vector<int> &vetor, int i, int j) {
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}


void divide(vector<int> &vetor, int inicio, int fim) {
    if(inicio >= fim) {
        return;
    }

    int pivo = inicio;
    int i = inicio;
    int j = i+1;

    while(j <= fim) {
        if(vetor[j] < vetor[pivo]) {
            i++;
            troca(vetor, i, j);
        }
        j++;
    }

    troca(vetor, i, pivo);
    pivo = i;

    // Neste ponto, ja ordenamos de acordo com o pivo, agora chamamos a recursao:

    divide(vetor, inicio, pivo);
    divide(vetor, pivo+1, fim);
}


void quicksort(vector<int> &vetor) {
    int n = vetor.size();

    divide(vetor, 0, n-1);
}


void printa_vetor(vector<int> vetor) {
    int n = vetor.size();

    for(int i = 0; i < n; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
 }


int main() {
    int n;
    vector<int> vetor;

    cin >> n;

    vetor.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    quicksort(vetor);

    printa_vetor(vetor);

    return 0;
}