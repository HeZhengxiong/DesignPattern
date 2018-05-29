#ifndef iterator_h__
#define iterator_h__

/*
Sunny软件公司为某商场开发了一套销售管理系统，
在对该系统进行分析和设计时，
Sunny软件公司开发人员发现经常需要对系统中的商品数据、
客户数据等进行遍历，为了复用这些遍历代码，
Sunny公司开发人员设计了一个抽象的数据集合类AbstractObjectList，
而将存储商品和客户等数据的类作为其子类，
*/

#include <vector>
#include <string>


template<typename T>
class AbstractIterator
{
public:
	virtual ~AbstractIterator(){ }

	virtual void next() = 0;
	virtual bool isLast() = 0;
	virtual void previous() = 0;
	virtual bool isFirst() = 0;
	virtual T getCurrentItem() = 0;
	virtual T getReverseItem() = 0;

};




template<typename T>
class AbstractObjectList
{
public:
	AbstractObjectList(std::vector<T> objects) : _objects(objects){ }

	void addObject(T obj)
	{
		_objects.push_back(obj);
	}

	void removeObj(T obj)
	{
		auto iter = std::find(_objects.begin(), _objects.end(), obj);
		if (iter != _objects.end())
			_objects.erase(iter);
	}

	std::vector<T> getObjects()
	{
		return _objects;
	}

	virtual AbstractIterator<T>* createIterator() = 0;


protected:
	std::vector<T>	_objects;
};




template<typename T>
class ProductList : public AbstractObjectList < T >
{
public:
	ProductList(std::vector<T> l) : AbstractObjectList<T>(l){ }

	AbstractIterator<T>*	createIterator(){
		return new ProductIterator<T>(this);
	}

};




template<typename T>
class ProductIterator : public AbstractIterator < T >
{
public:
	ProductIterator(ProductList<T> *l) : _productList(l)
	{
		_cursor = 0;
		_reverseCursor = _productList->getObjects().size() - 1;
	}

	virtual void next()
	{
		if (_cursor < _productList->getObjects().size())
			++_cursor;
	}


	virtual bool isLast()
	{
		return _cursor == _productList->getObjects().size();
	}

	virtual void previous()
	{
		if (_reverseCursor >= 0)
			--_reverseCursor;
	}
	virtual bool isFirst()
	{
		return _reverseCursor == -1;
	}

	T getCurrentItem()
	{
		return _productList->getObjects().at(_cursor);
	}

	T getReverseItem()
	{
		return _productList->getObjects().at(_reverseCursor);
	}


protected:
	int _cursor;
	int _reverseCursor;
	ProductList<T> *_productList;
};




#endif // iterator_h__
