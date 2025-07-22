#include "settings.h"

#include <QDebug>
#include <QFile>
#include <QKeySequence>
#include <QLoggingCategory>
#include <QVector>

Settings::Settings(QObject *parent) :
    QSettings(parent)
{
    //qCDebug(lcApplicationSettings) << "Loading settings from" << fileName();
}

bool Settings::loadLastOnStartup() const
{
    return contains("loadLastOnStartup") ? value("loadLastOnStartup").toBool() : defaultLoadLastOnStartup();
}

void Settings::setLoadLastOnStartup(bool loadLastOnStartup)
{
    const bool existingValue = value("loadLastOnStartup", defaultLoadLastOnStartup()).toBool();
    if (loadLastOnStartup == existingValue)
        return;

    setValue("loadLastOnStartup", loadLastOnStartup);
    emit loadLastOnStartupChanged();
}

bool Settings::defaultLoadLastOnStartup() const
{
    return false;
}

QStringList Settings::recentFiles() const
{
    return contains("recentFiles") ? value("recentFiles").toStringList() : QStringList();
}

void Settings::addRecentFile(const QString &filePath)
{
    QStringList files = recentFiles();
    const int existingIndex = files.indexOf(filePath);
    // If it already exists, remove it and move it to the top.
    if (existingIndex != -1)
        files.removeAt(existingIndex);

    // Add the file to the top of the list.
    files.prepend(filePath);

    // Respect the file limit.
    if (files.size() > 20)
        files.removeLast();

    setValue("recentFiles", files);
    emit recentFilesChanged();
}

void Settings::clearRecentFiles()
{
    if (recentFiles().isEmpty())
        return;

    setValue("recentFiles", QStringList());
    emit recentFilesChanged();
}

void Settings::removeInvalidRecentFiles()
{
    if (!contains("recentFiles"))
        return;

    bool changed = false;
    QStringList files = value("recentFiles").toStringList();
    for (int i = 0; i < files.size(); ) {
        const QString filePath = files.at(i);
        if (filePath.isEmpty() || !QFile::exists(QUrl(filePath).toLocalFile())) {
            files.removeAt(i);
            changed = true;
        } else {
            ++i;
        }
    }

    setValue("recentFiles", files);

    if (changed)
        emit recentFilesChanged();
}

QString Settings::displayableFilePath(const QString &filePath) const
{
    return QUrl(filePath).toLocalFile();
}
