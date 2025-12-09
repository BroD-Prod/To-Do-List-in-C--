#include <iostream>

class task {
    private:
        std::string name;
        std::string description;
        std::string due_date;
        bool completed;
        int id;
        static int next_id;
    
    public:
        task(int id,std::string name, std::string description, std::string due_date, bool completed = false)
            : id(id), name(name), description(description), due_date(due_date), completed(completed) {
            }

        int get_id() const {
            return id;
        }

        int get_next_id(){
            return id++;
        }

        std::string get_name() const {
            return name;
        }

        std::string get_description() const {
            return description;
        }

        std::string get_due_date() const {
            return due_date;
        }

        bool is_completed() const {
            return completed;
        }

        void set_name(const std::string& name) {
            this -> name = name;
        }

        void set_description(const std::string& description) {
            this -> description = description;
        }

        void set_due_date(const std::string& due_date) {
            this -> due_date = due_date;
        }

        void mark_completed() {
            completed = true;
        }

        std::string to_string() const {
            return "Task: " + name + "\nDescription: " + description + "\nDue Date: " + due_date + "\nCompleted: " + (completed ? "Yes" : "No") + "\n";
        }
};

class taskList {
    private:
        std::vector<task> tasks;
    
    public:
        taskList() = default;

        void add_task(const task& new_task) {
            tasks.push_back(new_task);
        }

        void remove_task(const task& t){
            tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [&t](const task& task) {
                return task.get_id() == t.get_id();
            }
        ), 
            tasks.end());
        }  
};

int main(){
    int id = 1; // Starting ID for tasks
    taskList myTaskList;
    std::string name, description, due_date;
    std::cout << "Enter task name: ";
    std::getline(std::cin, name);
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    std::cout << "Enter task due date (YYYY-MM-DD): ";
    std::getline(std::cin, due_date);
    task myTask(id, name, description, due_date);
    std::cout << myTask.to_string();
    myTaskList.add_task(myTask);
    return 0;
}