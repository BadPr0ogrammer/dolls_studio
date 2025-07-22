#pragma once

#include <QQuickItem>

#include <QskLinearBox.h>
#include <QskPageIndicator.h>

namespace DS
{
class MenuFileButton;
class Header : public QskLinearBox
{
    Q_OBJECT

public:
    Header(int tabCount, QQuickItem* parent = nullptr);

    MenuFileButton* _menuFileButton = nullptr;

public Q_SLOTS:
    void setCurrentTab(int index);

Q_SIGNALS:
    void enabledToggled(bool);
    void drawerRequested();

//private:
//    QskPageIndicator* _pageIndicator;
};

}
