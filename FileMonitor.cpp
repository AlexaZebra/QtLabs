#include "FileState.h"
#include "FileMonitor.h"



FileMonitor::FileMonitor(QObject* parent): QObject(parent){}

FileMonitor& FileMonitor::Instance(){
    static FileMonitor instance;
    return instance;
}

void FileMonitor::addFile(const QString& Path){                 // метод добавления файла

    StateFile newFile(Path);                                    // вытаскиваем информацию из файла в класс FileState
    infoFiles.push_back(newFile);                               // добавляем в вектор infoFiles этот файл для мониторинга

    emit StartMonitor(newFile.getPath(), newFile.getSize());    // подаем сигнал о добавлении файла в мониторинг
}

void FileMonitor:: updateFileState(){                           // метод обновления информации в файлах

    for (int i = 0; i < infoFiles.count(); i++) {               // цикл по файлам

        StateFile monitorFile(infoFiles[i]);                    // берем i-ый файл из мониторинга
        StateFile currentFile(monitorFile.getPath());           // действительный файл

        if (!currentFile.getExist() && currentFile.getExist() != monitorFile.getExist()){               // проверяем удалили ли файл из мониторинга?
            infoFiles[i] = currentFile;                                                                 // если да, то вносим актуальную информацию
            emit checkDeleted(currentFile.getPath(), currentFile.getExist());                           // подаем сигнал, что файл удален
        }

        else if (currentFile.getExist() != monitorFile.getExist() ){                                    // иначе проверяем, восстановили ли файл?
            infoFiles[i] = currentFile;                                                                 // корректируем
            emit checkRestored(currentFile.getPath(), currentFile.getSize(), currentFile.getExist());   // информируем о восстановлении
        }

        else if ( currentFile.getSize() != monitorFile.getSize()){                                      // если не то и не другое, то изменился ли файл?
           infoFiles[i] = currentFile;                                                                  // если да, то обновляем информацию
           emit checkChanged(currentFile.getPath(), currentFile.getSize());                             // сообщаем об изменении
        }
    }
}

FileMonitor::~FileMonitor(){};
