#pragma once

#include <vector>
#include <QAbstractListModel>

// homework : to MVC - model ListModel

class GameBoard : public QAbstractListModel
{
    Q_OBJECT
public:
    static constexpr size_t DEFAULT_DIMENSION  {4};

    GameBoard(size_t board_dimension = DEFAULT_DIMENSION);

    struct Tile {
        size_t value {};
        Tile& operator= (const size_t new_value){
            value = new_value;
            return *this;
        }
    };

    void shuffle();

private:
    std::vector<Tile> m_raw_board;
    const size_t m_dimension;
    const size_t m_boardsize;

    bool isBoardValid() const;
    bool isPositionValid (const size_t position) const;
};
