#pragma once

#include <QObject>

class CodeAnalyse  : public QObject
{
	Q_OBJECT

public:
	CodeAnalyse(QObject *parent);
	CodeAnalyse();
	//报错信息提示
	void hintError(QString error);

	// 词法分析
	void analyseCode(QString code);

	// 动作命令分析
	int getAction(QString command, QString code);

	//判断用户输入的变量名是否存在
	bool getVairable(QString code);
	~CodeAnalyse();
};
