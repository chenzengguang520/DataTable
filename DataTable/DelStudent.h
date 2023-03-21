#pragma once

#include <QObject>

class DelStudent  : public QObject
{
	Q_OBJECT

public:
	DelStudent(QObject *parent);
	~DelStudent();
};
