#include "EncryFile.h"

int main()
{
    EncryptFacade *fa  = new EncryptFacade();
    fa->fileEncrypt("C:/1.txt", "d:/encrypt.txt");
}