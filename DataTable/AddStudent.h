#pragma once

#include <QMainWindow>
#include "ui_AddStudent.h"
#include "Student.h"

/*
使用QInputDialog
*/
class AddStudent : public QMainWindow
{
	Q_OBJECT

public:
	AddStudent(QWidget *parent = nullptr);
	~AddStudent();

private:
	Ui::AddStudentClass ui;

};
