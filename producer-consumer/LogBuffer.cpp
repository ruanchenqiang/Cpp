#include "LogBuffer.h"

LogBuffer::LogBuffer(size_t maxsize)
{
	m_maxsize = maxsize;
	m_buffer.reserve(m_maxsize);
}

void LogBuffer::push(const std::string& str)
{
	LogBuffer::push(str.c_str(), str.size());
}

void LogBuffer::push(const char* ptr, size_t len)
{
	std::unique_lock<std::mutex> lock(m_buffer_mtx);
	
	{
		if(m_buffer.size() >= m_maxsize) {
			// 等待收到消费者的通知
			m_buffer_not_full.wait(lock, [this](){ return m_buffer.size() < m_maxsize; });
		}
		
		m_buffer.push_back(std::string{ptr, len});
		
		// 通知消费者
		lock.unlock();
		m_buffer_not_empty.notify_one();
	}
}

LogBuffer::Buffer LogBuffer::pop_all()
{
	Buffer out;
	out.reserve(m_maxsize);

	{
		std::unique_lock<std::mutex> lock(m_buffer_mtx);
		
		if(m_buffer.empty()) {
			// 等待超时 或者 收到生产者的通知
			m_buffer_not_empty.wait_for(lock, std::chrono::milliseconds(50), [this](){ return not m_buffer.empty(); });
		}
		
		out.swap(m_buffer);
		
		// 通知生产者
		lock.unlock();
		m_buffer_not_full.notify_one();
	}

	return out;
}

LogBuffer::~LogBuffer()
{
	
}