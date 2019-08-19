#include "gameboardmodel.h"
#include <random>
#include <QDebug>
#include <cmath>
#include <numeric>
#include <algorithm>

GameBoardModel::GameBoardModel(QObject *parent, size_t size) // Difference
    : m_dimension {size},
      m_hiddenElementValue {size * size},
      m_board(size * size)
{
    Q_UNUSED(parent)
    std::iota(m_board.begin(), m_board.end(), 1);
    shuffleBoard();
    QVector<int> qvector;
    emit dataChanged(createIndex(0, 0), createIndex(static_cast<int>(boardSize()), 0));
}

int GameBoardModel::rowCount(const QModelIndex &parent) const //TRUE
{
    Q_UNUSED(parent)
    return static_cast<int>(m_board.size());
}

QVariant GameBoardModel::data(const QModelIndex &index, int role) const // Difference
{
    const int elementIndex {index.row()};
    if (!index.isValid() &&
            elementIndex < 0 &&
            static_cast<size_t>(elementIndex) >= boardSize() &&
            role != Qt::DisplayRole)
    {
        return {};
    }

    const Tile& tile {m_board.at(static_cast<size_t>(elementIndex))};

    return QVariant::fromValue(static_cast<int>(tile.value));
}

void GameBoardModel::move(int index)
{
    int freeTilePosition {0};

    for (int i = 0; i < static_cast<int>(boardSize()); i++) {
        if (m_board.at(static_cast<size_t>(i)).value == boardSize()) {
            freeTilePosition = i;
            break;
        }
    }

    int right = (index + 1) % static_cast<int>(dimension()) ? index + 1 : -1;
    int left = index % static_cast<int>(dimension()) ? index - 1 : -1;
    int top = index >= static_cast<int>(dimension()) ? index - static_cast<int>(dimension()) : -1;
    int bottom = index < static_cast<int>(boardSize() - dimension()) ? index + static_cast<int>(dimension()) : -1;

    bool adjacent = freeTilePosition == right || freeTilePosition == left || freeTilePosition == bottom || freeTilePosition == top;

    int destination = index > freeTilePosition ? freeTilePosition : freeTilePosition + 1;

    if (adjacent) {
        beginMoveRows(QModelIndex(), index, index, QModelIndex(), destination);
        std::swap(m_board.at(static_cast<size_t>(index)), m_board.at(static_cast<size_t>(freeTilePosition)));
        endMoveRows();
        qDebug() << "MOVE: done [" << index << "]";
        emit dataChanged(createIndex(0, 0), createIndex(static_cast<int>(boardSize()), 0));
    }
    else {
        qDebug() << "MOVE: fail [" << index << "], choose another tile";
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
    emit dataChanged(createIndex(0, 0), createIndex(static_cast<int>(boardSize()), 0));
    qDebug() << "CHANGE BOARD: board changed!";
}

int GameBoardModel::hiddenElementValue() const{
    return static_cast<int>(m_hiddenElementValue);
}

size_t GameBoardModel::dimension() const
{
    return m_dimension;
}

size_t GameBoardModel::boardSize() const
{
    return m_dimension * m_dimension;
}

bool GameBoardModel::isBoardValid() const
{
    int pairs = 0;

    for (size_t i(0); i < dimension(); i++) {
        if (m_board.at(i).value != dimension() - 1) {
            for (size_t j(0); j < i; ++j) {
                if (m_board.at(j).value > m_board.at(i).value
                        && m_board.at(j).value != dimension() - 1) {
                    pairs++;
                }
            }
        } else {
            pairs += i / boardSize() + 1;
        }
    }
    return !(pairs % 2);
}

bool GameBoardModel::isPositionValid(const size_t position) const
{
    return position < boardSize();
}

GameBoardModel::Position GameBoardModel::getRowCol(size_t index) const
{
    size_t row = index / m_dimension;
    size_t col = index % m_dimension;
    Position result;
    result.m_position = std::make_pair(row, col);

    return result;
}
