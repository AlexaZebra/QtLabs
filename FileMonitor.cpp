#include "FileState.h"
#include "FileMonitor.h"
#include "ChangeOutput.h"


FileMonitor& FileMonitor::Instance(){
    static FileMonitor instance;
    return instance;
}

FileMonitor::FileMonitor(){
    // устанавливаем соединения между сигналами и слотами
    QObject::connect(this, &FileMonitor::StartMonitor, &ChangeOutput::logStartMonitor);
    QObject::connect(this, &FileMonitor::FinishMonitor, &ChangeOutput::logFinishMonitor);
    QObject::connect(this, &FileMonitor::checkRestored, &ChangeOutput::logRestore);
    QObject::connect(this, &FileMonitor::checkChanged, &ChangeOutput::logChange);
    QObject::connect(this, &FileMonitor::checkDeleted, &ChangeOutput::logDelete);
}

bool FileMonitor::addFile(const QString& Path){                         // метод добавления файла в мониторинг

    StateFile newFile(Path);                                            // вытаскиваем информацию из файла в класс FileState
    if (!infoFiles.contains(newFile)){                                  // если файл не дублируется, то
        infoFiles.push_back(newFile);                                   // добавляем в вектор infoFiles этот файл для мониторинга
        emit StartMonitor(newFile.getPath(), newFile.getSize());        // подаем сигнал о добавлении файла в мониторинг
        return true;
    }
    else
        return false;
}

bool FileMonitor::delFile(const QString& Path){                         // метод удаления файла из мониторинга

    StateFile oldFile(Path);
    if (infoFiles.contains(oldFile)){
        infoFiles.removeOne(oldFile);
        emit FinishMonitor(oldFile.getPath());
        return true;
    }
    else
        return false;
}

void FileMonitor:: updateFileState(){                           // метод обновления информации в файлах

    for (int i = 0; i < infoFiles.count(); i++) {               // цикл по файлам

        StateFile monitorFile(infoFiles[i]);                    // берем i-ый файл из мониторинга
        StateFile currentFile(monitorFile.getPath());           // действительный файл

        if (!currentFile.getExist() && currentFile.getExist() != monitorFile.getExist()){               // проверяем удалили ли файл из мониторинга?
            infoFiles[i] = currentFile;                                                                 // если да, то вносим актуальную информацию
            emit checkDeleted(currentFile.getPath());                                                   // подаем сигнал, что файл удален
        }

        else if (currentFile.getExist() != monitorFile.getExist() ){                                    // иначе проверяем, восстановили ли файл?
            infoFiles[i] = currentFile;                                                                 // корректируем
            emit checkRestored(currentFile.getPath(), currentFile.getSize());                          // информируем о восстановлении
        }

        else if ( currentFile.getSize() != monitorFile.getSize()){                                      // если не то и не другое, то изменился ли файл?
           infoFiles[i] = currentFile;                                                                  // если да, то обновляем информацию
           emit checkChanged(currentFile.getPath(), currentFile.getSize());                            // сообщаем об изменении
        }
    }
}

