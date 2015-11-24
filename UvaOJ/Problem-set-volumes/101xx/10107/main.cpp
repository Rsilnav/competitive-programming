#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    vector<int> numeros;
    long int numLeido ,mediana;
    string result = "";
    cin >> numLeido;
    numeros.push_back(numLeido);
    cout << numLeido<< endl;
    int derecha, izquierda, medio, tam=1,pos;
    while(cin >> numLeido){
        izquierda = 0;
        derecha = numeros.size();
        while(true){
            if(numLeido <= numeros[0]){
                numeros.insert(numeros.begin(),numLeido);
                break;
            }
            else if(numLeido >= numeros[numeros.size()-1]){
                numeros.insert(numeros.end(),numLeido);
                break;
            }
            else{
                medio = (derecha + izquierda)/2;
                if( numLeido >= numeros[medio]){
                    if(numLeido <= numeros[medio+1]){
                        numeros.insert(numeros.begin()+medio+1,numLeido);
                        break;
                    }
                    else
                        izquierda=medio+1;
                }
                else{
                    if(numLeido>= numeros[medio-1]){
                        numeros.insert(numeros.begin()+medio,numLeido);
                        break;
                    }
                    else
                        derecha = medio-1;
                }
            }
    	}
    	//busqueda de la media:
        tam++;
        if(tam%2){
            result += to_string(numeros[tam/2]) + "\n";
        }
        else{
            pos = tam/2;
            mediana = (numeros[pos] + numeros[pos-1])/2;
            result += to_string(mediana) + "\n";
        }
    }

    cout << result;
    return 0;
}
