#include "notificacao.h"
#include "usuario.h"
#include "twitter.h"
#include <string>

using namespace std;

string Notificacao::getMensagem() const {
    return mensagem;
}
