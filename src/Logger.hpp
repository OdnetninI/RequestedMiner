#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <fstream>

#define LOG_FILE "log.log"

class Logger {
  private:
    bool isFile;
    bool logging;
    std::ofstream file;

  public:
      static Logger* Instance();
      void toTerminal();
      void toFile();
      void disable();
      void enable();
      template <typename T>
      Logger* operator<< (T& obj);

  private:
    static Logger* instance;
    Logger();
    ~Logger();
};

#endif // __LOGGER_HPP__
