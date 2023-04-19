#pragma once
#ifndef FILESTATE_H
#define FILESTATE_H

#include <QString>
#include <QFileInfo>

class StateFile{

private:
    QString fileName;
    qint64 Size = 0;
    bool IsExist;

public:
    StateFile() = default;                      // конструктор по умолчанию используется контейнером
    StateFile(const QString& Path);             // конструктор с параметром путь файла
    bool operator==(const StateFile& file)const;//перегрузка оператора, чтобы делать проверки внутри методов addFile и delFile
    QString getPath();                          // получить путь
    qint64 getSize();                           // получить размер
    bool getExist();                            // получить статус существования
};
#endif // FILESTATE_H


// старт вывести все файлы(пути) и размер
// + состояние
/*
 *  массив строк
 *  QFileInfo системно-независимая информация
 *  qmake
 *  объект константный и функции тоже
 *  QString для работы со строками
 *  Изменение файла (last modify?) - это изменение относительно размера файла
*/



