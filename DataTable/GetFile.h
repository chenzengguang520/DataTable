#pragma once

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "Student.h"
#include <QVector>

class GetFile  : public QObject
{
	Q_OBJECT

private:
	QVector<Student> s;

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
};
