#include "IntegrityConstraint.h"
#include <QDebug>
#include "GetFile.h"
IntegrityConstraint::IntegrityConstraint(QObject *parent)
	: QObject(parent)
{}

IntegrityConstraint::~IntegrityConstraint()
{}

bool IntegrityConstraint::numberStandard(QString s)
{
	
	for (int i = 0;i < s.length();i++)
	{
		if (!(s[i] >= '0' && s[i] <='9'))
		{
			return false;
		}
	}
	return true;
}

bool IntegrityConstraint::snoStandard(QString sno)
{
	if (sno.length() != 12 || this->numberStandard(sno))
	{
		return false;
	}
	return true;
}

bool IntegrityConstraint::nameStandard(QString name)
{
	if (!((name.length() == 2 || name.length() == 3) && this->chineseStandard(name)))
	{
		return false;
	}
	return true;
}

bool IntegrityConstraint::chineseStandard(QString s)
{
	int nCount = s.count();
	for (int i = 0; i < nCount; i++) 
	{
		QChar cha = s.at(i);
		ushort uni = cha.unicode();
		if (!(uni >= 0x4E00 && uni <= 0x9FA5)) 
		{
			return false;
		}
	}
	return true;
}

bool IntegrityConstraint::dataIsOnly(QString majorKey)
{
	GetFile* file = new GetFile(this);
	QVector<QString>s = file->getData(majorKey);
	QMap<QString, int> m;
	for (auto it = s.begin();it != s.end();it++)
	{ 
		if (m[*it] != 0)
		{
			qDebug() << "主键不惟一!";
			return false;
		}
		m[*it] += 1;
	}
	qDebug() << "主键惟一！";
	return true;
}
