#ifndef TWITTER_SISTEMABUSCA_H
#define TWITTER_SISTEMABUSCA_H
#include <vector>
#include <string>
#include "publicacao.h"
#include "usuario.h"


class SistemaBusca {
public:
    static std::vector<Publicacao> buscaPorPalavraChave(const std::string& palavraChave);
    static std::vector<Usuario> buscarPorNomeUsuario(const std::vector<Usuario>& usuarios, const std::string& nomeUsuario);

};


#endif
