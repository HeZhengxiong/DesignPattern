#ifndef skin_h__
#define skin_h__

/*
Sunny软件公司欲开发一套界面皮肤库，
可以对Java桌面软件进行界面美化。
为了保护版权，该皮肤库源代码不打算公开，
而只向用户提供已打包为jar文件的class字节码文件。
用户在使用时可以通过菜单来选择皮肤，
不同的皮肤将提供视觉效果不同的按钮、文本框、组合框等界面元素，
其结构示意图如图所示：

                                  ----浅绿色按钮
                                 |
          --------Spring风格------|----绿色边框文本框
         |                       |
         |                        -----绿色边框组合框
皮肤库----|
         |
		|                         |----浅蓝色按钮
		----------Summer风格-------|----蓝色边框文本框
                                   -----蓝色边框组合框
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
