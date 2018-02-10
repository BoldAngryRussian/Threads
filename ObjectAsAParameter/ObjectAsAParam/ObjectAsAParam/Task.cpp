#include "stdafx.h"
#include "Task.h"

// определяем статическую переменную
int CTask::m_counter = 0;
std::mutex CTask::m_mutex;


void CTask::do_it()
{
	auto id = std::this_thread::get_id();
	std::cout << "[" << id << "] working..." << std::endl;

	// Область видимости объекта блокировки ресурса
	{
		std::lock_guard<std::mutex> guard(m_mutex);
		std::cout << "[" << id << "] " << "counter : " << m_counter++ << std::endl;
	}

	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "[" << id << "] stopped..." << std::endl;

}

std::thread CTask::get()
{
	// созаем объект рабочего потока
	CTask task;
	std::thread thread(&CTask::do_it, &task);
	return thread;
}