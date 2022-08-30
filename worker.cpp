#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Created" << this;
}

void Worker::DoWork()
{
    for(int i = 0; i < 100; i++)
    {
        qInfo() << "Work" << QString().number(i);
    }

    emit Complete();
}
