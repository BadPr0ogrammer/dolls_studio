#pragma once

#include <QQuickItem>

#include <QskLinearBox.h>

namespace DS
{
class Page : public QskLinearBox
{
    Q_OBJECT
  public:
    Page(QQuickItem* parent = nullptr);
    Page(Qt::Orientation, QQuickItem* parent = nullptr);
};

}
