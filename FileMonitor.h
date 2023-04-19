#pragma once
#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include "FileState.h"
#include <QVector>

class FileMonitor: public QObject
{

private:
    Q_OBJECT
    QVector<StateFile> infoFiles;                               // контейнер с информацией файла
    FileMonitor() = default;                                    // конструктор

public:
    static FileMonitor& Instance();   // чтобы создавался при вызове один экземпляр класса на протяжении всего времени работы программы
    void addFile(const QString& Path);                          // метод добавления нового файла в мониторинг
    void delFile(const QString& Path);                          // метод удаления файла из мониторинга
    void updateFileState();                                     // метод для обновления информации о файлах

signals:
    void StartMonitor(QString Path, qint64 Size);               // сигнал - файл добавлен в мониторинг
    void FinishMonitor(QString Path);                           // сигнал - файл удален из мониторинга
    void checkRestored(QString Path, qint64 Size);              // сигнал - файл создан
    void checkChanged(QString Path, qint64 Size);               // сигнал - файл изменен
    void checkDeleted(QString Path);                            // сигнал - файл удален

};
#endif // FILEMONITOR_H


//Контейнеры
//QVector <FileState> objects;
//QSet <FileState> objects;
