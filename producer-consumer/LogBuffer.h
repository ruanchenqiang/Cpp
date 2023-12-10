#ifndef LOGBUFFER_H
#define LOGBUFFER_H

#include <condition_variable>
#include <mutex>
#include <string>
#include <vector>

class LogBuffer {
public:
	using Buffer = std::vector<std::string>;
	
public:
	LogBuffer(size_t size);
	
	void push(const std::string& str);
	void push(const char* ptr, size_t len);
	Buffer pop_all();
	
	~LogBuffer();
	
private:
	size_t m_maxsize;
	
	Buffer m_buffer;
	std::mutex m_buffer_mtx;
	std::condition_variable m_buffer_not_empty;
	std::condition_variable m_buffer_not_full;
};

#endif // LOGBUFFER_H