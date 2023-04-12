#include "CodeWidget.h"
#include "QDebug"
#include <QAction>
#include <QMenu>
#include <QTextEdit>

CodeWidget::CodeWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	//点击运行之后开始运行代码
	connect(ui.actionrun, &QAction::triggered, this, [=]() {

		QString text = ui.textEdit->toPlainText();
		qDebug() << text;

	});
}

CodeWidget::~CodeWidget()
{}
