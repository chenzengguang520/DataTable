#pragma once

#include <QObject>
#include <QString>

class Student  : public QObject
{
	Q_OBJECT

private:
	//学号
	QString sno;

	//姓名
	QString name;

	//性别
	QString sex;

	//出生日期
	QString data;

	//所在系
	QString sdept;

public:
	//构造函数和析构函数
	Student(QObject *parent);
	Student();
	Student(QString m_sno, QString m_name, QString sex, QString m_data, QString m_sdept);
	Student(const Student& s);
	~Student();
	
	//存取学号
	void setSno(QString m_sno);
	QString getSno();

	//存取姓名
	void setName(QString m_name);
	QString getName();

	//存取性别
	void setSex(QString m_sex);
	QString getSex();

	//存取出生日期
	void setData(QString m_data);
	QString getData();

	//存取所在系
	void setSdept(QString m_Sdept);
	QString getSdept();

	//检查函数，检查存取的变量是否具有完整性
	bool check(QString str, int len);

	//重载等号
	Student& operator=(const Student& other);
};
