#ifndef HUFF_MAN_EXCEPTION_H
#define HUFF_MAN_EXCEPTION_H


#ifdef _WIN32
#define EXCEPTION(s) std::exception()
#else
#define EXCEPTION(s) std::exception()
#endif

#include <exception>
#include <string>

class HuffmanException : public std::exception {
public:
	HuffmanException(const char *msg) : err_msg(msg) {};

	~HuffmanException() throw() {};

	const char *what() const throw() { return this->err_msg.c_str(); };
private:
	std::string err_msg;
};
#endif
