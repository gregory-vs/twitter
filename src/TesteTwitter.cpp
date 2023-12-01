#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/doctest.h"

#include "../include/twitter.h"

TEST_CASE("Teste criacao usuario") {
    Twitter t = *new Twitter;
    Usuario u, v = *new Usuario;
    v.setNome("greg");
    u = t.cadastraUsuario("greg");
    CHECK(u.getNome() == v.getNome());
}