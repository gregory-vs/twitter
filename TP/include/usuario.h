#ifndef TWITTER_USUARIO_H
#define TWITTER_USUARIO_H
#include "publicacao.h"
#include "notificacao.h"
#include <string>
#include <vector>


class Usuario {

private:
    std::string nome;
    std::vector<Publicacao> publicacoes;
    std::vector<Usuario> amigos;
    std::vector<Notificacao> notificacoes;

public:
    Usuario();
    ~Usuario();
    std::string getNome();
    void setNome(const std::string& novoNome);
    std::vector<Publicacao> getPublicacoes();
    void adicionarPublicacao(Publicacao& novaPublicacao);
    std::vector<Usuario> getAmigos();
    void imprimirPublicacoes();
    std::vector<Publicacao> buscaPorPalavraChave(const std::string& palavraChave);
    void adicionarNotificacao(const std::string& mensagem);
};


#endif
