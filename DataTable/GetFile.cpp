#include "GetFile.h"
#include <qdebug.h>
#include <QFile>
#include <QTextStream>

GetFile::GetFile(QObject *parent)
	: QObject(parent)
{}

GetFile::~GetFile()
{}

void GetFile::test()
{
    // 打开文件
    QFile file("./table/test.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "无法打开文件！";
        return ;
    }

    // 创建文本流
    QTextStream stream(&file);
    //stream.setCodec("UTF-8"); // 设置编码方式


    // 逐行读取文件内容并输出到控制台
    QString line;
    while (!stream.atEnd())
    {
        line = stream.readLine();
        qDebug() << line;
    }

    // 关闭文件
    file.close();

}

void GetFile::test1()
{
	// 文件路径
	QString filePath = "./table/test.txt";

	// 打开文件，如果文件不存在则创建它
	QFile file(filePath);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
		return;

	// 创建一个 QTextStream，用于向文件写入数据
	QTextStream out(&file);

	// 写入数据到文件
	out << "Hello, world!";
}

void GetFile::test2()
{
	QString fileName = "./table/example.txt";
	QFile file(fileName);

	if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
	{
		QTextStream stream(&file);
		stream << "Hello World!\n";
		stream << "This is an example file!!!!.\n";
		file.close();
	}
}

void GetFile::addStudent(Student& s)
{
	// 文件路径
	QString filePath = "./table/test.txt";

	// 打开文件，如果文件不存在则创建它
	QFile file(filePath);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
		return;

	// 创建一个 QTextStream，用于向文件写入数据
	QTextStream out(&file);

	// 写入数据到文件
	out << s.getSno() <<" " << s.getName() <<" "<<s.getSex() << " " << s.getData() << " " << s.getSdept() << "\n";
}

QVector<Student>& GetFile::getStudents()
{
	// 打开文件
	QFile file("./table/test.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "无法打开文件！";
		return this->s;
	}

	// 创建文本流
	QTextStream stream(&file);
	//stream.setCodec("UTF-8"); // 设置编码方式


	// 逐行读取文件内容并输出到控制台
	QString line;

	//定义需要存储的变量
	QString name;
	QString sno;
	QString data;
	QString sex;
	QString sdept;

	while (!stream.atEnd())
	{
		line = stream.readLine(); 
		qDebug() << line;
		
		//存储变量
		sno = line.split(" ")[0];
		name = line.split(" ")[1];
		sex = line.split(" ")[2];
		data = line.split(" ")[3];
		sdept = line.split(" ")[4];
		qDebug() << sno << name << data << sdept;
		Student m_s(sno, name, sex,data, sdept);

		this->s.append(m_s);
		
	}

	// 关闭文件
	file.close();

	//返回存储学生信息的动态数组
	return this->s;
}

void GetFile::writeFile(QVector<Student> s)
{
	QString fileName = "./table/test.txt";
	QFile file(fileName);

	if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
	{
		QTextStream stream(&file);

		//遍历写入数据
		for (auto it = s.begin(); it != s.end(); it++)
		{
			stream << it->getSno() << " " << it->getName() << " " << it->getSex() << " " << it->getData() << " " << it->getSdept() << "\n";
		}
		file.close();
	}
}

QMap<QString, QString>& GetFile::getInformation()
{
	QString user;
	QString passwd;

	// 打开文件
	QFile file("./table/user.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "无法打开文件！";
		return this->m;

	}

	// 创建文本流
	QTextStream stream(&file);
	//stream.setCodec("UTF-8"); // 设置编码方式


	// 逐行读取文件内容并输出到控制台
	QString line;

	while (!stream.atEnd())
	{
		line = stream.readLine();
		user = line.split(" ")[0];
		passwd = line.split(" ")[1];

		qDebug() << user << " " << passwd;

		//存储变量
		this->m[user] = passwd;

	}

	// 关闭文件
	file.close();
	return this->m;

}
