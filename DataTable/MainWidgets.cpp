#include "MainWidgets.h"
#include <qpushbutton.h>
#include "DataTable.h"
#include "GetFile.h"
#include "AddStudent.h"
#include "FindStudent.h"
#include "DelStudent.h"
#include "ModifyStudent.h"
#include "IntegrityConstraint.h"

MainWidgets::MainWidgets(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//把显示数据的按钮和界面之间建立联系
	connect(ui.showBtn, &QPushButton::clicked, this, [=]() {

		DataTable* table = new DataTable();
		table->show();
		
	});

	//建立增加数据和界面之间的联系
	connect(ui.addBtn, &QPushButton::clicked, this, [=]() {

		AddStudent* addTable = new AddStudent();
		addTable->show();

	});

	//建立查找数据和界面之间的联系
	connect(ui.findBtn, &QPushButton::clicked, this, [=]() {

		FindStudent* findWidget = new FindStudent();
		findWidget->show();

	});

	//建立删除数据和界面之间的联系
	connect(ui.delBtn, &QPushButton::clicked, this, [=]() {

		DelStudent* delWidget = new DelStudent();
		delWidget->show();

	});

	//建立修改数据和界面的联系
	connect(ui.modBtn, &QPushButton::clicked, this, [=]() {

		ModifyStudent* modifyWidget = new ModifyStudent();
		modifyWidget->show();
		
	});
}

MainWidgets::~MainWidgets()
{}
