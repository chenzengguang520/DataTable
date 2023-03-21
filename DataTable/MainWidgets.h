#pragma once

#include <QMainWindow>
#include "ui_MainWidgets.h"

class MainWidgets : public QMainWindow
{
	Q_OBJECT

public:
	MainWidgets(QWidget *parent = nullptr);
	~MainWidgets();

private:
	Ui::MainWidgetsClass ui;
};
