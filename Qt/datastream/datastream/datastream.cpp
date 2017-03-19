#include "datastream.h"

DataStream::DataStream() {
    m_nType = 0;
    m_strName = "";
}

DataStream::~DataStream() {

}

DataStream& DataStream::operator = (const DataStream& other) {
    m_nType = other.m_nType;
    m_strName = other.m_strName;
    return *this;
}

QDataStream& operator >> (QDataStream& src, DataStream& data) {
    src >> data.m_nType;
    src >> data.m_strName;
    return src;
}

QDataStream& operator << (QDataStream& out, DataStream& data) {
    out << data.m_nType << data.m_strName;
    return out;
}
