#include "FileState.h"
#include "FileMonitor.h"



FileMonitor::FileMonitor(QObject* parent): QObject(parent){}

void FileMonitor::addFile(const QString& Path){

    StateFile newFile(Path);
    infoFiles.push_back(newFile);

    emit StartMonitor(newFile.getPath(), newFile.getSize());
}

void FileMonitor:: updateFileState(){

    for (int i = 0; i < infoFiles.count(); i++) {       // цикл по файлам

        StateFile monitorFile(infoFiles[i].getPath());  // берем текущий i-ый файл
        StateFile currentFile(monitorFile.getPath());   // новый файл, который возможно с изменениями

        if (currentFile.getExist() && currentFile.getExist() != monitorFile.getExist()){
            infoFiles[i] = currentFile;
            emit checkCreated(currentFile.getPath(), currentFile.getSize(), currentFile.getExist());
        }

        else if (currentFile.getExist() && currentFile.getSize() != monitorFile.getSize()){
            infoFiles[i] = currentFile;
            emit checkChanged(currentFile.getPath(), currentFile.getSize());
        }

        else if (!currentFile.getExist() && currentFile.getExist() != monitorFile.getExist())
            emit checkDeleted(currentFile.getPath(), currentFile.getExist());
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
        update size();
*/
