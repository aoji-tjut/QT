#include "xml.h"

XML::XML()
{

}

//创建空xml文件
void XML::CreateXML(QString path)
{
	//创建文件对象
	QFile file(path);

	//若文件存在则返回
	if(file.exists())
	{
		cout << "文件已存在" << endl;
		return;
	}

	//只写打开
	if(!file.open(QIODevice::WriteOnly))
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//创建xml文件
	QDomDocument doc;

	//创建格式头 <?xml version="1.0" encoding="UTF-8"?>
	QDomProcessingInstruction ins;
	ins = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(ins);

	//创建根节点元素
	QDomElement root = doc.createElement("root");
	doc.appendChild(root);

	//保存
	QTextStream stream(&file);
	doc.save(stream, 4); //缩进4
	file.close();

}

void XML::AppendXML(QString path)
{
	//只读打开文件
	QFile file(path);
	if(!file.open(QIODevice::ReadOnly))
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//file与xml关联
	QDomDocument doc;
	if(!doc.setContent(&file))
	{
		cout << "文件关联失败" << endl;
		return;
	}

	file.close();								//关闭file
	QDomElement root = doc.documentElement();	//获取根节点元素

	//判断根节点下是否有子节点
	if(root.hasChildNodes())
	{
		//有子节点
		QDomElement last_elememt = root.lastChildElement();
		if(last_elememt.attribute("date") == QDateTime::currentDateTime().toString("yyyy-MM-dd"))
		{
			//同一天
			WriteTime(doc, last_elememt);
		}
		else
		{
			//不同天
			//创建新日期节点
			QDomElement element = doc.createElement("日期");									//创建元素
			QDomAttr attribute = doc.createAttribute("date");								//创建属性
			attribute.setNodeValue(QDateTime::currentDateTime().toString("yyyy-MM-dd"));	//设置属性值
			element.setAttributeNode(attribute);											//节点与属性关联
			root.appendChild(element);														//加入根节点

			//创建时间节点
			WriteTime(doc, element);
		}
	}
	else
	{
		//无子节点
		//创建日期节点
		QDomElement element = doc.createElement("日期");									//创建元素
		QDomAttr attribute = doc.createAttribute("date");								//创建属性
		attribute.setNodeValue(QDateTime::currentDateTime().toString("yyyy-MM-dd"));	//设置属性值
		element.setAttributeNode(attribute);											//节点与属性关联
		root.appendChild(element);														//加入根节点

		//创建时间节点
		WriteTime(doc, element);
	}

	//只写打开文件
	if(!file.open(QIODevice::WriteOnly))
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//保存文件
	QTextStream stream(&file);
	doc.save(stream, 4);
	file.close();
}

void XML::WriteTime(QDomDocument& doc, QDomElement& root)
{
	QDomElement element = doc.createElement("time");

	QDomText text;
	text = doc.createTextNode(QDateTime::currentDateTime().toString("hh:mm:ss"));
	element.appendChild(text);

	root.appendChild(element);
}

void XML::ReadXML(QString path)
{
	//只读打开文件
	QFile file(path);
	if(!file.open(QIODevice::ReadOnly))
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//file与xml关联
	QDomDocument doc;
	if(!doc.setContent(&file))
	{
		cout << "文件关联失败" << endl;
		return;
	}

	file.close();								//关闭file
	QDomElement root = doc.documentElement();	//获取根节点元素

	//判断根节点下是否有子节点
	if(root.hasChildNodes())
	{
		//找根节点的所有子节点(日期)
		QDomNodeList data_list = root.childNodes();
		for(int i = 0; i < data_list.size(); i++)
		{
			cout << data_list.at(i).toElement().attribute("date").toUtf8().data();	//属性值

			//子节点的子节点(时间)
			QDomNodeList time_list = data_list.at(i).toElement().childNodes();
			for(int i = 0; i < time_list.size(); i++)
			{
				cout << time_list.at(i).toElement().text().toUtf8().data();			//元素text
			}

			qDebug();
		}
	}
	else
	{
		cout << "无子节点" << endl;
	}
}
