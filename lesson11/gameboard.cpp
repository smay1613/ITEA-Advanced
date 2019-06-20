#include "gameboard.h"

#include <cmath>
#include <numeric>
#include <algorithm>
#include <random>

GameBoard::GameBoard(QObject *parent, size_t board_dimension):
    QAbstractListModel {parent},
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

int GameBoard::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return static_cast<int>(m_boardsize);
}

QVariant GameBoard::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    switch (role) {
    case someRole   : return QVariant("someRoleData"   );
    case anotherRole: return QVariant("anotherRoleData");
    }
    return QVariant();
}

bool GameBoard::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags GameBoard::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> GameBoard::roleNames() const
{
    QHash<int, QByteArray> names;
    names[someRole] = "someRole";
    names[anotherRole] = "anotherRole";
    return names;
}
