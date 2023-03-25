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
    // Функции статичны для возможности вызова их без создания экзепляра класса
    static void logStartMonitor(QString fileName, qint64 Size);
    static void logRestore(QString fileName, qint64 Size);
    static void logChange(QString fileName, qint64 Size);
    static void logDelete(QString fileName);
};

#endif // CHANGEOUTPUT_H
