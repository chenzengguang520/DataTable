#pragma once

#include <QObject>
#include "Student.h"
#include <QVector>

class Students  : public QObject
{
	Q_OBJECT
private:
	QVector<Student> s;

public:
	Students(QObject *parent);
	~Students();
};
