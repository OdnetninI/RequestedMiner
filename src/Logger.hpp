#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <fstream>
#include <iostream>

#define LOG_FILE "log.log"

class Logger {
  private:
    bool isFile;
    bool logging;
    std::fstream file;

  public:
      static Logger& Instance();
      static void destroy();
      void toTerminal();
      void toFile();
      void disable();
      void enable();
      template <typename T>
      Logger& operator<< (T& obj) {
        if (this->logging) {
          if (this->isFile) {
            this->file << obj;
            this->file.flush();
          }
          else std::cout << obj;
        }
        return *this;
      }

  private:
    static Logger* instance;
    Logger();
    ~Logger();
};

#endif // __LOGGER_HPP__
