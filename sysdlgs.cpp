#include "sysdlgs.h"
#include "vtkitem.h"

using namespace DS;

FileDlg::FileDlg(VtkItem* vtk, QQuickFileDialog * parent)
    : QQuickFileDialog(parent), _vtk(vtk)
{
}

void FileDlg::openFileDlg()
{
    create();
    setModality(Qt::WindowModality::WindowModal);
    open();
    connect(this, SIGNAL(accepted()), this, SLOT(acceptFile()));
    connect(this, &QObject::destroyed, this, &QObject::deleteLater);
}

void FileDlg::acceptFile()
{
    const QUrl url = currentFile();
    _vtk->_fname = url.toLocalFile();
    _vtk->openSource();
}
