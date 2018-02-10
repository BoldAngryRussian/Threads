// ObjectAsAParam.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Task.h"


int main()
{
	std::cout << "[" << std::this_thread::get_id() << "] Main function starts...." << std::endl;

	VTHREADS vThreads;
	vThreads.reserve(25);

	// заполняем контейнер объектами потоков
	for (int i = 0; i < 20; i++)
	vThreads.push_back(CTask::get());

	// джойним сосновным потоком
	for (auto &it : vThreads)
	if (it.joinable()) it.join();
	

	int value(0);
	std::cin >> value;

    return 0;
}

