#pragma once

#include <QMainWindow>
#include "ui_DelStudent.h"

class DelStudent : public QMainWindow
{
	Q_OBJECT

public:
	DelStudent(QWidget *parent = nullptr);
	~DelStudent();

private:
	Ui::DelStudentClass ui;
};
