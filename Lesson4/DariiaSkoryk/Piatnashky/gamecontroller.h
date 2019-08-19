#pragma once

#include <QObject>
#include "gameboardmodel.h"

class GameController : public QObject
{
    Q_OBJECT

public:
    explicit GameController(QObject *parent = nullptr);

    Q_INVOKABLE GameBoardModel* getModel();

private:
    GameBoardModel gameBoard;
};
