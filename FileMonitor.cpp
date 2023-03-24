#include "FileState.h"
#include "FileMonitor.h"



FileMonitor::FileMonitor(QObject* parent): QObject(parent){}

void FileMonitor::addFile(const QString& Path){

    StateFile newFile(Path);
    infoFiles.push_back(newFile);
}

void FileMonitor:: updateFileState(){

    for (int i = 0; i < infoFiles.count(); i++) {       // цикл по файлам

        QFileInfo currentFile(infoFiles[i].getPath());  // берем текущий i-ый файл

        if (currentFile.exists() && !IsExist ) {

        }
    }
}

/*
    если файл существует и не добавлен в мониторинг:
        IsExist = true;
        update size();
    иначе если файл мониторится, но был изменен:
        update size();
    иначе если файл мониторится, но не существует:
        IsExist = false;
        update size(); (вернется ноль т.к. файл не существует)
*/
