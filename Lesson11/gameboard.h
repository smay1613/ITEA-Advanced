#pragma once

#include <vector>
#include <QAbstractListModel>

// homework : to MVC - model ListModel
// https://www.youtube.com/watch?v=9BcAYDlpuT8&t=1215s

class GameBoard : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int hiddenElementValue READ getHiddenElementValue CONSTANT)
public:
    static constexpr size_t DEFAULT_DIMENSION  {4};

    GameBoard(QObject *parent = nullptr, size_t board_dimension = DEFAULT_DIMENSION);

    struct Tile {
        size_t value {};
        Tile& operator= (const size_t new_value){
            value = new_value;
            return *this;
        }
    };

    void shuffle();

    //{ To become a QAbstractListModel

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    //}

    size_t getHiddenElementValue() const;

private:
    std::vector<Tile> m_raw_board;
    const size_t m_dimension;
    const size_t m_boardsize;

    const size_t hiddenElementValue;

    bool isBoardValid() const;
    bool isPositionValid (const size_t position) const;
    bool isSizeValid(size_t size) const ;

};
