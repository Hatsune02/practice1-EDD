cmake_minimum_required(VERSION 3.27)
project(practice1_EDD)

set(CMAKE_CXX_STANDARD 17)

add_executable(practice1_EDD main.cpp
        backend/cards/Card.cpp
        backend/cards/Card.h
        backend/cards/Deck.cpp
        backend/cards/Deck.h
        backend/cards/Queue.cpp
        backend/cards/Queue.h
        backend/cards/Node.cpp
        backend/cards/Node.h
        backend/cards/LinkedList.cpp
        backend/cards/LinkedList.h
        backend/board/Board.cpp
        backend/board/Board.h)
