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
            return "Task: \n" "ID: " + std::to_string(id) + "\nName: " + name + "\nDescription: " + description + "\nDue Date: " + due_date + "\nCompleted: " + (completed ? "Yes" : "No") + "\n";
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
        void print_tasks(){
            for(const task& t : tasks){
                std::cout << t.to_string() << std::endl;
            }
        }

        std::vector<task>& get_tasks(){
            return tasks;
        }
};

int main(){
    int id = 1; // Starting ID for tasks
    taskList myTaskList;
    int choice;
    std::string name, description, due_date;
    while(true){
        std::cout << "Select an option: " << std::endl;
        std::cout << "1. Create New Task" << std::endl; 
        std::cout << "2. Delete a Task" << std::endl; 
        std::cout << "3. View All Tasks" << std::endl;
        std::cout << "4. Quit" << std::endl; 
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(choice == 1){
            std::cout << "Enter task name: " << std::endl;
            std::getline(std::cin, name);
            std::cout << "Enter task description: " << std::endl;
            std::getline(std::cin, description);
            std::cout << "Enter task due date (YYYY-MM-DD): " << std::endl;
            std::getline(std::cin, due_date);
            task myTask(id, name, description, due_date);
            myTaskList.add_task(myTask);
            id++;
        }
        else if(choice == 2){
            int id_choice;
            std::cout << "Please enter the id of the task you'd like to delete: " << std::endl;
            std::cin >> id_choice;
            for (task &task : myTaskList.get_tasks()){
                if(task.get_id() == id){
                    myTaskList.remove_task(task);
                }
                else{
                    std::cout << "No Task With That ID." << std::endl;
                }
            }
        }
        else if(choice == 3){
            myTaskList.print_tasks();
        }

        else if(choice == 4){
            break;
        }

        else{
            std::cout << "Invalid Input. Try Again!" << std::endl;
            continue;
        }
    }

    return 0;
}