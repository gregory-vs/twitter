#ifndef TWITTER_NOTIFICACAO_H
#define TWITTER_NOTIFICACAO_H

#include <string>

class Notificacao {

private:
    std::string mensagem;

public:
    Notificacao(const std::string& mensagem) : mensagem(mensagem) {};
    std::string getMensagem() const;
    static void mandarNotificacaoCurtida(std::string usuarioDestino, std::string usuarioOrigem);
};

#endif
