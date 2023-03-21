#pragma once

#include <QMainWindow>
#include "ui_FindStudent.h"
#include "Student.h"

class FindStudent : public QMainWindow
{
	Q_OBJECT

public:
	FindStudent(QWidget *parent = nullptr);
	~FindStudent();

	//提供查找函数的接口
	Student& findStudent(QString sno);

private:
	Ui::FindStudentClass ui;
};
