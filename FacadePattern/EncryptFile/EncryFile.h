#include <string>
#include <iostream>

class FileReader
{
public:
	std::string readFile(const std::string& fileName)
	{
		std::cout << "reding file " << std::endl;
		return "readed file content";
	}
};

class CipherMachine
{
public:
	std::string encryptContent(const std::string& content)
	{
		std::cout << "Encrypting file content" << std::endl;
		return "Encrypt file content";
	}
};


class FileWriter
{
	public:
		void writeFile(const std::string encryptedString, const std::string& fileURL)
		{
			std::cout << "saving encryptContent to file:" << fileURL << std::endl;
		}
};


class EncryptFacade
{
	public:
		EncryptFacade()
		{
			_reader = new FileReader();
			_machine = new CipherMachine();
			_fileWriter = new FileWriter();
		} 

		void fileEncrypt(const std::string fileNameSrc, const std::string fileSaveURL)
		{
			const std::string content = _reader->readFile(fileNameSrc);
			const std::string fileEncryptContent = _machine->encryptContent(content);
			_fileWriter->writeFile(fileEncryptContent, fileSaveURL);
		}

	protected:
		FileReader *		_reader;
		CipherMachine *		_machine;
		FileWriter*			_fileWriter;

};



