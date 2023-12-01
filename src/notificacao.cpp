#include "../include/notificacao.h"
#include "../include/usuario.h"
#include "../include/twitter.h"
#include <string>

using namespace std;

string Notificacao::getMensagem() const {
    return mensagem;
}
