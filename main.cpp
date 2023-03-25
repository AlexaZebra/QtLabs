#include "FileMonitor.h"
#include "FileState.h"
#include "ChangeOutput.h"
#include <QCoreApplication>
#include <iostream>
#include <QTimer>
using namespace std;


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    QCoreApplication a(argc, argv);
    FileMonitor* monitor = new FileMonitor(); // Создаем объект класса FileMonitor


    // Устанавливаем соединения между сигналами и слотами
    QObject::connect(monitor, &FileMonitor::StartMonitor, &ChangeOutput::logStartMonitor);
    QObject::connect(monitor, &FileMonitor::checkCreated, &ChangeOutput::logCreate);
    QObject::connect(monitor, &FileMonitor::checkChanged, &ChangeOutput::logChange);
    QObject::connect(monitor, &FileMonitor::checkDeleted, &ChangeOutput::logDelete);

    // Добавляем файлы для отслеживания
    monitor->addFile("C:/Users/staro/Lab_1/files/test1.txt");
    monitor->addFile("C:/Users/staro/Lab_1/files/test2.txt");
    monitor->addFile("C:/Users/staro/Lab_1/files/test3.txt");
    monitor->addFile("C:/Users/staro/Lab_1/files/test4.txt");

    // Запустим цикл котрый будет постоянно опрашивать изменения в файлах
    while (1) {
        monitor->updateFileState();
    }

    return a.exec();

}
