#include "FileState.h"
#ifndef FILEMONITOR_H
#define FILEMONITOR_H


class FileMonitor: public QObject
{

private:
    Q_OBJECT


public:
    FileMonitor(const QString& filename);
    ~FileMonitor();
    bool AddFile(const QString* FileName);   // статус добавления файла в наблюдатель. 0, если объект уже под наблюдением
    bool DelFile(QString* FileName);   // 0, если не можем удалить (если его нет изначально)

//??CheckStatus();

//private:
//FileState *objects;
//FileState **objects;

//Контейнеры
//QVector <FileState> objects;
//QSet <FileState> objects;
};
#endif // FILEMONITOR_H
