#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include "datastream.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 控制台输入/输出: 将标准流封装为 QTextStream 对象
    //QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //QTextStream cerr(stderr, QIODevice::WriteOnly);

    DataStream data;
    data.m_nType = 10;
    data.m_strName = "Hello, World";

    QFile file("test");

    // Write
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << data;
    file.close();

    // Read
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    DataStream dataRead;
    in >> dataRead;
    file.close();

    // Test
    cout << dataRead.m_nType << endl;
    cout << dataRead.m_strName << endl;

    return a.exec();
}
