#include "gameboard.h"

#include <cmath>
#include <numeric>
#include <algorithm>
#include <random>

GameBoard::GameBoard(QObject *parent, size_t board_dimension):
    QAbstractListModel {parent},
    m_dimension {board_dimension},
    m_boardsize {board_dimension * board_dimension},
    hiddenElementValue {m_boardsize}
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
    return (position < m_boardsize);
}

int GameBoard::rowCount(const QModelIndex &/*parent*/) const
{
    return static_cast<int>(m_boardsize);
}

QVariant GameBoard::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return {};
    }

    const size_t index_row = static_cast<size_t>(index.row());

    if (!isSizeValid(index_row)) {
        return {};
    }

    //return QVariant( static_cast<int>(m_raw_board[index_row].value) );
    return QVariant::fromValue(m_raw_board[index_row].value);
}

size_t GameBoard::getHiddenElementValue() const
{
    return hiddenElementValue;
}

bool GameBoard::isSizeValid(size_t size) const
{
    return size <= m_boardsize;
}
