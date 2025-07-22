#pragma once

#include <SkinnyShortcut.h>

#include <QskObjectCounter.h>
#include <QskWindow.h>
#include <QskPushButton.h>
#include <QskCheckBox.h>
#include <QskLinearBox.h>
#include <QskMainView.h>

#include <QGuiApplication>

#include "private/qquickdialogtype_p.h"
#include "private/qquickfolderdialog_p.h"
#include "private/qquickfolderdialog_p.h"
#include "private/qquickfiledialog_p.h"

#include <QtQml>

namespace DS
{
    class VtkItem;
    class FileDlg : public QQuickFileDialog
    {
        Q_OBJECT
    public:
        FileDlg(VtkItem* vtk, QQuickFileDialog* parent = nullptr);

        void openFileDlg();

        VtkItem* _vtk = nullptr;
    public Q_SLOTS:
        void acceptFile();
    };
}
