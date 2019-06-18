#ifndef CONNECTMYSQL_H
#define CONNECTMYSQL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlDatabase>

class ConnectMysql
{
public:
    ConnectMysql();
    void connect();
    void insert(QString name, double grade);
};

#endif // CONNECTMYSQL_H
