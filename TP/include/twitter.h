#ifndef TWITTER_TWITTER_H
#define TWITTER_TWITTER_H
#include <string>
#include <vector>
#include "usuario.h"

class Twitter {

    std::vector<Usuario> usuarios;

public:
     Usuario procuraUsuario(const std::string& nomeUsuario);
     Usuario cadastraUsuario(const std::string& nomeUsuario);
     Usuario login();
     void func(Usuario usuarioLogado);
     void adicionarPublicacaoAoSistema(const std::string& nomeUsuario, const std::string& texto);

};


#endif
