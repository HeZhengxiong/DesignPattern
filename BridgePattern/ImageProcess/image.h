/*

      Sunny软件公司欲开发一个跨平台图像浏览系统，
      要求该系统能够显示BMP、JPG、GIF、PNG等多种格式的文件，
      并且能够在Windows、Linux、Unix等多个操作系统上运行。
      系统首先将各种格式的文件解析为像素矩阵(Matrix)，
      然后将像素矩阵显示在屏幕上，
      在不同的操作系统中可以调用不同的绘制函数来绘制像素矩阵。
      系统需具有较好的扩展性以支持新的文件格式和操作系统。

*/


#include <iostream>
#include <string>

class Matrix
{
    public:
        Matrix(){ }
};

class ImageImpl
{
    public:
        virtual void doPaint(Matrix* m) = 0;
};

class Image
{
    public:

        void setImageImpl(ImageImpl* impl){ _impl = impl;}
        virtual ~Image() { }
        virtual void parseFile(const std::string& fileName) = 0;

    protected:
        ImageImpl   *_impl;
};


class JPGImage : public Image
{
    public:
       virtual void parseFile(const std::string& fileName)
       {
           Matrix *m = new Matrix();
           _impl->doPaint(m);
           std::cout << fileName + ": JPG" << std::endl;
       }
};

class PNGImage : public Image
{
    public:
       virtual void parseFile(const std::string& fileName)
       {
           Matrix *m = new Matrix();
           _impl->doPaint(m);
           std::cout << fileName + ": PNG" << std::endl;
       }
};


class GIFImage : public Image
{
    public:
       virtual void parseFile(const std::string& fileName)
       {
           Matrix *m = new Matrix();
           _impl->doPaint(m);
           std::cout << fileName + ": GIF" << std::endl;
       }
};


class BMPImage : public Image
{
    public:
       virtual void parseFile(const std::string& fileName)
       {
           Matrix *m = new Matrix();
           _impl->doPaint(m);
           std::cout << fileName + ": BMP" << std::endl;
       }
};


class WindowsImpl : public ImageImpl
{
    public:
        virtual void doPaint(Matrix* m) override
        {
            std::cout << "Windows do Matrix" << std::endl;
        }
};

class LinuxImpl : public ImageImpl
{
    public:
        virtual void doPaint(Matrix *m)
        {
            std::cout << "Linux do Matrix" << std::endl;       
        }
};

class UnixImpl : public ImageImpl
{
    public:
        virtual void doPaint(Matrix* m)
        {
            std::cout << "Unix do matirx" << std::endl;
        }
};

