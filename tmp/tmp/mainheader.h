#ifndef MAINHEADER_H
#define MAINHEADER_H

#include <QskLinearBox.h>
#include <QskPushButton.h>

#include <QQuickItem>

namespace DS
{
class MainHeader : public QskLinearBox
{
    Q_OBJECT
public:
    MainHeader(QQuickItem* parent);

    QskPushButton*  m_btnOpen = nullptr;
    QskPushButton*  m_btnAnim = nullptr;
};

}

#endif // MAINHEADER_H
