#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

vector<string> palavras = {"PROGRAMACAO", "DESENVOLVIMENTO", "LINGUAGEM", "COMPUTADOR", "ALGORITMO", "HARDWARE", "BACKUP"};

string escolherPalavraAleatoria() {
    srand(static_cast<unsigned int>(time(0)));
    int indiceAleatorio = rand() % palavras.size();
    return palavras[indiceAleatorio];
}

string esconderPalavra(const string& palavra) {
    string palavraEscondida(palavra.length(), '_');
    return palavraEscondida;
}

bool tentativaValida(const string& palavra, char letra, string& palavraEscondida) {
    bool acerto = false;
    char letraMaiuscula = toupper(letra); // Converter para maiúsculas
    for (int i = 0; i < palavra.length(); ++i) {
        if (palavra[i] == letraMaiuscula) {
            palavraEscondida[i] = letraMaiuscula;
            acerto = true;
        }
    }
    return acerto;
}

bool palavraCompleta(const string& palavraEscondida) {
    return palavraEscondida.find('_') == string::npos;
}

int main() {
    string palavra = escolherPalavraAleatoria();
    string palavraEscondida = esconderPalavra(palavra);
    int tentativasMaximas = 6;
    int tentativas = 0;
    vector<char> letrasTentadas;

    cout << "Bem-vindo ao Jogo da Forca!\n";
    cout << "Tente adivinhar uma palavra com " << palavra.length() << " letras.\n";
    
    while (tentativas < tentativasMaximas) {
        cout << "Palavra: " << palavraEscondida << "\n";
        cout << "Tentativas restantes: " << tentativasMaximas - tentativas << "\n";
        cout << "Letras tentadas: ";
        for (char letra : letrasTentadas) {
            cout << letra << " ";
        }
        cout << "\n";

        char letra;
        cout << "Digite uma letra: ";
        cin >> letra;

        letra = toupper(letra); // Converter para maiúsculas

        if (find(letrasTentadas.begin(), letrasTentadas.end(), letra) != letrasTentadas.end()) {
            cout << "Você já tentou essa letra. Tente outra.\n";
            continue;
        }

        letrasTentadas.push_back(letra);

        if (tentativaValida(palavra, letra, palavraEscondida)) {
            cout << "Letra correta!\n";
            if (palavraCompleta(palavraEscondida)) {
                cout << "Parabéns! Você acertou a palavra: " << palavra << "\n";
                break;
            }
        } else {
            cout << "Letra incorreta. Tente novamente.\n";
            tentativas++;
        }
    }

    if (tentativas == tentativasMaximas) {
        cout << "Você atingiu o número máximo de tentativas. A palavra era: " << palavra << "\n";
    }

    return 0;
}
