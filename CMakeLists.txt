cmake_minimum_required(VERSION 3.23)
project(twitter)

set(CMAKE_CXX_STANDARD 17)

add_executable(twitter
        src/main.cpp
        src/notificacao.cpp
        src/publicacao.cpp
        src/sistemabusca.cpp
        src/twitter.cpp
        src/usuario.cpp
        include/doctest.h
        include/notificacao.h
        include/publicacao.h
        include/sistemabusca.h
        include/twitter.h
        include/usuario.h
        src/TesteTwitter.cpp
)
