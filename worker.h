#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

public slots:
    void DoWork();

signals:
    void Complete();

};

#endif // WORKER_H
