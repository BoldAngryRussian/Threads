// ObjectAsAParam.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "Task.h"


int main()
{
	std::cout << "[" << std::this_thread::get_id() << "] Main function starts...." << std::endl;

	VTHREADS vThreads;
	vThreads.reserve(25);

	// ��������� ��������� ��������� �������
	for (int i = 0; i < 20; i++)
	vThreads.push_back(CTask::get());

	// ������� ��������� �������
	for (auto &it : vThreads)
	if (it.joinable()) it.join();
	

	int value(0);
	std::cin >> value;

    return 0;
}

