#include "RegWidget.h"
#include <QMessageBox>

RegWidget::RegWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	//建立确认按钮的联系
	connect(ui.logBtn, &QPushButton::clicked, this, [=]() {

		//定义变量接收信息
		QString user = ui.userLine->text();
		QString passwd = ui.passwdLine->text();
		QString accPasswd = ui.accPasswdLine->text();

		//判断密码和确认密码是否一致
		if (passwd != accPasswd)
		{
			QMessageBox* box = new QMessageBox(this);
			box->setText("两次密码输入不一致");
			box->show();
		}
		else 
		{
			//创建QMap容器存储用户名和密码
			QMap<QString, QString> m;
			m[user] = passwd;

			//建立GetFile对象对文件存储
			GetFile* file = new GetFile(this);
			file->WriteUser(m);

			//注册成功
			QMessageBox* box = new QMessageBox(this);
			box->setText("注册成功");
			box->show();

			ui.userLine->clear();
			ui.passwdLine->clear();
			ui.accPasswdLine->clear();

		}






	});
}

RegWidget::~RegWidget()
{}
