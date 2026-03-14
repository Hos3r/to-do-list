#include "task.h"
#include <vector>
#include <limits>
#include <cstdlib>
#include <fstream>

void WriteOutMenu();
void AddNewTask(std::vector<Task>& todoList);
void LoadTasksFromFile(std::vector<Task>& todoList);
void SaveTasksToFile(const std::vector<Task>& todoList);
void ShowTasks(const std::vector<Task>& todoList);
void DeleteTask(std::vector<Task>& todoList);
void MarkTaskAsDone(std::vector<Task>& todoList);



int main()
{
    int choice;
    std::vector<Task> todoList;

    LoadTasksFromFile(todoList);

    do
        {
            WriteOutMenu();
            std::cin >> choice;

            if(!std::cin)
                {
                    std::cout << "Thats not a number! Please try again. \n";

                    std::cin.clear();

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

            if(choice==1) AddNewTask(todoList);
            if(choice==2) ShowTasks(todoList);
            if(choice==3) DeleteTask(todoList);
            if(choice==4) MarkTaskAsDone(todoList);

            if(choice==5)
                {
                    SaveTasksToFile(todoList);
                    std::cout << "App closing..." << std::endl;
                    return 0;
                }
        }
    while(choice!=5);

    return 0;
}




void WriteOutMenu()
{
    std::cout << "\n---Welcome in an To-Do-List-Application---" << std::endl;
    std::cout << "Please choose one of the available options\n1-Add new task\n2-Show list\n3-Delete task\n4-Check smth done\n5-Exit the App\n" << std::endl;
}

void AddNewTask(std::vector<Task>& todoList)
{
    std::string tempName;
    int tempTime;
    std::cout << "Please insert task name: ";
    std::getline(std::cin >> std::ws, tempName);
    std::cout << "Please insert time planned for that task(in minutes): ";
    std::cin >> tempTime;
    Task temp(tempName, tempTime, false);
    todoList.push_back(temp);
}

void LoadTasksFromFile(std::vector<Task>& todoList)
{
    std::ifstream loadFile("tasks.txt");

    if(loadFile.is_open())
        {
            std::string tempName;
            int tempTime;
            bool tempIsDone;

            while(std::getline(loadFile >> std::ws, tempName))
                {
                    loadFile >> tempTime;
                    loadFile >> tempIsDone;

                    Task temp(tempName, tempTime, tempIsDone);
                    todoList.push_back(temp);
                }
            loadFile.close();
        }
}

void SaveTasksToFile(const std::vector<Task>& todoList)
{
    std::ofstream saveFile("tasks.txt");
    if(saveFile.is_open())
        {
            for(size_t i=0; i<todoList.size(); i++)
                {
                    saveFile << todoList.at(i).get_taskName() << "\n";
                    saveFile << todoList.at(i).get_timeNeeded() << "\n";
                    saveFile << todoList.at(i).get_isDone() << "\n";
                }
            saveFile.close();
        }
}

void ShowTasks(const std::vector<Task>& todoList)
{
    std::cout << "\nList:\n";
    for(size_t i=0 ; i<todoList.size() ; i++)
        {
            std::cout << i + 1 << ".\n";
            todoList.at(i).info();
        }
}

void DeleteTask(std::vector<Task>& todoList)
{
    int taskDel;
    std::cout << "Choose which task to delete(numeric): ";
    std::cin >> taskDel;
    if(taskDel > 0 && taskDel <= (int)todoList.size())
        {
            todoList.erase(todoList.begin() + ((size_t)taskDel-1));
            std::cout << "Task deleted.\n";
        }
    else
        {
            std::cout << "Invalid task number!\n";
        }
}

void MarkTaskAsDone(std::vector<Task>& todoList)
{
    int taskCheck;
    std::cout << "Choose which task to check done: ";
    std::cin >> taskCheck;
    if(taskCheck > 0 && taskCheck <= (int)todoList.size())
        {
            todoList.at((size_t)taskCheck-1).markAsDone();
        }
    else
        {
            std::cout << "Invalid task number!\n";
        }
}
