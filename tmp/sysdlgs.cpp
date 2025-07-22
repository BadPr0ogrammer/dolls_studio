#include "sysdlgs.h"

using namespace DS;

FileDlg::FileDlg(QQuickFileDialog * parent) : QQuickFileDialog(parent)
{
    //m_engine = new QQmlEngine(this);//QCoreApplication::instance()
    /*
    //m_component = new QQmlComponent(m_engine);

    QByteArray qmlCode = "import QtQuick.Dialogs\n";
    qmlCode += "FileDialog";
    qmlCode += " {}";
    //m_component->
        setData(qmlCode.constData(), QUrl());

    if (m_component->status() != QQmlComponent::Ready)
    {
        qWarning() << m_component->errorString();
        delete m_component;
        m_component = nullptr;
        return;
    }
    */
}

void FileDlg::createFileDlg()
{
    /*
    m_dialog = qobject_cast<QQuickFileDialog*>(m_component->create());
    m_dialog->setParent(this);
    m_dialog->setOptions(QFileDialogOptions::DontUseNativeDialog);
    m_dialog->setModality(Qt::WindowModality::WindowModal);
    m_dialog->open();
    connect(this, SIGNAL(m_dialog->accepted()), this, SLOT(FileDlg::acceptFile()));
    */
    create();
    //setOptions(QFileDialogOptions::DontUseNativeDialog);
    setModality(Qt::WindowModality::WindowModal);
    open();
}

void FileDlg::acceptFile()
{
    //const QUrl url = m_dialog->currentFile();
    qDebug() << "name";//m_dialog->objectName();
    //m_vtk->openSource(url);
}

/*
void FileDlg::createQml()
{


    m_dialog =
    //QObject::connect(m_dialog, &QObject::destroyed, m_component, &QObject::deleteLater);
}

void FileDlg::createFileDlg()
{
    createQml();
}

*/
