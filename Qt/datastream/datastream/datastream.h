#ifndef DATASTREAM_H
#define DATASTREAM_H

#include <QDataStream>

class DataStream :public QObject {
public:
    DataStream();
    virtual ~DataStream();
    DataStream& operator = (const DataStream&);

    friend QDataStream& operator >> (QDataStream&, DataStream&);
    friend QDataStream& operator << (QDataStream&, DataStream&);

    int m_nType;
    QString m_strName;
};

#endif // DATASTREAM_H
