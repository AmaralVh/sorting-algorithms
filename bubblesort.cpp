#include <iostream>
#include <vector>

using namespace std;


void bubblesort(vector<int> &vetor) {
    int n = vetor.size();

    bool trocou;

    for(int i = 0; i < n-1; i++) {
        trocou = false;
        for(int j = 0; j < n-1-i; j++) {
            if(vetor[j] > vetor[j+1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux; 

                trocou = true;
            }
        }

        if(!trocou) {
            break;
        }
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
    int n = 0;
    vector<int> vetor;

    cin >> n;

    int numero = 0;

    vetor.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    bubblesort(vetor);

    printa_vetor(vetor);

    return 0;
}