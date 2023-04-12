#pragma once

#include <QMainWindow>
#include "ui_CodeWidget.h"

class CodeWidget : public QMainWindow
{
	Q_OBJECT

public:
	CodeWidget(QWidget *parent = nullptr);
	~CodeWidget();

private:
	Ui::CodeWidgetClass ui;
};
