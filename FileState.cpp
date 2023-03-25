#include "FileState.h"



StateFile::StateFile(const QString& Path) { // конструктор с параметром
    QFileInfo infoFile;                     // с помощью конструктора QFileInfo инициализируем информацию
    infoFile.setFile(Path);                 // устанавливаем адрес
    fileName = infoFile.absoluteFilePath(); // храним путь
    IsExist = infoFile.exists();            // существование файла
    Size = infoFile.size();                 // его размер
}
                                            // геттеры для обращения к приватной информации из класса мониторинга
QString StateFile::getPath() const {
    return fileName;
}

qint64 StateFile::getSize() const {
    return Size;
}

bool StateFile::getExist() const {
    return IsExist;
}


