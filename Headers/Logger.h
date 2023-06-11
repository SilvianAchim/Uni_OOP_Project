#ifndef OOP_LOGGER_H
#define OOP_LOGGER_H

template <typename T>
class Logger {
public:
    void LogInformation(const std::string& information);
    void LogError(const std::string& error);
    void LogSuccess(const std::string& success);
    void LogWarning(const std::string& warning);

    Logger() : type(GetType())  {}

private:
    std::string GetType();
    std::string type;
    const std::string delimitator =": ";
};

#endif
