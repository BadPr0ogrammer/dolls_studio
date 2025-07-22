#pragma once

#include <QQuickItem>

#include <QskTabView.h>

namespace DS
{
class TabView : public QskTabView
{
    Q_OBJECT
public:
    TabView(QQuickItem* parent = nullptr);

    void setPagesEnabled(bool on);
    void addPage(const QString& tabText, QQuickItem* page);
};

}
