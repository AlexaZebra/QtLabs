#include "FileMonitor.h"
#include "FileState.h"
#include <QCoreApplication>
#include <iostream>
using namespace std;

void main(){
    FileMonitor monitor;
    FileMonitor.AddFile('a.txt');
    FileMonitor.AddFile('b.txt');
    FileMonitor.AddFile('c.txt');
    FileMonitor.AddFile('d.txt');


    while(doCheckObj){

    FileMonitor.CheckStatus();

};
