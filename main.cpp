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
    task myTask("Finish Project", "Complete the C++ project by the end of the week", "2024-06-30");
    std::cout << myTask.to_string();
    return 0;
}