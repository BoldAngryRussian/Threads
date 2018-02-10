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
	//рабочая функция рабочего потока
	void do_it();
	// Создаем поток с задачей
	static std::thread get();
private:
	static int m_counter;			// демонстрация роботы с общей переменной пула потоков
	static std::mutex m_mutex;		// объект синхронизации доступа
};

//контейнер потоков
typedef std::vector<std::thread> VTHREADS;



