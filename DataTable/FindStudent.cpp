#include "FindStudent.h"
#include "QPushButton.h"
#include <QMessageBox>
#include <QDebug>
#include "GetFile.h"

FindStudent::FindStudent(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置提示字符
	ui.findLine->setPlaceholderText("要查找学生的学号");

	//建立提交按钮的联系
	connect(ui.findBtn, &QPushButton::clicked, this, [=]() {

		qDebug() << "点击了提交按钮";
		QString sno = ui.findLine->text();

		//判断输入学号是否正确
		if (sno.size() != 12) 
		{
			
			QMessageBox* box = new QMessageBox();
			box->setText("学号不对!请重新输入！");
			box->show();
		}

		else
		{
			Student* s = new Student(this->findStudent(sno));
			if (s->getSno() == "111111111111")
			{
				qDebug() << "查找完成但是未查找到！";
				QMessageBox* box = new QMessageBox();
				box->setText("该学生不存在此系统中！");
				box->show();
			}
			else
			{
				s->printInformation();
				ui.snoLine->setText(s->getSno());
				ui.nameLine->setText(s->getName());
				ui.sexLine->setText(s->getSex());
				ui.dateLine->setText(s->getData());
				ui.sdeptLine->setText(s->getSdept());

			}

		}

	});
}

FindStudent::~FindStudent()
{}

Student& FindStudent::findStudent(QString sno)
{
	GetFile* file = new GetFile(this);
	QVector<Student> s;
	s = file->getStudents();
	for (auto it = s.begin();it != s.end();it++)
	{
		if (it->getSno() == sno)
		{
			Student* stu = new Student(*it);
			return *stu;
		}
	}
	QString m_sno = "111111111111";
	Student* m_s = new Student();
	m_s->setSno(m_sno);
	return *m_s;
}
