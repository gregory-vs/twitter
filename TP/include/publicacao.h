#ifndef TWITTER_PUBLICACAO_H
#define TWITTER_PUBLICACAO_H
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Publicacao {

private:
    std::string usuario;
    std::string textoDaPublicacao;

public:
    int curtidas;
    int compartilhamentos;
    Publicacao(std::string u, std::string t, int cu, int co);
    std::string getUsuario();
    void setUsuario(const std::string& novoUsuario);
    int getCurtidas() const;
    void setCurtida(int n);
    int getCompartilhamentos() const;
    void setCompartilhamentos(int c);
    std::string getTextoDaPublicacao() const;
    void setTextoDaPublicacao(const std::string& novoTexto);
    void imprimirPublicacoes();
    static void imprimirPublicacoesEncontradas(std::vector<Publicacao> resultados);
    static void mandarNotificacaoCurtida(std::string usuarioDestino, std::string usuarioOrigem);
};


#endif //TWITTER_PUBLICACAO_H
