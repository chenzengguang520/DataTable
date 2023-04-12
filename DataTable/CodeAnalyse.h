#pragma once

#include <QObject>

class CodeAnalyse  : public QObject
{
	Q_OBJECT

public:
	CodeAnalyse(QObject *parent);
	CodeAnalyse();
	~CodeAnalyse();

	//一句一句的词法分析
	void analyseOneLine(QString line);

	//检测是否存在空格
	bool containsPunctuation(QString str);
};
