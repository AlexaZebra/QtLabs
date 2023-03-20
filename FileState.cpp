#include "FileState.h"
#include <QFileInfo> //https://doc.qt.io/qt-6/qfileinfo.html#details

StateFile::StateFile(const QString& filename) { // конструктор с аргументом
    QFileInfo FileName(filename);
    Size = FileName.size();
    IsExist = FileName.exists();
}

QString StateFile::getFileName() const {
    return FileName;
}

qint64 StateFile::getSize() const{
    return Size;
}

bool StateFile::getExistStatus() const{
    return IsExist;
}
