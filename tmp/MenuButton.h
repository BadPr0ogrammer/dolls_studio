#pragma once

#include <QQuickItem>

#include <QskPushButton.h>
#include <QskMenu.h>

class QskMenu;
namespace DS
{
class FileDlg;
class MenuButton : public QskPushButton
{
    Q_OBJECT
public:
    MenuButton(const QString& text, QQuickItem* parent = nullptr);

private:
    void openMenu();
    void populateMenu(QskMenu*);

    void openFile();        
public:
    QskMenu* m_menu = nullptr;
    FileDlg* m_fileDlg = nullptr;
};

}
