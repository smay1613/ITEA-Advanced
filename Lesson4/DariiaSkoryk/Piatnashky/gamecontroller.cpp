#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{
}

GameBoardModel* GameController::getModel()
{
    return &gameBoard;
}
