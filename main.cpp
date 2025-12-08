#include <iostream>

class task {
    private:
        std::string name;
        std::string description;
        std::string due_date;
        bool completed;
    
    public:
        task(std::string name, std::string description, std::string due_date, bool completed = false)
            : name(name), description(description), due_date(due_date), completed(completed) {

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

        std:: string to_string() const {
            return "Task: " + name + "\nDescription: " + description + "\nDue Date: " + due_date + "\nCompleted: " + (completed ? "Yes" : "No") + "\n";
        }
};

int main(){
    std::string name, description, due_date;
    std::cout << "Enter task name: ";
    std::getline(std::cin, name);
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    std::cout << "Enter task due date (YYYY-MM-DD): ";
    std::getline(std::cin, due_date);
    task myTask(name, description, due_date);
    std::cout << myTask.to_string();
    return 0;
}