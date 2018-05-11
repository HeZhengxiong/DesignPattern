/*����

Sunny�����˾������Java���Կ���һ��ͼ��⣬
��ͼ������ΪӦ��ϵͳ�ṩ���ֲ�ͬ��۵�ͼ��������״ͼ����״ͼ������ͼ�ȡ�
Sunny�����˾ͼ��������Աϣ��ΪӦ��ϵͳ������Ա�ṩһ��������õ�ͼ��⣬
���ҿ��Խ�Ϊ����ض�ͼ��������չ���Ա��ܹ��ڽ�������һЩ�����͵�ͼ��

��һ�����ƴ�������:

class Chart {

	private String type; //ͼ������

	public Chart(Object[][] data, String type) {
		this.type = type;
		if (type.equalsIgnoreCase("histogram")) {
		//��ʼ����״ͼ
		}
		else if (type.equalsIgnoreCase("pie")) {
		//��ʼ����״ͼ
		}
		else if (type.equalsIgnoreCase("line")) {
		//��ʼ������ͼ
		}
	}

	public void display() {
		if (this.type.equalsIgnoreCase("histogram")) {
		//��ʾ��״ͼ
		}
		else if (this.type.equalsIgnoreCase("pie")) {
		//��ʾ��״ͼ
		}
		else if (this.type.equalsIgnoreCase("line")) {
		//��ʾ����ͼ
		}
	}

};

�Ż������ݼ򵥹���ģʽ�Ըô�������ع�
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
		std::cout << "����ֱ��ͼ" << std::endl;
	}

	virtual void display() override
	{
		std::cout << "��ʾֱ��ͼ" << std::endl;
	}
};


class PieChart : public Chart
{
public:
	PieChart()
	{
		std::cout << "������ͼ" << std::endl;
	}

	virtual void display() override
	{
		std::cout << "��ʾ��ͼ" << std::endl;
	}
};


class LineChart : public Chart
{
public:
	LineChart()
	{
		std::cout << "��������ͼ" << std::endl;
	}

	virtual void display() override
	{
		std::cout << "��ʾ����ͼ" << std::endl;
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