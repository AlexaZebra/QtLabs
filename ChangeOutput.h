#pragma once
#ifndef CHANGEOUTPUT_H
#define CHANGEOUTPUT_H


#include <QString>
#include <QObject>

class ChangeOutput : public QObject
{

public slots:
    // используется static, чтобы не создавать объект этого класса в main()
    static void logStartMonitor(QString fileName, qint64 Size);
    static void logRestore(QString fileName, qint64 Size);
    static void logChange(QString fileName, qint64 Size);
    static void logDelete(QString fileName);
};

#endif // CHANGEOUTPUT_H
