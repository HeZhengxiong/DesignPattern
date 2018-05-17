#ifndef skin_h__
#define skin_h__

/*
Sunny�����˾������һ�׽���Ƥ���⣬
���Զ�Java����������н���������
Ϊ�˱�����Ȩ����Ƥ����Դ���벻���㹫����
��ֻ���û��ṩ�Ѵ��Ϊjar�ļ���class�ֽ����ļ���
�û���ʹ��ʱ����ͨ���˵���ѡ��Ƥ����
��ͬ��Ƥ�����ṩ�Ӿ�Ч����ͬ�İ�ť���ı�����Ͽ�Ƚ���Ԫ�أ�
��ṹʾ��ͼ��ͼ��ʾ��

                                  ----ǳ��ɫ��ť
                                 |
          --------Spring���------|----��ɫ�߿��ı���
         |                       |
         |                        -----��ɫ�߿���Ͽ�
Ƥ����----|
         |
		|                         |----ǳ��ɫ��ť
		----------Summer���-------|----��ɫ�߿��ı���
                                   -----��ɫ�߿���Ͽ�
*/

#include <iostream>

class Button
{
public:
	virtual ~Button(){ }
	virtual void display() = 0;
};


class SpringButton : public Button
{
public:
	virtual void display() override
	{
		std::cout << "Spring green button" << std::endl;
	}
};

class SummerButton : public Button
{
	virtual void display() override
	{
		std::cout << "Summer blue button" << std::endl;
	}
};


class TextField
{
public:
	virtual ~TextField(){ }
	virtual void display() = 0;
};


class SpringTextField : public TextField
{
public:
	virtual void display() override
	{
		std::cout << "spring green text field" << std::endl;
	}
};

class SummerTextField : public TextField
{
public:
	virtual void display() override
	{
		std::cout << "summer blue text field" << std::endl;
	}
};


class ComboBox
{
public:
	virtual ~ComboBox() { }
	virtual void display() = 0;
};

class SpringComboBox : public ComboBox
{
public:
	virtual void display() override
	{
		std::cout << "spring green combobox" << std::endl;
	}
};

class SummerComboBox : public ComboBox
{
public:
	virtual void display() override
	{
		std::cout << "summer blue combobox" << std::endl;
	}
};


//////////////////////////////////////////////////////////////////////////
//Skin Factory

class SkinFactory
{
public:
	virtual ~SkinFactory(){ }
	
	virtual Button*		createButton() = 0;
	virtual TextField*	createTextField() = 0;
	virtual ComboBox*		createComboBox() = 0;
};


//spring factory
class SpringFactory : public SkinFactory
{
public:
	Button* createButton() override
	{
		return new SpringButton();
	}

	TextField* createTextField() override
	{
		return new SpringTextField();
	}

	ComboBox* createComboBox() override
	{
		return new SpringComboBox();
	}
};

//summer factory
class SummerFactory : public SkinFactory
{
public:
	Button* createButton() override
	{
		return new SummerButton();
	}

	TextField* createTextField() override
	{
		return new SummerTextField();
	}

	ComboBox* createComboBox() override
	{
		return new SummerComboBox();
	}
};


#endif // skin_h__
