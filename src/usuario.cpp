#include "../include/usuario.h"
#include "../include/publicacao.h"
#include "../include/notificacao.h"
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

Usuario::Usuario() = default;
Usuario::~Usuario()= default;

std::string Usuario::getNome()  {
    return nome;
}

void Usuario::setNome(const std::string& novoNome) {
    nome = novoNome;
}

std::vector<Publicacao> Usuario::getPublicacoes() {
    return publicacoes;
}


void Usuario::adicionarPublicacao(Publicacao& novaPublicacao) {
    publicacoes.push_back(novaPublicacao);
}

void Usuario::adicionarNotificacao(const std::string& mensagem) {
    notificacoes.push_back({mensagem});
}

std::vector<Usuario> Usuario::getAmigos() {
    return amigos;
}

void Usuario::imprimirPublicacoes()  {
    Publicacao::imprimirPublicacoesEncontradas(publicacoes);
}

std::vector<Publicacao> Usuario::buscaPorPalavraChave(const std::string& palavraChave) {
    std::vector<Publicacao> resultados;

    for (Publicacao publicacao : publicacoes) {
        std::string textoMin = publicacao.getTextoDaPublicacao();
        std::transform(textoMin.begin(), textoMin.end(), textoMin.begin(), ::tolower);

        std::string chaveMin = palavraChave;
        std::transform(chaveMin.begin(), chaveMin.end(), chaveMin.begin(), ::tolower);

        if (textoMin.find(chaveMin) != std::string::npos) {
            resultados.push_back(publicacao);
        }
    }
    return resultados;
}

