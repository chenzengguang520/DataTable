#include "LogWidget.h"
#include <QPushButton>
#include "GetFile.h"
#include <QMessageBox>
#include "MainWidgets.h"
#include "RegWidget.h"

LogWidget::LogWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//建立登录按钮和主界面的联系
	connect(ui.logBtn, &QPushButton::clicked, this, [=]() {

		QString user = ui.userLine->text();
		QString passwd = ui.passwdLine->text();

		//获取所有的用户账号密码信息
		//建立一个map存储这些信息
		QMap<QString, QString>m;
		GetFile* file = new GetFile(parent);
		m = file->getInformation();

		//定义一个变量用来表示该用户名是否存在
		//flag1用来判断用户名是否存在，flag2用来判断密码是否正确
		bool flag1 = false;
		bool flag2 = false;
		for (auto it = m.constBegin();it != m.constEnd();it++)
		{
			if (user == it.key())
			{
				flag1 = true;
				if (passwd == it.value())
				{
					flag2 = true;
					break;
				}
			}
		}

		//如果用户名或密码不正确则给出相应的提示
		if (!flag1)
		{
			QMessageBox* box = new QMessageBox(this);
			box->setText("用户名不存在！");
			box->show();
		}
		else if (!flag2)
		{
			QMessageBox* box = new QMessageBox(this);
			box->setText("输入的密码不正确！");
			box->show();
		}
		else
		{
			MainWidgets* widget = new MainWidgets(this);
			this->close();
			widget->show();
		}
	});

	//建立注册按钮和注册界面的联系
	connect(ui.regBtn, &QPushButton::clicked, this, [=]() {

		RegWidget* reg = new RegWidget();
		reg->show();
	
	});
}

LogWidget::~LogWidget()
{}
