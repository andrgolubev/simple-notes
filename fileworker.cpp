#include "fileworker.h"

#include <QStandardPaths>
#include <QVariant>

#include <fcntl.h>

namespace
{
    static const char SAVE_FILE_NAME[] = "/.notes.sv";
}

FileWorker::FileWorker(QObject* parent) :
    QObject(parent),
    mFileOpened(false)
{
    auto homeLocationList = QStandardPaths::standardLocations(QStandardPaths::StandardLocation::HomeLocation);
    mSaveFilePath = homeLocationList[0] + SAVE_FILE_NAME;

    int file = open(mSaveFilePath.toStdString().c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    mFileWR.open(file, QFile::OpenModeFlag::ReadWrite);
}

FileWorker::~FileWorker()
{
    mFileWR.close();
}

void FileWorker::loadDefault()
{
    auto bytes = mFileWR.readAll();
    emit loadMessage(bytes);
}

void FileWorker::save(QString message)
{
    mFileWR.resize(0);
    mFileWR.write(message.toLatin1());
}
