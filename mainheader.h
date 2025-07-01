#ifndef MAINHEADER_H
#define MAINHEADER_H

#include <QskLinearBox.h>
#include <QskPushButton.h>

#include <QQuickItem>

namespace DollsStudio
{
class MainHeader : public QskLinearBox
{
    Q_OBJECT
public:
    MainHeader(QQuickItem* parent);

    const QskPushButton* getBtnOpen();

private:
    QskPushButton*  m_btnOpen = nullptr;
};

}

#endif // MAINHEADER_H
