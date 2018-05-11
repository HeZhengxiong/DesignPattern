#include "chart.h"
#include "tinyxml2.h"

#include <string>


std::string getChartTypeStringFromConfigFile(const char *configFilePath)
{
	tinyxml2::XMLDocument doc;

	if (doc.LoadFile("config.xml") != tinyxml2::XML_SUCCESS)
	{
		std::cerr << "´ò¿ªXMLÊ§°Ü" << std::endl;
		exit(-1);
	}

	tinyxml2::XMLElement* chartTypeElement =
		doc.FirstChildElement("config")->FirstChildElement("chartType");

	std::string typeName = chartTypeElement->GetText();

	return typeName;
}


int main()
{
	Chart *chart = ChartFactory::getChart(getChartTypeStringFromConfigFile("config.xml"));
	chart->display();

	getchar();
	return 0;
}