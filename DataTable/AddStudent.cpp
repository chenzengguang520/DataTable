#include "AddStudent.h"
#include <QInputDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include "GetFile.h"

AddStudent::AddStudent(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	ui.snoLine->setPlaceholderText("学号（12位数字）");
	ui.nameLine->setPlaceholderText("姓名");

	Student* s = new Student();
	connect(ui.submitBtn, &QPushButton::clicked, this, [=]() {
		
		qDebug() << "点击了提交按钮";
		QString sno = ui.snoLine->text();
		QString name = ui.nameLine->text();
		QString sex = ui.sexBox->currentText();
		QString data = ui.dateEdit->text();
		QString sdept = ui.sdeptBox->currentText();
		qDebug() << sno << name << data << sdept;
		if (sno.size() != 12)
		{
			QMessageBox* box = new QMessageBox();
			box->setText("学号不对!请重新输入！");
			box->show();
		}
		else
		{
			s->setSno(sno);
			s->setName(name);
			s->setSex(sex);
			s->setData(data);
			s->setSdept(sdept);
			QMessageBox* box = new QMessageBox();
			box->setText("添加成功！");
			box->show();
			ui.snoLine->clear();
			ui.nameLine->clear();
			GetFile* f = new GetFile(parent);
			f->addStudent(*s);
		}
	});
}

AddStudent::~AddStudent()
{}
