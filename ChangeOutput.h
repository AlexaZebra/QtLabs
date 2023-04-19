#pragma once
#ifndef CHANGEOUTPUT_H
#define CHANGEOUTPUT_H


#include <QString>
#include <QObject>

class ChangeOutput : public QObject
{
public slots:
    static void logStartMonitor(QString fileName, qint64 Size);
    static void logFinishMonitor(QString fileName);
    static void logRestore(QString fileName, qint64 Size);
    static void logChange(QString fileName, qint64 Size);
    static void logDelete(QString fileName);
    static void logChanges(QString fileName, qint64 Size);
};

#endif // CHANGEOUTPUT_H
