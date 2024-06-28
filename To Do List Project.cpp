#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Task {
    string name;
    string dueDate;
    int priority;
    bool completed;
};

int main() {
	cout<<"\t\t\t\t\t\t--------------------TO DO LIST--------------------";
    vector<Task> tasks;

    char choice;
    do {
        cout <<"\n\n\n"<< "1. Add Task\n2. Display Tasks\n3. Mark Task as Completed\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                Task newTask;
                cout << "Enter task name: ";
                cin >> newTask.name;
                cout << "Enter due date: ";
                cin >> newTask.dueDate;
                cout << "Enter priority (1-5): ";
                cin >> newTask.priority;
                newTask.completed = false;
                tasks.push_back(newTask);
                break;
            }
            case '2': {
                for(const auto& task : tasks) {
                    cout << "Task: " << task.name << " | Due Date: " << task.dueDate << " | Priority: " << task.priority << " | Completed: " << (task.completed ? "Yes" : "No") << std::endl;
                }
                break;
            }
            case '3': {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                if(index >= 0 && index < tasks.size()) {
                    tasks[index].completed = true;
                } else {
                    cout << "Invalid index." << endl;
                }
                break;
            }
            case '4':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != '4');
    

    return 0;
}
