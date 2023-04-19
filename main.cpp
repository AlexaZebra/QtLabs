#include "FileMonitor.h"
#include "FileState.h"
#include "ChangeOutput.h"
#include <QCoreApplication>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    QCoreApplication a(argc, argv);
    FileMonitor monitor;    // создаем объект класса FileMonitor
    ChangeOutput printer;   // создаем объект класса ChangeOut


    // устанавливаем соединения между сигналами и слотами
    QObject::connect(&monitor, &FileMonitor::StartMonitor, &printer, &ChangeOutput::logStartMonitor);
    QObject::connect(&monitor, &FileMonitor::FinishMonitor, &printer, &ChangeOutput::logFinishMonitor);
    QObject::connect(&monitor, &FileMonitor::checkRestored, &printer, &ChangeOutput::logRestore);
    QObject::connect(&monitor, &FileMonitor::checkChanged, &printer, &ChangeOutput::logChange);
    QObject::connect(&monitor, &FileMonitor::checkDeleted,&printer, &ChangeOutput::logDelete);

    // добавляем файлы для отслеживания
    monitor.addFile("C:/Users/staro/Lab_1/files/test1.txt");
    monitor.addFile("C:/Users/staro/Lab_1/files/test2.txt");
    monitor.addFile("C:/Users/staro/Lab_1/files/test3.txt");
    monitor.addFile("C:/Users/staro/Lab_1/files/test4.txt");

    monitor.delFile("C:/Users/staro/Lab_1/files/test4.txt");

    // цикл, котрый будет постоянно опрашивать изменения в файлах
    while (1) {
        monitor.updateFileState();
    }

    return a.exec();

}
