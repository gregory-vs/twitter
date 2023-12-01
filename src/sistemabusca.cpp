#include "../include/sistemabusca.h"
#include "../include/publicacao.h"
#include "../include/usuario.h"
#include <algorithm>




std::vector<Usuario> SistemaBusca::buscarPorNomeUsuario(const std::vector<Usuario>& usuarios, const std::string& nomeUsuario) {
    std::vector<Usuario> resultados;

    for (Usuario usuario : usuarios) {
        std::string nomeUsuarioMin = usuario.getNome();
        std::transform(nomeUsuarioMin.begin(), nomeUsuarioMin.end(), nomeUsuarioMin.begin(), ::tolower);

        std::string buscaMin = nomeUsuario;
        std::transform(buscaMin.begin(), buscaMin.end(), buscaMin.begin(), ::tolower);

        if (nomeUsuarioMin.find(buscaMin) != std::string::npos) {
            resultados.push_back(usuario);
        }
    }

    return resultados;
}