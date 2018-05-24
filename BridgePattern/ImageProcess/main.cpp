#include "image.h"


int main()
{
    Image *image = new PNGImage();
    WindowsImpl *windowImpl = new WindowsImpl();
    image->setImageImpl(windowImpl);
    image->parseFile("c:/windows/test.png");
}