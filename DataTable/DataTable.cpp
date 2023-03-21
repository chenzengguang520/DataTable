
#include "DataTable.h"
#include <QTableWidgetItem>
#include <QPushButton>


DataTable::DataTable(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//获取数据
	GetFile* file = new GetFile(parent);
	
	qDebug() << "动态数组开始创建";
	QVector<Student> s;
	qDebug() << "动态数组创建完成";
	s = file->getStudents();
	qDebug() << "动态数组赋值完成";
	
	//for (auto it = s.begin(); it != s.end(); it++)
	//{
	//	Student m_s(*it);
	//	qDebug() << m_s.getName();
	//}


	//展示数据
	//设置表头
	QTableWidget* myTable = new QTableWidget(0,5,this);
	QTableWidgetItem* item1 = new QTableWidgetItem(QString("学号"));
	QTableWidgetItem* item2 = new QTableWidgetItem(QString("姓名"));
	QTableWidgetItem* item3 = new QTableWidgetItem(QString("性别"));
	QTableWidgetItem* item4 = new QTableWidgetItem(QString("出生日期"));
	QTableWidgetItem* item5 = new QTableWidgetItem(QString("所在系"));
	myTable->setHorizontalHeaderItem(0, item1);
	myTable->setHorizontalHeaderItem(1, item2);
	myTable->setHorizontalHeaderItem(2, item3);
	myTable->setHorizontalHeaderItem(3, item4);
	myTable->setHorizontalHeaderItem(4, item5);
	myTable->resize(600, 500);


	//定义行号变量
	int num = 0;
	for (auto it = s.begin(); it != s.end(); it++)
	{

		Student m_s(*it);
		myTable->insertRow(num);
		myTable->setItem(num, 0, new QTableWidgetItem(m_s.getSno()));
		myTable->setItem(num, 1, new QTableWidgetItem(m_s.getName()));
		myTable->setItem(num, 2, new QTableWidgetItem(m_s.getSex()));
		myTable->setItem(num, 3, new QTableWidgetItem(m_s.getData()));
		myTable->setItem(num++, 4, new QTableWidgetItem(m_s.getSdept()));
		qDebug() << m_s.getName();
	}
	
}

DataTable::~DataTable()
{}
