#ifndef APP_H
#define APP_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <memory>

class Settings;
class Manager;

class App
{
public:
    App(int &argc, char **argv);
    ~App();

    void registerQmlTypes();

    std::unique_ptr<QGuiApplication> m_application;
    std::unique_ptr<QQmlApplicationEngine> m_qmlEng;

    std::unique_ptr<Settings> m_settings;
    std::unique_ptr<Manager> m_manager;
};

#endif
