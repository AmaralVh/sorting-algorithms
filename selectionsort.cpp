#include <iostream>
#include <vector>

using namespace std;


void troca(vector<int> &vetor, int i, int j) {
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}


void selectionsort(vector<int> &vetor) {
    int n = vetor.size();

    for(int i = 0; i < n-1; i++) {
        int min = vetor[i];
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(vetor[j] < min) {
                min = vetor[j];
                minIndex = j;
            }
        }
        troca(vetor, i, minIndex);
    }
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

    selectionsort(vetor);

    printa_vetor(vetor);

    return 0;
}