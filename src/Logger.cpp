#include "Logger.hpp"
#include <iostream>

Logger* Logger::instance = nullptr;

Logger* Logger::Instance() {
  if (!instance) instance = new Logger();
  return instance;
}

Logger::Logger() {
  this->logging = true;
  this->isFile = false;
  this->file.open(LOG_FILE);
  if (this->file.good()) this->isFile = true;
}

Logger::~Logger() {
  if (this->file.is_open()) this->file.close();
}

void Logger::toTerminal() {
  this->isFile = false;
}

void Logger::toFile() {
  if (this->file.is_open()) this->isFile = true;
}

void Logger::disable() {
  this->logging = false;
}

void Logger::enable() {
  this->logging = true;
}

template <typename T>
Logger* Logger::operator<< (T& obj) {
  if (logging) {
    if (isFile) file << obj;
    else std::cout << obj;
  }
  return this;
}
