#pragma once

#include <QQuickItem>

#include <QskPushButton.h>
#include <QskMenu.h>

class QskMenu;
namespace DS
{
class FileDlg;
class MenuFileButton : public QskPushButton
{
    Q_OBJECT
public:
    MenuFileButton(const QString& text, QQuickItem* parent = nullptr);

private:
    void openMenu();
    void populateMenu(QskMenu*);

    void openFile();
    void closeFile();
    void animateFile();
public:
    QskMenu* _menu = nullptr;
    FileDlg* _fileDlg = nullptr;
};

}
