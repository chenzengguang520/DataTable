#pragma once

#include <QMainWindow>
#include "ui_ModifyStudent.h"

class ModifyStudent : public QMainWindow
{
	Q_OBJECT

public:
	ModifyStudent(QWidget *parent = nullptr);
	~ModifyStudent();

private:
	Ui::ModifyStudentClass ui;
};
