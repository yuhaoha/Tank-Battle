#include"connectmysql.h"
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
ConnectMysql::ConnectMysql()
{

}

void ConnectMysql:: insert(QString name, double grade )
{
    QSqlQuery query;
    query.prepare("insert into grades(name,grade) values (:name,:grade)");
    query.addBindValue(name);
    query.addBindValue(grade);
    query.exec();
}

void ConnectMysql:: connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("mydb");
    db.setUserName("myuser");
    db.setPassword("1234");
    bool ok = db.open();
    if(ok){
          qDebug()<<"成功连接数据库";
    }else{

          QMessageBox::warning(NULL,"警告","无法连接数据库");
    }
}
