#include "CodeAnalyse.h"
#include <QRegularExpression>

CodeAnalyse::CodeAnalyse(QObject *parent)
	: QObject(parent)
{}

CodeAnalyse::CodeAnalyse()
{
}

CodeAnalyse::~CodeAnalyse()
{}

void CodeAnalyse::analyseOneLine(QString line)
{
	//
}

bool CodeAnalyse::containsPunctuation(QString str)
{
	// 构建一个正则表达式，匹配除了空格以外的所有标点符号
	QRegularExpression regex("[^\\s\\w]+");

	// 使用正则表达式匹配输入字符串
	QRegularExpressionMatch match = regex.match(str);

	// 如果匹配到了除了空格以外的标点符号，返回 true
	return match.hasMatch();
}

bool CodeAnalyse::containsNonSemicolonPunctuation(QString str)
{
	// 构建一个正则表达式，匹配除了分号以外的所有标点符号
	QRegularExpression regex("[^;\\s\\w]+");

	// 使用正则表达式匹配输入字符串
	QRegularExpressionMatch match = regex.match(str);

	// 如果匹配到了除了分号以外的标点符号，返回 true
	return match.hasMatch();
}
