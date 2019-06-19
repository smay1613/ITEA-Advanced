#include "gameboard.h"

#include <cmath>
#include <numeric>
#include <algorithm>
#include <random>

GameBoard::GameBoard(size_t board_dimension):
    m_dimension {board_dimension},
    m_boardsize {board_dimension * board_dimension}
{
    m_raw_board.resize(m_boardsize);
    std::iota(m_raw_board.begin(), m_raw_board.end(), 1);
    shuffle();
}

void GameBoard::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());

    do {
        std::shuffle(m_raw_board.begin(), m_raw_board.end(), g);
    }
    while (!isBoardValid());
}

bool GameBoard::isBoardValid() const
{
    int inv = 0;
    for (size_t i = 0; i < m_boardsize; ++i){
        if (m_raw_board[i].value){
            for (size_t j = 0; j < i; ++j){
                if (m_raw_board[j].value > m_raw_board[i].value){
                    ++inv;
                }
            }
        }
    }


    const size_t start_point = 1;

    for (size_t i = 0; i < m_boardsize; ++i){
        if (m_raw_board[i].value == m_boardsize){
            inv += start_point + i / m_dimension;
        }
    }

    return ((inv % 2) == 0);
}

bool GameBoard::isPositionValid(const size_t position) const
{
    return position < m_boardsize;
}
