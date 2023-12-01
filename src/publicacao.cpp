#include "../include/publicacao.h"
#include "../include/twitter.h"
#include "../include/notificacao.h"
#include <iostream>
#include <algorithm>

using namespace std;

Publicacao::Publicacao(std::string u, std::string t, int cu, int co)
{
    usuario = u;
    textoDaPublicacao = t;
    curtidas = cu;
    compartilhamentos = co;
}

std::string Publicacao::getUsuario() {
    return usuario;
}

void Publicacao::setUsuario(const std::string& novoUsuario) {
    usuario = novoUsuario;
}

std::string Publicacao::getTextoDaPublicacao() const {
    return textoDaPublicacao;
}

void Publicacao::setTextoDaPublicacao(const std::string& novoTexto) {
    textoDaPublicacao = novoTexto;
}

int Publicacao::getCurtidas() const {
    return curtidas;
}

void Publicacao::setCurtida(int n)
{
    curtidas = n;
}

int Publicacao::getCompartilhamentos() const {
    return compartilhamentos;
}

void Publicacao::setCompartilhamentos(const int c)
{
    compartilhamentos = c;
}

void Publicacao::imprimirPublicacoesEncontradas(std::vector<Publicacao> resultados) {
    if (resultados.empty()) {
        cout << "Nenhuma publicacao encontrada.\n";
        return;
    }

    int indiceAtual = 0;
    char opcao;

    do {
        cout << "Texto da Publicacao: " << resultados[indiceAtual].getTextoDaPublicacao() << "\n";
        cout << "Curtidas: " << resultados[indiceAtual].getCurtidas() << "\n";
        cout << "Compartilhamentos: " << resultados[indiceAtual].getCompartilhamentos() << "\n\n";

        std::cout << "Opcoes: (A)vantar, (C)urtir, (S)air: ";
        cin >> opcao;

        switch (opcao) {
            case 'A':
            case 'a':
                indiceAtual = (indiceAtual + 1) % resultados.size();
                break;
            case 'V':
            case 'v':
                indiceAtual = (indiceAtual - 1 + resultados.size()) % resultados.size();
                break;
            case 'C':
            case 'c':
                resultados[indiceAtual].setCurtida(resultados[indiceAtual].getCurtidas()+1);
                cout << "Publicacao curtida!\n";
                break;
            case 'S':
            case 's':
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 'S' && opcao != 's');
}
