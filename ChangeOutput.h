#pragma once
#ifndef CHANGEOUTPUT_H
#define CHANGEOUTPUT_H


#include <QString>
#include <QObject>

class ChangeOutput : public QObject
{

public:
    ChangeOutput() = default;

public slots:
    void logStartMonitor(QString fileName, qint64 Size);
    void logFinishMonitor(QString fileName);
    void logRestore(QString fileName, qint64 Size);
    void logChange(QString fileName, qint64 Size);
    void logDelete(QString fileName);
    void logChanges(QString fileName, qint64 Size);
};

#endif // CHANGEOUTPUT_H
