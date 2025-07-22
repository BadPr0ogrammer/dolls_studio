#include <SkinnyShortcut.h>

#include <QskObjectCounter.h>
#include <QskWindow.h>
#include <QskPushButton.h>
#include <QskCheckBox.h>
#include <QskLinearBox.h>
#include <QskMainView.h>

#include <QGuiApplication>

#include <private/qquickcolordialog_p.h>
#include <private/qquickfiledialog_p.h>
#include <private/qquickfolderdialog_p.h>
#include <private/qquickfontdialog_p.h>
#include <private/qquickmessagedialog_p.h>

#include <QtQml>

static QQuickAbstractDialog* createQml( const char* className )
{
    static QQmlEngine engine( nullptr );

    QByteArray qmlCode = "import QtQuick.Dialogs\n";
    qmlCode += className;
    qmlCode += " {}";

    auto component = new QQmlComponent( &engine );
    component->setData( qmlCode.constData(), QUrl() );

    if ( component->status() != QQmlComponent::Ready )
    {
        qWarning() << component->errorString();
        delete component;

        return nullptr;
    }

    auto dialog = qobject_cast< QQuickAbstractDialog* >( component->create() );
    QObject::connect( dialog, &QObject::destroyed,
                     component, &QObject::deleteLater );

    return dialog;
}
