//class definition

#include "task.h"

Task::Task(){
    taskName = "name not defined";
    timeNeeded = 0;
    isDone = false;
}

Task::Task(const std::string& taskName, int timeNeeded, bool isDone)
    : taskName(taskName), timeNeeded(timeNeeded), isDone(isDone)
{
    // Left empty because the list above do all the work of constructing
}

Task::~Task(){
}

void Task::info() const{
    std::cout << "Task name: " << taskName << std::endl;
    std::cout << "Time needed: " << timeNeeded << " minutes" << std::endl;
    std::cout << "Is it done? " << isDone << std::endl;
    std::cout << std::endl;
}

void Task::markAsDone(){
    isDone = true;
}

std::string Task::get_taskName() const
{
    return taskName;
}

int Task::get_timeNeeded() const
{
    return timeNeeded;
}

bool Task::get_isDone() const
{
    return isDone;
}

