//完整性约束

#pragma once

#include <QObject>

class IntegrityConstraint  : public QObject
{
	Q_OBJECT

public:
	IntegrityConstraint(QObject *parent);
	~IntegrityConstraint();

	//判断是否是数字
	bool numberStandard(QString s);

	//判断学号是否符合要求
	bool snoStandard(QString sno);

	//判断姓名是否符合要求
	bool nameStandard(QString name);

	//判断是不是中文
	bool chineseStandard(QString s);

	//判断数据是否唯一
	bool dataIsOnly(QString majorKey = "sno");
};
