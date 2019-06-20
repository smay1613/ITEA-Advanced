#pragma once

#include <vector>
#include <QAbstractListModel>

// homework : to MVC - model ListModel
// https://www.youtube.com/watch?v=9BcAYDlpuT8&t=1215s

class GameBoard : public QAbstractListModel
{
    Q_OBJECT
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

    enum {
        someRole = Qt::UserRole,
        anotherRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
    //}

private:
    std::vector<Tile> m_raw_board;
    const size_t m_dimension;
    const size_t m_boardsize;

    bool isBoardValid() const;
    bool isPositionValid (const size_t position) const;
};
