#ifndef MANAGER_H
#define MANAGER_H

#include <memory>

#include <QObject>
#include <QUrl>
#include <QtQmlIntegration/qqmlintegration.h>

#include "settings.h"
#include "vtkitem.h"

class Manager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Settings *applicationSettings READ applicationSettings
        WRITE setApplicationSettings NOTIFY applicationSettingsChanged)
    Q_PROPERTY(bool ready READ isReady NOTIFY readyChanged)

    QML_ELEMENT
    QML_UNCREATABLE("")
    Q_MOC_INCLUDE("app.h")

public:
    explicit Manager(QObject *parent = nullptr);

    Settings *applicationSettings() const;
    void setApplicationSettings(Settings *applicationSettings);

    bool isReady() const;
    void setReady(bool ready);

    Q_INVOKABLE void openSource(const QUrl &url);
    Q_INVOKABLE void playFlag();

    Settings *m_settings = nullptr;
    VtkItem *m_vtk = nullptr;

    bool m_projectCreationFailed = false;
    bool m_ready = false;
signals:
    void projectChanged();
    void applicationSettingsChanged();
    void readyChanged();
    void creationFailed(const QString &errorMessage);

private slots:
    void onCreationFailed(const QString &errorMessage);
    void projectUrlChanged();
};

#endif
