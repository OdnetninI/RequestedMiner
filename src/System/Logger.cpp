#include "System/Logger.hpp"

Logger* Logger::instance = nullptr;

Logger& Logger::Instance() {
  if (!instance) instance = new Logger();
  return *instance;
}

void Logger::destroy() {
  if (instance) delete instance;
  instance = nullptr;
}

Logger::Logger() {
  this->logging = true;
  this->isFile = false;
  this->file.open(LOG_FILE, std::ofstream::out);
  if (this->file.good() && this->file.is_open())
    this->isFile = true;
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
