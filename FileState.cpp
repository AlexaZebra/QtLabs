#include "FileState.h"



StateFile::StateFile(const QString& Path) { // конструктор с параметром
    QFileInfo infoFile(Path);
    fileName = infoFile.absoluteFilePath();
    Size = infoFile.size();
    IsExist = infoFile.exists();
}

QString StateFile::getPath() const {
    return fileName;
}

qint64 StateFile::getSize() const {
    return Size;
}

bool StateFile::getExist() const {
    return IsExist;
}


