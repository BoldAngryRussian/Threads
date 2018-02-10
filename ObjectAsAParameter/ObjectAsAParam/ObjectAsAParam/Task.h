#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// This class is disagned to do some task
// in a new thread
class CTask
{
public:
	CTask() { ; }
	~CTask() { ; }
	//������� ������� �������� ������
	void do_it();
	// ������� ����� � �������
	static std::thread get();
private:
	static int m_counter;			// ������������ ������ � ����� ���������� ���� �������
	static std::mutex m_mutex;		// ������ ������������� �������
};

//��������� �������
typedef std::vector<std::thread> VTHREADS;



