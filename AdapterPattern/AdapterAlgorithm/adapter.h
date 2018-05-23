#ifndef adapter_h__
#define adapter_h__

/*
Sunny�����˾�ںܾ���ǰ��������һ���㷨�⣬
���������һЩ���õ��㷨�����������㷨�Ͳ����㷨��
�ڽ��и����������ʱ������Ҫ���ø��㷨���е��㷨��
��ΪĳѧУ�����������ϵͳʱ��������Ա������Ҫ��ѧ���ɼ���������Ͳ��ң�
��ϵͳ�������Ա�Ѿ�������һ���ɼ������ӿ�ScoreOperation��
�ڸýӿ������������򷽷�sort(int[]) �Ͳ��ҷ���search(int[], int)��
Ϊ���������Ͳ��ҵ�Ч�ʣ�������Ա���������㷨���еĿ��������㷨��QuickSort�Ͷ��ֲ����㷨��BinarySearch��
����QuickSort��quickSort(int[])����ʵ���˿�������
BinarySearch ��binarySearch (int[], int)����ʵ���˶��ֲ��ҡ�

����ĳЩԭ��
����Sunny��˾������Ա�Ѿ��Ҳ������㷨���Դ���룬
�޷�ֱ��ͨ�����ƺ�ճ���������������еĴ��룻
���ֿ�����Ա�Ѿ����ScoreOperation�ӿڱ�̣�
�����Ҫ��Ըýӿڽ����޸Ļ�Ҫ����ֱ��ʹ��QuickSort���BinarySearch�ཫ���´���������Ҫ�޸ġ�

Sunny�����˾������Ա������û��Դ����㷨�⣬
����һ���Ҹ����ַ��յ����⣺
����ڼȲ��޸����нӿ��ֲ���Ҫ�κ��㷨�����Ļ������ܹ�ʵ���㷨������ã�
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
