#include "mainview.h"

#include <QFileDialog>
#include <QApplication>
#include <QCoreApplication>

using namespace DS;

MainView::MainView(QQuickItem* parent)
{
    m_vtk = new VtkItem();

    m_header = new MainHeader(this);
    setHeader(m_header);

    QskControl* vtki = reinterpret_cast<QskControl*>(m_vtk);
    setBody(vtki);

    connect(m_header->m_btnOpen, &QskPushButton::pressed, this, &MainView::openFile);
    connect(m_header->m_btnAnim, &QskPushButton::pressed, this, &MainView::startAnim);
}

MainView::~MainView()
{
}

#if defined(__linux__) || defined(_WIN32)

void MainView::openFile()
{
    QFileDialog dialog(QApplication::activeWindow());
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("FBX (*.fbx);;All Files (*.*)"));
    dialog.setViewMode(QFileDialog::Detail);

    if (dialog.exec())
    {
        QStringList flist = dialog.selectedFiles();
        m_vtk->openSource(flist[0]);
    }
}

#endif

void MainView::startAnim()
{
    m_vtk->startAnim();
}
