#include "adapter.h"

int main()
{
	ScoreOperation *sc = new OperationAdapter();
	int arr[] = { 1, 2, 3, 3, 4 };
	sc->search(arr,1);
	sc->sort(arr);
}