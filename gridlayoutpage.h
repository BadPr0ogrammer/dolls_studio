#pragma once

#include <QskControl.h>

class QskGridBox;
namespace DS
{
class GridLayoutPage : public QskControl
{
public:
    GridLayoutPage(QQuickItem* parent = nullptr);

    QskGridBox* _grid = nullptr;
};

}
