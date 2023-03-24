#include <QString>
#include <QFileInfo>
#ifndef FILESTATE_H
#define FILESTATE_H


class StateFile: public QObject     // данные файла
{
private:
    Q_OBJECT
    QString fileName;
    qint64 Size = 0;
    bool IsExist;

public:
    StateFile(const QString& Path); // конструктор с параметром путь файла
    //~StateFile();
    QString getPath() const;        // получить путь
    qint64 getSize() const;         // получить размер
    bool getExist() const;          // получить статус существования

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
