#include "header.h"
#include "menufilebutton.h"

#include <QskTextLabel.h>
#include <QskSwitchButton.h>
#include <QskPushButton.h>

using namespace DS;

Header::Header(int tabCount, QQuickItem* parent)
    : QskLinearBox(Qt::Horizontal, parent)
{
    setPaddingHint(QskBox::Panel, 5);

    initSizePolicy(QskSizePolicy::Ignored, QskSizePolicy::Fixed);
    setPanel(true);

    _menuFileButton = new MenuFileButton("File", this);

    addStretch(10);
    /*
    _pageIndicator = new QskPageIndicator(tabCount, this);
    _pageIndicator->setCurrentIndex(0);
    addStretch(10);
    {
        new QskTextLabel("Enabled", this);

        auto button = new QskSwitchButton(this);
        button->setChecked(true);

        connect(button, &QskSwitchButton::toggled, this, &Header::enabledToggled);
    }
    {
        auto burger = new QskPushButton( "≡", this );
        burger->setEmphasis(QskPushButton::LowEmphasis);

        connect(burger, &QskPushButton::clicked, this, &Header::drawerRequested);
    }
    */
}

void Header::setCurrentTab(int index)
{
    //_pageIndicator->setCurrentIndex(index);
}
