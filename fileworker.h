#pragma once

#include <QFile>
#include <QString>

class FileWorker : public QObject
{
    Q_OBJECT
public:
    FileWorker(QObject* parent = nullptr);
    ~FileWorker();

    void loadDefault();

public slots:
    void save(QString message);

signals:
    void loadMessage(QString message);

private:
    QFile mFileWR;
    QString mSaveFilePath;

    bool mFileOpened;
};

