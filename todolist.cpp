#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to display the list of tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
    } else {
        cout << "\nTo-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added successfully!\n";
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    int taskNumber;
    viewTasks(tasks);

    if (!tasks.empty()) {
        cout << "Enter the task number to mark as completed: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    int taskNumber;
    viewTasks(tasks);

    if (!tasks.empty()) {
        cout << "Enter the task number to remove: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully!\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
