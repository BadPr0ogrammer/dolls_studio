#include "page.h"

using namespace DS;

Page::Page(QQuickItem* parent)
    : Page(Qt::Vertical, parent)
{
}

Page::Page(Qt::Orientation orientation, QQuickItem* parent)
    : QskLinearBox(orientation, parent)
{
    setMargins(6);
    setPadding(6);
    setSpacing(6);
}
