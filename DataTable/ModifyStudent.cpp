#include "ModifyStudent.h"
#include <qpushbutton.h>
#include <QMEssageBOx>
#include <QVector>
#include "Student.h"
#include "GetFile.h"

ModifyStudent::ModifyStudent(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.snoLine1->setPlaceholderText("要修改学生的学号");
	ui.snoLine->setPlaceholderText("修改后的学号");
	ui.nameLine->setPlaceholderText("修改后的姓名");

	//建立确认按钮的联系
	connect(ui.okBtn, &QPushButton::clicked, this, [=]() {

		QString sno = ui.snoLine1->text();

		QString sno1 = ui.snoLine->text();
		QString name = ui.nameLine->text();
		QString sex = ui.sexBox->currentText();
		QString date = ui.dateEdit->text();
		QString sdept = ui.sdeptBox->currentText();

		QVector<Student>s;

		GetFile* file = new GetFile(this);
		//检测输入的学号是否正确
		if (sno.size() != 12)
		{
			QMessageBox* box = new QMessageBox();
			box->setText("学号不对!请重新输入！");
			box->show();
		}
		else
		{
			s = file->getStudents();
			for (auto it = s.begin(); it != s.end(); it++)
			{
				if (it->getSno() == sno)
				{
					it->setSno(sno1);
					it->setName(name);
					it->setSex(sex);
					it->setData(date);
					it->setSdept(sdept);
					break;
				}
			}
			file->writeFile(s);
		}


	});
}

ModifyStudent::~ModifyStudent()
{}
