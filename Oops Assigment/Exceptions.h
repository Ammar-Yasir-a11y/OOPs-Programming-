#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <exception>
#include <string>

// 1. Exception thrown when a flight has no available seats left
class FlightFullException : public std::exception {
private:
    std::string message; // std:: lagaya line 12 par
public:
    FlightFullException(std::string msg) : message(msg) {} // std:: lagaya line 14 par

    virtual ~FlightFullException() throw() {} 

    const char* what() const throw() override {
        return message.c_str();
    }
};

// 2. Exception thrown when a cancellation is invalid
class InvalidCancellationException : public std::exception {
private:
    std::string message; // std:: lagaya
public:
    InvalidCancellationException(std::string msg) : message(msg) {} // std:: lagaya

    virtual ~InvalidCancellationException() throw() {} 

    const char* what() const throw() override {
        return message.c_str();
    }
};

#endif
