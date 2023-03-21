#include "Student.h"
#include <qdebug.h>

Student::Student(QObject *parent)
	: QObject(parent)
{}

Student::Student()
{
}

Student::Student(QString m_sno, QString m_name, QString m_sex, QString m_data, QString m_sdept)
{
	if (!check(m_sno, 12))
	{
		qDebug() << "存取学号失败";
	}
	if (!(check(m_name, 2) || check(m_name, 3)))
	{
		qDebug() << "存取姓名失败";
	}
	this->sno = m_sno;
	this->name = m_name;
	this->sex = m_sex;
	this->data = m_data;
	this->sdept = m_sdept;
}

Student::Student(const Student& s)
{
	this->sno = s.sno;
	this->name = s.name;
	this->sex = s.sex;
	this->data = s.data;
	this->sdept = s.sdept;
}

Student::~Student()
{}

void Student::setSno(QString m_sno)
{
	if (!check(m_sno, 12))
	{
		qDebug() << "存取学号失败";
		return;
	}
	this->sno = m_sno;
}

QString Student::getSno()
{
	return this->sno;
}

void Student::setName(QString m_name)
{
	if (!(check(m_name, 3) || check(m_name, 2)))
	{
		qDebug() << "存取姓名失败，姓名不符合规则";
	}
	this->name = m_name;
}

QString Student::getName()
{
	return this->name;
}

void Student::setSex(QString m_sex)
{
	if (!check(m_sex, 1))
	{
		qDebug() << "输入的性别类型不对";
		return;
	}
	this->sex = m_sex;
}

QString Student::getSex()
{
	return this->sex;
}

void Student::setData(QString m_data)
{
	this->data = m_data;
}

QString Student::getData()
{
	return this->data;
}

void Student::setSdept(QString m_Sdept)
{
	this->sdept = m_Sdept;
}

QString Student::getSdept()
{
	return this->sdept;
}

bool Student::check(QString str, int len)
{
	if (str.size() == len)
	{
		return true;
	}
	qDebug() << "输入的数据类型不合理";
	return false;
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		this->sno = other.sno;
		this->name = other.name;
		this->sex = other.sex;
		this->data = other.name;
		this->sdept = other.sdept;
	}
	return *this;
}

void Student::printInformation()
{
	qDebug() << this->sno << " " << this->name << " " << this->sex << " " << this->data << " " << this->sdept;
}
