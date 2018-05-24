#include "antivirus.h"

int main()
{
	AbstractFile *cs1 = new Folder("cs1");
	AbstractFile *image1 = new ImageFile("image1");
	AbstractFile *text1 = new TextFile("text1");
	cs1->add(image1);
	cs1->add(text1);

	AbstractFile *	cs2 = new Folder("cs2");
	AbstractFile *image2 = new ImageFile("image2");
	cs2->add(cs1);
	cs2->add(image2);


	cs2->killVirus();
}