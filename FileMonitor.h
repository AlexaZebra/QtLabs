#include "FileState.h"
#include <QVector>

#ifndef FILEMONITOR_H
#define FILEMONITOR_H


class FileMonitor: public QObject
{

private:
    Q_OBJECT
    QVector<StateFile> infoFiles;                      // контейнер с статистикой файла используется в конструкторе FileMonitor

public:
    explicit FileMonitor(QObject* parent = nullptr);  // конструктор
    //~FileMonitor();
    void addFile(const QString& Path);                // метод добавления нового файла

signals:
    void checkCreated();        // сигнал - файлы созданы
    void checkChanged();        // сигнал - файлы изменены
    void ckeckDeleted();        // сигнал - файлы удалены

public slots:
    void updateFileState();     // Слот для обновления информации о файлах

signals:
    void existFile(QString fileName, bool exist);       // Сигнал передает имя и состояние
    void sizeFile(QString fileName, qint64 size);       // Сигнал передает имя и размер

};
#endif // FILEMONITOR_H
//??CheckStatus();

//Контейнеры
//QVector <FileState> objects;
//QSet <FileState> objects;
