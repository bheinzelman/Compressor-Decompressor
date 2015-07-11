#ifndef HUFF_MAN_EXCEPTION_H
#define HUFF_MAN_EXCEPTION_H

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