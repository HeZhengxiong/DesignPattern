/*需求：

Sunny软件公司欲基于Java语言开发一套图表库，
该图表库可以为应用系统提供各种不同外观的图表，例如柱状图、饼状图、折线图等。
Sunny软件公司图表库设计人员希望为应用系统开发人员提供一套灵活易用的图表库，
而且可以较为方便地对图表库进行扩展，以便能够在将来增加一些新类型的图表。

第一版的设计代码如下:

class Chart {

	private String type; //图表类型

	public Chart(Object[][] data, String type) {
		this.type = type;
		if (type.equalsIgnoreCase("histogram")) {
		//初始化柱状图
		}
		else if (type.equalsIgnoreCase("pie")) {
		//初始化饼状图
		}
		else if (type.equalsIgnoreCase("line")) {
		//初始化折线图
		}
	}

	public void display() {
		if (this.type.equalsIgnoreCase("histogram")) {
		//显示柱状图
		}
		else if (this.type.equalsIgnoreCase("pie")) {
		//显示饼状图
		}
		else if (this.type.equalsIgnoreCase("line")) {
		//显示折线图
		}
	}

};

优化：根据简单工厂模式对该代码进行重构
*/
#include <iostream>

class Chart
{
public:
	virtual void display() = 0;
};


class HistogramChart : public Chart
{
public:
	HistogramChart()
	{
		std::cout << "创建直方图" << std::endl;
	}

	virtual void display() override
	{
		std::cout << "显示直方图" << std::endl;
	}
};


class PieChart : public Chart
{
public:
	PieChart()
	{
		std::cout << "创建饼图" << std::endl;
	}

	virtual void display() override
	{
		std::cout << "显示饼图" << std::endl;
	}
};


class LineChart : public Chart
{
public:
	LineChart()
	{
		std::cout << "创建折线图" << std::endl;
	}

	virtual void display() override
	{
		std::cout << "显示折线图" << std::endl;
	}
};


class ChartFactory
{
public:
	static Chart* getChart(const std::string& chartString)
	{
		if (chartString == "histogram")
		{
			return new HistogramChart();
		}
		else if (chartString == "pie")
		{
			return new PieChart();
		}
		else if (chartString == "line")
		{
			return new LineChart();
		}

		return nullptr;
	}
};