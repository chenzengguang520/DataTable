#include "AddStudent.h"
#include <QInputDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include "GetFile.h"
#include "IntegrityConstraint.h"

AddStudent::AddStudent(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	ui.snoLine->setPlaceholderText("学号（12位数字）");
	ui.nameLine->setPlaceholderText("姓名");

	//创建完整性约束类
	IntegrityConstraint* inter = new IntegrityConstraint(this);


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
		else if (inter->dataIsOnly(sno) && inter-> nameStandard(name))
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
		else if(!inter->dataIsOnly(sno))
		{
			QMessageBox* box = new QMessageBox();
			box->setText("此学号已经存在！");
			box->show();
		}
		else
		{
			QMessageBox* box = new QMessageBox();
			box->setText("姓名不符合规范！");
			box->show();
		}
	});
}

AddStudent::~AddStudent()
{}
