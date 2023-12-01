
#include "../include/twitter.h"
#include "../include/usuario.h"
#include "../include/publicacao.h"
#include "../include/sistemabusca.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Usuario Twitter::login()
{
    Usuario u = *new Usuario;
    string nomeUsuario;
    int login = 3;

    while(login != 0) {

        cout << "Bem vindo ao Twitter!" << endl;
        cout << "Você ja tem uma conta?" << endl;
        cout << "Selecione a opção: " << endl;
        cout << "1 - Ja tenho minha conta, entrar." << endl;
        cout << "2 - Gostaria de criar uma nova conta." << endl;
        cin >> login;
        cout << " " << endl;

        if (login == 1) {
            cout << "Por favor, digite seu nome de usuário: " << endl;
            cin >> nomeUsuario;
            cout << " " << endl;
            u =  Twitter::procuraUsuario(nomeUsuario);

            if (u.getNome() == "") {
                cout << "Usuario nao encontrado, verifique o nome cadastrado e tente novamente." << endl;
                cout << "Ou, se quiser, cadastre uma nova conta" << endl;
                cout << " " << endl;
            }
            else
            {
                cout << "Login feito com sucesso. Aproveite bem o site!" << endl;
                cout << " " << endl;
                login = 0;
            }

        }

        if (login == 2) {
            cout << "Por favor, digite o nome do usuário que você deseja cadastrar: " << endl;
            cin >> nomeUsuario;
            cout << " " << endl;
            u = Twitter::procuraUsuario(nomeUsuario);

            if(u.getNome() == "")  {
                u = cadastraUsuario(nomeUsuario);
                cout << "O cadastro foi realizado com sucesso. Aproveite bem o site!" << endl;
                cout << " " << endl;
                login = 0;
            }
            else
            {
                cout << "Usuario ja existe, por favor, verifique o nome cadastrado e tente novamente." << endl;
                cout << " " << endl;
            }
        }

    }

    return u;
}

Usuario Twitter::cadastraUsuario(const std::string& nomeUsuario) {

    Usuario user = *new Usuario;
    user.setNome(nomeUsuario);

    usuarios.push_back(user);

    return user;
}

Usuario Twitter::procuraUsuario(const std::string& nomeUsuario)
{
    Usuario u = *new Usuario;
    unsigned int vecSize = usuarios.size();

    for(int i = 0; i < vecSize; ++i)
    {
        if(usuarios[i].getNome() == nomeUsuario)
            return usuarios[i];
    }

    return u;
};

void Twitter::func(Usuario usuarioLogado)
{
    int opcaoEscolhida = -1;

    while(opcaoEscolhida != 0)
    {
        cout << "Agora, o que voce gostaria de fazer?" << endl;
        cout << "1 - gostaria de escrever uma publicacao." << endl;
        cout << "2 - gostaria de realizar uma busca." << endl;
        cout << "3 - gostaria de ver minhas notificacoes." << endl;
        cout << "4 - gostaria de ver minhas publicacoes." << endl;
        cout << "5 - gostaria de apagar minha conta." << endl;
        cout << "0 - sair do aplicativo." << endl;
        cin >> opcaoEscolhida;

        if(opcaoEscolhida == 1)
        {
            string txt;
            cout << "O que está acontecendo? (Lembre-se do limite de 140 caracteres)" << endl;
            getline(cin >> ws, txt);

            Twitter::adicionarPublicacaoAoSistema(usuarioLogado.getNome(), txt);

        }
        if(opcaoEscolhida == 2)
        {
            int opBusca;
            string palavraBusca;
            cout << "O que você gostaria de buscar?" << endl;
            cout << "1 - Usuário por nome." << endl;
            cout << "2 - Publicacao por palavra-chave." << endl;
            cin >> opBusca;
            cout << " " << endl;

            if(opBusca == 1)
            {
                int opUsuario;
                vector<Usuario> retorno;
                cout << "Digite o nome do usuario:" << endl;
                cin >> palavraBusca;
                retorno = SistemaBusca::buscarPorNomeUsuario(usuarios, palavraBusca);

                cout << "Resultados da busca por '" << palavraBusca << "':" << endl;
                for (Usuario resultado : retorno) {
                    cout << "Nome do Usuario: " << resultado.getNome() << "\n";
                }
                cout << " " << endl;
                cout << "A partir dos resultados informados, gostaria de ver as publicacoes de algum usuario?" << endl;
                cout << "1 - Sim." << endl;
                cout << "2 - Nao." << endl;
                cin >> opUsuario;
                if(opUsuario == 1)
                {
                    cout << "Digite o nome do usuario que voce gostaria de ver as publicacoes" << endl;
                    cin >> palavraBusca;

                    Usuario usuarioBusca = procuraUsuario(palavraBusca);

                    Publicacao::imprimirPublicacoesEncontradas(usuarioBusca.getPublicacoes());
                }
            }
            if(opBusca == 2)
            {
                vector<Publicacao> retorno;
                cout << "Digite o termo que voce gostaria de procurar." << endl;
                cin >> palavraBusca;

                for(Usuario usuario : usuarios)
                {
                    retorno = usuario.buscaPorPalavraChave(palavraBusca);

                    cout << "Resultados da busca por '" << palavraBusca << ":\n";

                    Publicacao::imprimirPublicacoesEncontradas(retorno);
                }
            }
        }
        if(opcaoEscolhida == 3)
        {
            cout << "Esta opcao ainda não foi implementada, aguarde por novidades!";
        }
        if(opcaoEscolhida == 4)
        {
            Usuario usuarioBusca = procuraUsuario(usuarioLogado.getNome());

            Publicacao::imprimirPublicacoesEncontradas(usuarioBusca.getPublicacoes());
        }
        if(opcaoEscolhida == 5)
        {
            Twitter::excluirUsuario(usuarioLogado.getNome());

            opcaoEscolhida = 0;
        }

        if(opcaoEscolhida == 0)
            break;

    }
}

void Twitter::adicionarPublicacaoAoSistema(const std::string& nomeUsuario, const std::string& texto) {
    Publicacao p = {nomeUsuario, texto, 0, 0};
    for (auto& usuario : usuarios) {
        if (usuario.getNome() == nomeUsuario) {
            usuario.adicionarPublicacao(p);
            std::cout << "Nova publicacao adicionada ao usuario " << nomeUsuario << ".\n";
            return;
        }
    }
}

void Twitter::excluirUsuario(const basic_string<char>& nome) {
    auto it = remove_if(usuarios.begin(), usuarios.end(),
                             [nome](Usuario usuario) {
                                 return usuario.getNome() == nome;
                             });

    usuarios.erase(it, usuarios.end());
}

