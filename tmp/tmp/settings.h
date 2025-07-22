#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QString>
#include <QStringList>
#include <QUrl>

class Settings : public QSettings
{
    Q_OBJECT
    Q_PROPERTY(bool loadLastOnStartup READ loadLastOnStartup WRITE setLoadLastOnStartup NOTIFY loadLastOnStartupChanged)
    Q_PROPERTY(QStringList recentFiles READ recentFiles NOTIFY recentFilesChanged)
public:
    explicit Settings(QObject *parent = nullptr);

    bool loadLastOnStartup() const;
    void setLoadLastOnStartup(bool loadLastOnStartup);
    bool defaultLoadLastOnStartup() const;

    QStringList recentFiles() const;
    void addRecentFile(const QString &filePath);
    Q_INVOKABLE void clearRecentFiles();
    void removeInvalidRecentFiles();
    // Converts the paths we store ("file:///some-file.png") into a user-facing path.
    Q_INVOKABLE QString displayableFilePath(const QString &filePath) const;

    QString defaultOpenShortcut() const;
    QString openShortcut() const;
    void setOpenShortcut(const QString &shortcut);

signals:
    void loadLastOnStartupChanged();
    void recentFilesChanged();
};

#endif
