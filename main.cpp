#include <QCoreApplication>
#include "mylittleparse.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyLittleParse *parse = new MyLittleParse("/home/bobbi/Config.ini");

#define test(func, key, ...) \
    do {	\
        if (parse->func(key, ##__VA_ARGS__)) {		\
            qDebug() << QString("%1 %2 success, errmsg is [%3]").arg(#func).arg(key).arg(parse->getErrMsg());	\
        } else {								\
            qDebug() << QString("%1 %2 failed, errmsg is [%3]").arg(#func).arg(key).arg(parse->getErrMsg());	\
        }										\
    }while(0)

#if 0
    if (parse->find("name")) {
        qDebug() << "find name success";
    }
#endif
    test(add, "name", "bobbi");
    test(add, "password", "nansong");
    test(add, "sex", "male");
    test(mod, "sex", "female");
    test(del, "name");
    test(add, "name", "wangli");
    test(add, "name", "Lili");
    test(mod, "sex", "middle");
    test(del, "password");

    return a.exec();
}
