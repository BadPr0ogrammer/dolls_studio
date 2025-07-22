#include "tabview.h"

#include <QskScrollArea.h>
#include <QskScrollView.h>

using namespace DS;

TabView::TabView(QQuickItem* parent) : QskTabView(parent)
{
    setAutoFitTabs(true);
}

void TabView::setPagesEnabled(bool on)
{
    for (int i = 0; i < count(); i++)
        pageAt(i)->setEnabled(on);
}

void TabView::addPage(const QString& tabText, QQuickItem* page)
{
    auto scrollArea = new QskScrollArea();
    scrollArea->setMargins(5);

    scrollArea->setFocusPolicy(Qt::NoFocus);
    // hiding the viewport
    //scrollArea->setGradientHint(QskScrollView::Viewport, QskGradient());
    //scrollArea->setBoxShapeHint(QskScrollView::Viewport, 0);
    //scrollArea->setBoxBorderMetricsHint(QskScrollView::Viewport, 0);

    scrollArea->setItemResizable(true);
    scrollArea->setScrolledItem(page);

    addTab(tabText, scrollArea);
}
