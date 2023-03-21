#include "DelStudent.h"
#include <QVector>
#include "Student.h"
#include "GetFile.h"
#include <qpushbutton.h>
#include <qdebug.h>
#include <QMessageBox.h>

DelStudent::DelStudent(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//提示输入数据的设置
	ui.delLine->setPlaceholderText("需要删除学生的学号");

	//建立删除按钮的联系
	connect(ui.delBtn, &QPushButton::clicked, this, [=]() {

		qDebug() << "点击了删除按钮";

		//通过两个动态数组实现对固定元素的删除
		QVector<Student>s1;
		QVector<Student>s2;
		s1 = (new GetFile(this))->getStudents();


		//检测输入的学号是否正确如果正确就对固定学生进行删除
		QString sno = ui.delLine->text();
		if (sno.size() != 12)
		{
			QMessageBox* box = new QMessageBox();
			box->setText("学号不对!请重新输入！");
			box->show();
		}
		else
		{
			for (auto it = s1.begin(); it != s1.end(); it++)
			{
				if (it->getSno() == sno)
				{
					continue;
				}
				s2.append(*it);
			}
			(new GetFile(this))->writeFile(s2);
		}



	});
}

DelStudent::~DelStudent()
{}
