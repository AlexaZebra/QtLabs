#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include "FileState.h"
#include <QVector>

class FileMonitor: public QObject
{
    Q_OBJECT
private:
    //Q_OBJECT
    QVector<StateFile> infoFiles;                      // контейнер с статистикой файла используется в конструкторе FileMonitor

public:
    explicit FileMonitor(QObject* parent = nullptr);  // конструктор
    //~FileMonitor();
    void addFile(const QString& Path);                // метод добавления нового файла

signals:
    void StartMonitor(QString Path, qint64 Size);                  // сигнал - файлы добавлены
    void checkCreated(QString Path, qint64 Size, bool Exist);            // сигнал - файлы созданы
    void checkChanged(QString Path, qint64 Size);                        // сигнал - файлы изменены
    void checkDeleted(QString Path, bool Exist);                         // сигнал - файлы удалены

public slots:
    void updateFileState();     // Слот для обновления информации о файлах


};
#endif // FILEMONITOR_H


//Контейнеры
//QVector <FileState> objects;
//QSet <FileState> objects;
