#pragma once

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "Student.h"
#include <QVector>
#include <QMap>

class GetFile  : public QObject
{
	Q_OBJECT

private:
	//存取学生信息的动态数组
	QVector<Student> s;
	
	//存取用户账号的数组和密码的 
	QMap<QString, QString>m;

public:
	GetFile(QObject *parent);
	~GetFile();

	//读文件测试
	void test();

	//追加文件内容测试
	void test1();

	//覆盖写入文件测试
	void test2();

	//添加一名学生
	void addStudent(Student& s);

	//读取文件并返回Student类型的动态数组
	QVector<Student>& getStudents();

	//对原有文件内容进行覆盖
	void writeFile(QVector<Student> s);

	//获取登录用户的账号和密码信息
	QMap<QString, QString>& getInformation();

	//存储用户的注册信息
	void WriteUser(QMap<QString, QString>);
};
