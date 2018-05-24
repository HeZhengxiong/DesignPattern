#ifndef antivirus_h__
#define antivirus_h__

/*
Sunny�����˾������һ��ɱ��(AntiVirus)�����
������ȿ��Զ�ĳ���ļ���(Folder)ɱ����
Ҳ���Զ�ĳ��ָ�����ļ�(File)����ɱ����
��ɱ����������Ը��ݸ����ļ����ص㣬
Ϊ��ͬ���͵��ļ��ṩ��ͬ��ɱ����ʽ��
����ͼ���ļ�(ImageFile)���ı��ļ�(TextFile)��ɱ����ʽ���������졣
����Ҫ�ṩ��ɱ���������������Ʒ�����
*/


#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>


class AbstractFile
{
public:
	virtual ~AbstractFile(){ }

	virtual void add(AbstractFile *file) = 0;
	virtual void remove(AbstractFile *file) = 0;
	virtual AbstractFile* getChild(int i) = 0;
	virtual void killVirus() = 0;
};


class ImageFile : public AbstractFile
{
private:
	std::string	_name;

public:
	ImageFile(const std::string& name)
	{
		_name = name;
	}

	void add(AbstractFile *file)
	{
		std::cout << "Cannot add file" << std::endl;
	}

	void remove(AbstractFile *file)
	{
		std::cout << "Cannot remove file" << std::endl;
	}

	AbstractFile* getChild(int i)
	{
		std::cout << "Cannot get child" << std::endl;
		return nullptr;
	}

	void killVirus()
	{
		std::cout << "Killing virus for Image File " << _name << std::endl;
	}
};



class TextFile : public AbstractFile
{
public:
	TextFile(const std::string& name)
	{
		_name = name;
	}

	void add(AbstractFile *file)
	{
		std::cout << "Text File cannot add child" << std::endl;
	}

	void remove(AbstractFile *file)
	{
		std::cout << "Text File cannot remove child" << std::endl;
	}

	AbstractFile* getChild(int i)
	{
		std::cout << "Text File cannot get child" << std::endl;
		return nullptr;
	}

	void killVirus()
	{
		std::cout << "Killing Virus for text file " << _name << std::endl;
	}


private:
	std::string		_name;
};


class Folder : public AbstractFile
{
private:
	std::string _name;
	std::vector<AbstractFile*> _fileList;

public:
	Folder(const std::string& fileName) : _name(fileName){ }

	void add(AbstractFile *file){ _fileList.push_back(file); }
	void remove(AbstractFile *file)
	{
		auto iter = std::find(_fileList.begin(), _fileList.end(), file);
		if (iter != _fileList.end())
			_fileList.erase(iter);
	}

	AbstractFile* getChild(int i)
	{
		return _fileList.at(i);
	}

	void killVirus()
	{
		std::cout << "Directory killing virus: " << std::endl;
		for (auto iter : _fileList)
		{
			iter->killVirus();
		}
	}

};



#endif // antivirus_h__
