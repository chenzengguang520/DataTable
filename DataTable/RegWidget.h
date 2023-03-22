#pragma once

#include <QMainWindow>
#include "ui_RegWidget.h"

class RegWidget : public QMainWindow
{
	Q_OBJECT

public:
	RegWidget(QWidget *parent = nullptr);
	~RegWidget();

private:
	Ui::RegWidgetClass ui;
};
