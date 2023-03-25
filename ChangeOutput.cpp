#include "ChangeOutput.h"
#include <iostream>

using namespace std;

void ChangeOutput::logStartMonitor(QString fileName, qint64 Size) {
        wcout << L"Файл мониторится: " << fileName.toStdWString() << L" его размер: "<< Size << L" байт" << endl;
}

void ChangeOutput::logRestore(QString fileName, qint64 Size) {
        wcout << L"Файл был восстановлен: " << fileName.toStdWString() << L" его размер: "<< Size << L" байт" << endl;
}

void ChangeOutput::logChange(QString fileName, qint64 Size) {
        wcout << L"Файл был изменен: " << fileName.toStdWString() << L", его размер: "<< Size << L" байт"<< endl;
}

void ChangeOutput::logDelete(QString fileName) {
        wcout << L"Файл был удален: " << fileName.toStdWString() << endl;
}
