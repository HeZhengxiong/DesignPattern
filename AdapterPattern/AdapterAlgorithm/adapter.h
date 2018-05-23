#ifndef adapter_h__
#define adapter_h__

/*
Sunny软件公司在很久以前曾开发了一个算法库，
里面包含了一些常用的算法，例如排序算法和查找算法，
在进行各类软件开发时经常需要重用该算法库中的算法。
在为某学校开发教务管理系统时，开发人员发现需要对学生成绩进行排序和查找，
该系统的设计人员已经开发了一个成绩操作接口ScoreOperation，
在该接口中声明了排序方法sort(int[]) 和查找方法search(int[], int)，
为了提高排序和查找的效率，开发人员决定重用算法库中的快速排序算法类QuickSort和二分查找算法类BinarySearch，
其中QuickSort的quickSort(int[])方法实现了快速排序，
BinarySearch 的binarySearch (int[], int)方法实现了二分查找。

由于某些原因，
现在Sunny公司开发人员已经找不到该算法库的源代码，
无法直接通过复制和粘贴操作来重用其中的代码；
部分开发人员已经针对ScoreOperation接口编程，
如果再要求对该接口进行修改或要求大家直接使用QuickSort类和BinarySearch类将导致大量代码需要修改。

Sunny软件公司开发人员面对这个没有源码的算法库，
遇到一个幸福而又烦恼的问题：
如何在既不修改现有接口又不需要任何算法库代码的基础上能够实现算法库的重用？
*/

#include <iostream>

class ScoreOperation
{
public:
	virtual ~ScoreOperation(){ }
	virtual int* sort(int arr[]) = 0;
	virtual int search(int arr[], int key) = 0;
};


class QuickSort
{
public:
	int* quickSort(int arr[])
	{
		std::cout << "quick sort implemented!" << std::endl;
		return arr;
	}
};


class BinarySearch
{
public:
	int binarySearch(int arr[], int key)
	{
		std::cout << "binary search implemented!" << std::endl;
		return 1;
	}
};



class OperationAdapter : public ScoreOperation
{
private:
	QuickSort*	_quickSort;
	BinarySearch*	_binarySarch;

public:
	OperationAdapter()
	{
		_quickSort = new QuickSort();
		_binarySarch = new BinarySearch();
	}

	virtual int* sort(int arr[]) override
	{
		_quickSort->quickSort(arr);
		return arr;
	}

	virtual int search(int arr[], int key) override
	{
		return _binarySarch->binarySearch(arr, key);
	}
};




#endif // adapter_h__
