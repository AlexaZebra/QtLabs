#include "FileState.h"



StateFile::StateFile(const QString& Path) { // конструктор с параметром
    QFileInfo fileName(Path);
    Size = fileName.size();
    IsExist = fileName.exists();
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


