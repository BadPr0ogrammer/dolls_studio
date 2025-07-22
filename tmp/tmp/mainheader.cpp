#include "mainheader.h"

namespace DS
{

MainHeader::MainHeader(QQuickItem* parent) : QskLinearBox(Qt::Horizontal, parent)
{
    setPaddingHint(QskBox::Panel, 5);

    initSizePolicy(QskSizePolicy::Ignored, QskSizePolicy::Fixed);
    setPanel(true);

    m_btnOpen = new QskPushButton(tr("File"), this);
    m_btnAnim = new QskPushButton(tr("Animation"), this);

    addStretch(10);
}

}
