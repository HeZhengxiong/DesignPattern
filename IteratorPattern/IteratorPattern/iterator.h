#ifndef iterator_h__
#define iterator_h__

template<typename T>
class ConcreteAggregate;

template<typename T>
class Iterator
{
public:
	virtual ~Iterator(){ }

	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool hasNext() = 0;
	virtual T getCurrentItem() = 0;
};


template<typename T>
class ConcreteIterator : public Iterator<T>
{
public:
	ConcreteIterator(ConcreteAggregate* obj) : _objects(obj){}

	virtual void first(){ }
	virtual void next(){}
	virtual bool hasNext(){}
	T getCurrentItem(){ return T(); }


private:
	int _cursor;
	ConcreteAggregate*	_objects;
};


template<typename T>
class Aggregate
{
public:
	virtual ~Aggregate(){ }

	virtual Iterator<T>* createIterator() = 0;

};

template<typename T>
class ConcreteAggregate : public Aggregate<T>
{
public:
	virtual Iterator* createIterator()
	{
		return new ConcreteIterator(this);
	}
};



#endif // iterator_h__
