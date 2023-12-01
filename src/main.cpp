#include <iostream>
#include <string>
#include "../include/twitter.h"

using namespace std;



int main() {
    Twitter t = *new Twitter;
    Usuario usuarioLogado = t.login();

    if(!usuarioLogado.getNome().empty())
    {
        t.func(usuarioLogado);
    }

    cout << "Obrigado por usar nosso site e volte sempre!" << endl;

    return 0;

}
