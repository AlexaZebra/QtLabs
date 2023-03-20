#include <QString>
#include <QFileInfo>
#ifndef FILESTATE_H
#define FILESTATE_H


class StateFile: public QObject // хранит состояние файла
{
private:
    Q_OBJECT
    QString FileName;
    qint64 Size = 0;
    bool IsExist;

public:
    StateFile(const QString& filename);
    //~StateFile();
    QString getFileName() const;
    qint64 getSize() const;
    bool getExistStatus() const;
};
#endif // FILESTATE_H

// старт вывести все файлы(пути) и размер
// + состояние
/*
 *  массив строк??
 *  QFileInfo системно-независимая информация
 *  qmake
 *  объект константный и функции тоже
 *  QString для работы со строками
 *  Изменение файла (last modify?) - это изменение относительно размера файла
*/
