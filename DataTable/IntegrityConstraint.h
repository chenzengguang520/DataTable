//完整性约束

#pragma once

#include <QObject>

class IntegrityConstraint  : public QObject
{
	Q_OBJECT

public:
	IntegrityConstraint(QObject *parent);
	~IntegrityConstraint();

	//
};
