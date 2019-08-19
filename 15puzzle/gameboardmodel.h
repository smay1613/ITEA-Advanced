#ifndef GAMEBOARDMODEL_H
#define GAMEBOARDMODEL_H
#include <QAbstractListModel>

class GameBoardModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int dimension READ dimension CONSTANT)
    Q_PROPERTY(int boardSize READ boardSize CONSTANT)
    Q_PROPERTY(bool shuffleBoardFunc READ shuffleBoardFunc)
    Q_PROPERTY(int numbersOfSteps READ numbersOfSteps)


public:
    static constexpr size_t DefaultDimension {4};
    GameBoardModel(QObject* parent = nullptr,
                   size_t size = DefaultDimension);

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE bool move(int index);
    struct Tile {
        size_t value;
        Tile& operator= (const size_t new_value) {
            value = new_value;
            return *this;
        }
        bool operator==(const size_t other) {
            return other == value;
        }
    };
    bool shuffleBoardFunc();
    size_t dimension() const;
    size_t boardSize() const;
    size_t numbersOfSteps();
//    struct Position {

//        std::pair<size_t, size_t> m_position;
//    };

private:
    bool proximityCheck(const size_t &, const size_t &);

    bool isBoardValid() const;
    size_t serch16Element()const;
    void shuffleBoard();

    std::pair<size_t, size_t> getRowCol(size_t index) const;


    size_t numbersSteps{0};
    const size_t m_dimension;
    std::vector<Tile> m_board;
};

#endif // GAMEBOARDMODEL_H
