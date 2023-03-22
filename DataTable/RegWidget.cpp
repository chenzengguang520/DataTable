#include "RegWidget.h"

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



	});
}

RegWidget::~RegWidget()
{}
