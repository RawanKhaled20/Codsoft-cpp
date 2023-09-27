/* Author:Rawan Khaled  https://github.com/RawanKhaled20/Codsoft-cpp.git */

#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
// create a max number of tasks 100
const int MAX_TASKS = 100;
// assign a task 2 attributes
struct Task {
    string description;
    bool completed;
};
// Create 5 methods for the list
class ToDoList {
private:
    Task tasks[MAX_TASKS];
    int taskCount;

public:
    ToDoList() {
        taskCount = 0;
    }

    void addTask(const string& description) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount].description = description;
            tasks[taskCount].completed = false;
            taskCount++;
            cout << "Task added: " << description << endl;
        } else {
            cout << "Task list is full. Cannot add more tasks." << endl;
        }
    }

    void viewTasks() {
        if (taskCount == 0) {
            cout << "No tasks found." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (int i = 0; i < taskCount; ++i) {
                cout << i + 1 << ". ";
                if (tasks[i].completed) {
                    cout << "[X] ";
                } else {
                    cout << "[ ] ";
                }
                cout << tasks[i].description << endl;
            }
        }
    }

    void markTaskAsCompleted(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= taskCount) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed: " << tasks[taskNumber - 1].description << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= taskCount) {
            cout << "Removed task: " << tasks[taskNumber - 1].description << endl;
            for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList todoList;

    while (true) {
        sleep(1);
        cout << "\nTo-Do List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Consume the newline character left in the buffer

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskAsCompleted(taskNumber);
                break;
            }
            case 4: {
                int taskNumber;
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }

    return 0;
}
