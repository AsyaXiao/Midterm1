//
// Created by Анастасия Смирнова on 3/19/24.
//

#ifndef MIDTERM1_SOLUTION_H
#define MIDTERM1_SOLUTION_H

#endif //MIDTERM1_SOLUTION_H

#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;


    friend bool operator<(const Task& t1, const Task& t2)
    {
        int totalLoad1 = t1.getTotalLoad();
        int totalLoad2 = t2.getTotalLoad();
        if (totalLoad1 != totalLoad2)
        {
            return totalLoad1 < totalLoad2;
        }

        else if (t1.date != t2.date)
        {
            return t1.date < t2.date;
        }

        return t1.text < t2.text;
    }
};
struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    // might be needed for task 5
    bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Task::Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads)
{
    this->text = text;
    this->date = date;
    this->workloads = workloads;
}

// task 1
Worker::Worker(const std::string& name, const std::string& login, int maxLoad)
{
    this->name = name;
    this->login = login;
    this->maxLoad = maxLoad;
}


// task 2
int Task::getTotalLoad() const
{
    int totalLoad = 0;
    for (auto& i: workloads)
    {
        totalLoad += i.second;
    }
    return totalLoad;
}


// task 3
void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end());
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    int totalLoad = 0;

    for (const auto& task: allTasks)
    {
        if (task.workloads.find(worker.login) != task.workloads.end())
            totalLoad += task.workloads.at(worker.login);
    }

    return totalLoad;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    for (const auto& worker: workers)
    {
        if (newTask.workloads.find(worker.login) != newTask.workloads.end())
        {
            int load = newTask.workloads.at(worker.login);
            if (load + getWorkerLoad(tasks, worker) > worker.maxLoad)
            {
                throw std::runtime_error("Overworked");
            }
        }
    }
    tasks.push_back(newTask);
}

// task 6
void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    std::vector<std::pair<std::string, int>> overworkedWorkers;


    for (const auto& worker: workers)
    {
        int load = getWorkerLoad(tasks, worker);
        if (newTask.workloads.find(worker.login) != newTask.workloads.end())
        {
            load += newTask.workloads.at(worker.login);
        }
        if (load > worker.maxLoad)
        {
            overworkedWorkers.emplace_back(worker.login, load - worker.maxLoad);
        }
    }


    if (!overworkedWorkers.empty())
    {
        std::sort(overworkedWorkers.begin(), overworkedWorkers.end());
        std::string errorMessage = "Overworked: ";
        for (size_t i = 0; i < overworkedWorkers.size(); ++i)
        {
            errorMessage += overworkedWorkers[i].first + " by " + std::to_string(overworkedWorkers[i].second);
            if (i != overworkedWorkers.size() - 1)
            {
                errorMessage += ", ";
            }
        }
        throw std::runtime_error(errorMessage);
    }

    tasks.push_back(newTask);
}