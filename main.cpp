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
    FileMonitor& monitor = FileMonitor::Instance();

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
