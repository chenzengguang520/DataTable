﻿#include "CodeAnalyse.h"
#include "QDebug.h"
#include "GetFile.h"
#include <QMessageBox>

CodeAnalyse::CodeAnalyse(QObject *parent)
	: QObject(parent)
{}

CodeAnalyse::CodeAnalyse()
{
}

void CodeAnalyse::hintError(QString error)
{
	QMessageBox* box = new QMessageBox();
	box->setText(error);
	box->show();
}

// Create 命令
void CodeAnalyse::analyseCode(QString code)
{
	qDebug() << "调用了词法分析";
	int length = code.size();
	qDebug() << "length = " << length;
	int len = code.split(" ").count();
	qDebug() << "code[len] = "<<code[length - 1];
	if (code[length - 1] != ';')
	{
		hintError("Code is incomplete and missing ;");
		return;
	}
	QStringList str = code.split(" ");
	qDebug() << str;
	GetFile* file = new GetFile();
	
	// create命令
	// 确定动作
	int order = getAction("Action", str[0]);
	
	//create命令 order = 1
	if (order == 1)
	{
		qDebug() << "成功进入order选项";
		int command = getAction("Command", str[1]);
		//创建表格命令 command = 1
		if (command == 1)
		{
			qDebug() << "成功进入command命令";
			//需要创建的表格名称
			QStringList codeList = str[2].split("(");
			QString name = codeList[0];
			qDebug() << "name = "<<name;
			//提取括号里面的字符串信息
			int begin = code.indexOf("(");
			int end = code.indexOf(")");
			//判断括号是否完整
			if (begin < 0 && end >= 0)
			{
				hintError("not find (");
				return;
			}
			if (begin < 0 && end < 0)
			{
				hintError("Code is incomplete and missing ()");
				return;
			}
			if (begin >= 0 && end < 0) 
			{
				hintError("not find )");
				return;
			}
			QChar ch = code[end - 1];
			if (ch == ',')
			{
				hintError("Variable definitions are incomplete");
				return;
			}
			qDebug() << "begin = " << begin << "end = " << end;
			if (end - begin > 1)
			{
				QString content = code.mid(begin + 1, end - begin - 1);
				qDebug() << content;
				//获取遍历类别和遍历名信息
				QStringList var = content.split(",");
				qDebug() << var;
				qDebug() << var.count();
				QMap<QString, QString>m;
				for (int i = 0; i < var.count(); i++)
				{
					if (getVairable(var[i].split(" ")[0]))
					{
						m[var[i].split(" ")[1]] = var[i].split(" ")[0];
					}
					else
						return;
				}
				//调用function生成表格
				file->createTable(name, m);
				qDebug() << "create table 命令运行成功";
			}
			else
			{
				hintError("() is empty！");
			}
		}
	}
	
}

int CodeAnalyse::getAction(QString command,QString code)
{
	GetFile* file = new GetFile();
	QVector<QString>v = file->getList(command);
	int num = 0;
	for (auto it = v.begin();it != v.end();it++,num++)
	{
		if (*it == code)
		{
			return num + 1;
		}
	}
	QString error = code + " is not define";
	hintError(error);
	return 0;
}
bool CodeAnalyse::getVairable(QString code)
{
	GetFile* file = new GetFile();
	QVector<QString>v = file->getList("Vairable");
	int num = 0;
	for (auto it = v.begin(); it != v.end(); it++, num++)
	{
		if (*it == code)
		{
			return true;
		}
	}
	QString error = code + " is not a legal variable";
	hintError(error);
	return false;
}
CodeAnalyse::~CodeAnalyse()
{}
