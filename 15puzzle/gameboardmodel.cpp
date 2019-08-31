#include "gameboardmodel.h"
#include <random>
#include <QDebug>
#include <QQuickView>
#include <QMetaObject>

GameBoardModel::GameBoardModel(QObject *parent, size_t size)
    : m_dimension {size},
      m_board(size * size)
{
    Q_UNUSED(parent)
    std::iota(m_board.begin(), m_board.end(), 1);

    do {
        shuffleBoard();
    } while (!isBoardValid());
}

int GameBoardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_board.size();
}

QVariant GameBoardModel::data(const QModelIndex &index, int role) const
{
    const int elementIndex {index.row()};
    if (!index.isValid() &&
            elementIndex < 0 &&
            elementIndex >= boardSize() &&
            role != Qt::DisplayRole)
    {
        return {};
    }

    const Tile& tile {m_board.at(elementIndex)};

    return QVariant::fromValue(static_cast<int>(tile.value));
}

void GameBoardModel::move(int index)
{
    int x{-1}, y{-1};
    if (index >= 0 && index <=15)
    {
        x = -1;
        if (index > 0)
        {
            if (index / m_dimension == (index - 1) / m_dimension && m_board[index - 1].value == boardSize())
            {
                x = index;
                y = index - 1;
            }
        }
        if (index < 15)
        {
            if (index / m_dimension == (index + 1) / m_dimension && m_board[index + 1].value == boardSize())
            {
                x = index;
                y = index + 1;
            }
        }
        if (index >= m_dimension)
        {
            if ( m_board[index - m_dimension].value == boardSize())
            {
                x = index;
                y = index - m_dimension;
            }
        }
        if (index <= isBoardValid() - m_dimension)
        {
            if ( m_board[index + m_dimension].value == boardSize())
            {
                x = index;
                y = index + m_dimension;
            }
        }
        if (x != -1)
        {
            if (x > y)
            {
                beginMoveRows(QModelIndex(), x , x , QModelIndex(), y);
                qDebug() << "MOVE! " << index;
            }
            else if (x < y)
            {
                beginMoveRows(QModelIndex(), y , y , QModelIndex(), x);
                qDebug() << "MOVE! " << index;
            }
            std::swap(m_board[x].value, m_board[y].value);
            endMoveRows();
            emit dataChanged(createIndex(0, 0), createIndex(static_cast<int>(boardSize()), 0));

            check_board();
        }
    }

}

void GameBoardModel::ms_box(int index)
{
    if (index == 0)
    {
        do {
            shuffleBoard();
        } while (!isBoardValid());
        emit dataChanged(createIndex(0, 0), createIndex(static_cast<int>(boardSize()), 0));
    }
}

void GameBoardModel::shuffleBoard()
{
    std::random_device defaultRandomDevice;
    std::default_random_engine randomEngine {defaultRandomDevice()};
    do {
        std::shuffle(m_board.begin(), m_board.end(), randomEngine);
    }
    while (!isBoardValid());
}

bool GameBoardModel::isBoardValid() const
{
    int inv {0};
        for (size_t i {0}; i < boardSize(); ++i) {
            if (m_board[i].value){
                for (size_t j = 0; j < i; ++j) {
                    if (m_board[j].value > m_board[i].value){
                        ++inv;
                    }
                }
            }
        }

        const size_t start_point = 1;

        for (size_t i = 0; i < boardSize(); ++i){
            if (m_board[i].value == boardSize()){
                inv += start_point + i / m_dimension;
            }
        }

        return (inv % 2) == 0;
}

void GameBoardModel::check_board()
{
    QQuickView view(QUrl::fromLocalFile("GameBoard.qml"));
    QVariantList list;
    list << true;
}

size_t GameBoardModel::dimension() const
{
    return m_dimension;
}

size_t GameBoardModel::boardSize() const
{
    return m_dimension * m_dimension;
}
