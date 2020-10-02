#ifndef XML_H
#define XML_H
#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDomDocument>                 //文件
#include <QDomProcessingInstruction>	//格式头
#include <QDomElement>                  //元素
#include <QDateTime>

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

class XML
{
public:
	XML();

	static void CreateXML(QString);
	static void AppendXML(QString);
	static void WriteTime(QDomDocument&, QDomElement&);
	static void ReadXML(QString);
};

#endif // XML_H
