#include "gameboardmodel.h"
#include <random>
#include <QDebug>
#include <algorithm>
#include <QtMath>

GameBoardModel::GameBoardModel(QObject *parent, size_t size)
    : m_dimension {size},
      m_board(size * size)
{
    Q_UNUSED(parent)
    std::iota(m_board.begin(), m_board.end(), 1);
    shuffleBoard();
}

int GameBoardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_board.size();
}


QVariant GameBoardModel::data(const QModelIndex &index, int role) const
{
   // qDebug() << "data! " << role ;
    const int elementIndex {index.row()};
    if (!index.isValid() &&
            elementIndex < 0 &&
            elementIndex >= boardSize() &&
            role != Qt::DisplayRole)
    {
        return {};
    }

    const Tile& tile {m_board.at(elementIndex)};
    //qDebug() << "data! " << tile.value ;
    return QVariant::fromValue(static_cast<int>(tile.value));
}

bool GameBoardModel::move(int index)
{
    size_t tmp {serch16Element()};
    if(!proximityCheck(index, tmp)){
        return false;
        }


     std::swap(m_board[tmp], m_board[index]);
     numbersOfSteps();
     emit dataChanged(createIndex(0, 0), createIndex(boardSize(), 0));
     return  true;

     // qDebug() << "MOVE! " << index << m_board[index].value << " | "<<tmp<< m_board[tmp].value;
}

bool GameBoardModel::shuffleBoardFunc()
{
    shuffleBoard();
    numbersSteps = 0;
    emit dataChanged(createIndex(0, 0), createIndex(boardSize(), 0));
    return true;

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
    return true;
}

size_t GameBoardModel::serch16Element() const
{
    size_t number{0};
    for (const auto &value: m_board){

        if(value.value == boardSize()){
            return number;
        }
        number++;
    }
}

std::pair<size_t, size_t> GameBoardModel::getRowCol(size_t index) const
{
    size_t row = index / m_dimension;
    size_t col = index % m_dimension;

    return  std::make_pair(row, col);
}

size_t GameBoardModel::dimension() const
{
   // qWarning() <<  "!@#!@#!@#";
    return m_dimension;
}

size_t GameBoardModel::boardSize() const
{
       // qWarning() <<  "!@#!@#!@#";
    return m_dimension * m_dimension;
}

size_t GameBoardModel::numbersOfSteps()
{
    qWarning() << numbersSteps;
    return numbersSteps++;

}

bool GameBoardModel::proximityCheck(const size_t & elementToSwap, const size_t & lastElement)
{
    if(elementToSwap  == lastElement){
        return false;
    }
    std::pair<size_t, size_t> firstElement{getRowCol(elementToSwap)};
    std::pair<size_t, size_t> secondElement{getRowCol(lastElement)};
    qreal firsRow(firstElement.first);
    qreal secRow(secondElement.first);
    qreal firsCal(firstElement.second);
    qreal secCal(secondElement.second);
    if (firsRow - secRow > 1 || firsCal - secCal > 1 ){
        return false;
    }
    size_t firstCombIndex = firstElement.first + firstElement.second;
    size_t secCombIndex = secondElement.second+ secondElement.first;
    if( firstCombIndex - secCombIndex == 1 || firstCombIndex - secCombIndex == -1){
        return true;
    }
    return false;


}

