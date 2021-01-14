#pragma once

#include <QFile>
class QString;

class MyLittleParse
{
public:
    enum error_enum
    {
        DEFAULT,
        OPEN_FILE_FAIL,
        KEY_EXITS,	//key存在，value为空, 适用于add
        REPEAT,		//key和value都存在，且重复，适用于mod
        KEY_NOEXITS,	//不能找到key, 适用于find
        SUCCESS
    };
    MyLittleParse(const QString& path);

    ~MyLittleParse();

    bool add(const QString& key, const QString& value, error_enum& e);
    bool add(const QString& key, const QString& value);
    bool add(const QString&& key, const QString&& value);

    bool del(const QString& key, error_enum& e);
    bool del(const QString& key);
    bool del(const QString&& key);

    bool mod(const QString& key, const QString& value, error_enum& e);
    bool mod(const QString& key, const QString& value);
    bool mod(const QString&& key, const QString&& value);

    bool find(const QString& key, QString& value, error_enum& e);
    bool find(const QString& key, QString& value);
    bool find(const QString&& key, QString&& value);

    bool find_only(const QString& key, error_enum& e);
    bool find_only(const QString& key);
    bool find_only(const QString&& key);

    error_enum getErrEnum() const;

    QString getErrMsg();
private:
    QFile *file;
    error_enum m_e;
};
