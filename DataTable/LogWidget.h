#pragma once

#include <QMainWindow>
#include "ui_LogWidget.h"

class LogWidget : public QMainWindow
{
	Q_OBJECT

public:
	LogWidget(QWidget *parent = nullptr);
	~LogWidget();

private:
	Ui::LogWidgetClass ui;
};
