//class declaration

#ifndef TASK_H_
#define TASK_H_

#include <iostream>
#include <string>

class Task {
private:
    std::string taskName;
    int timeNeeded;
    bool isDone;
public:
    Task();
    Task(const std::string& taskName, int timeNeeded, bool isDone);
    void info() const;
    void markAsDone();
    ~Task();
    std::string get_taskName() const;
    int get_timeNeeded() const;
    bool get_isDone() const;
};

#endif // TASK_H_
