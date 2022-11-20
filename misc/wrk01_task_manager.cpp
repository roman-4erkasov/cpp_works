#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW=0,          // новая
    IN_PROGRESS=1,  // в разработке
    TESTING=2,      // на тестировании
    DONE=3          // завершена
};
const std::array<TaskStatus,3> all_statuses = {
    TaskStatus::NEW, 
    TaskStatus::IN_PROGRESS, 
    TaskStatus::TESTING
};

const std::map<TaskStatus,TaskStatus> task_map = {
    {TaskStatus::NEW, TaskStatus::IN_PROGRESS}, 
    {TaskStatus::IN_PROGRESS, TaskStatus::TESTING}, 
    {TaskStatus::TESTING, TaskStatus::DONE}
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

string status2str(TaskStatus status){
    switch(status){
        case TaskStatus::NEW: 
            return "TasksInfo::NEW"s;
        case TaskStatus::IN_PROGRESS: 
            return "TasksInfo::IN_PROGRESS"s;
        case TaskStatus::TESTING: 
            return "TasksInfo::TESTING"s;
        case TaskStatus::DONE: 
            return "TasksInfo::DONE"s;
        default: 
            return "TasksInfo::UNK"s;
    }
}

string task2str(const TasksInfo& tasks_info) {
    string res=""s;
    if (tasks_info.count(TaskStatus::NEW)) {
        res += (
            "NEW: " 
            + to_string(tasks_info.at(TaskStatus::NEW)) 
            + " "
        );
    }
    if (tasks_info.count(TaskStatus::IN_PROGRESS)) {
        res +=(
            "IN_PROGRESS: "
            + to_string(tasks_info.at(TaskStatus::IN_PROGRESS))
            + " "
        );
    }
    if (tasks_info.count(TaskStatus::TESTING)) {
        res +=(
            "TESTING: " 
            +to_string(tasks_info.at(TaskStatus::TESTING)) 
            +" "
        );
    }
    if (tasks_info.count(TaskStatus::DONE)) {
        res+=(
            "DONE: " 
            +to_string(tasks_info.at(TaskStatus::DONE)) 
            +" "
        );
    }
    return res;
}

string tasks2str(
    const TasksInfo& updated_tasks, 
    const TasksInfo& untouched_tasks
) {
    return (
        "Updated: ["
        +task2str(updated_tasks)
        +"] "
        +"Untouched: ["
        +task2str(untouched_tasks)
        +"] "
    );
}



class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return emp2tasks.at(person);
    };

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        emp2tasks[person][TaskStatus::NEW]++;
    };

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count
    ){
        cout << "per="<< person << " task_count=" << task_count << endl;
        TasksInfo updated, 
        untouched(emp2tasks.at(person)),
        buff;
        for(TaskStatus status: all_statuses) {
            if(emp2tasks[person].count(status)==0) untouched[status] = 0;
            else untouched[status] = emp2tasks.at(person).at(status);
        }
        buff = TasksInfo(emp2tasks.at(person));
        for(TaskStatus status: all_statuses){
            int delta = min(task_count, emp2tasks[person][status]);
            cout << "pre: s=" << status2str(status) 
                << " d=" << delta << endl;
            cout << "pre: " << tasks2str(updated,untouched) << endl;
            if(delta==0) continue;
            buff[status] -= delta;
            untouched[status] = max(0, untouched[status] - delta);
            if(task_map.count(status)>0){
                buff[task_map.at(status)] += delta;
                updated[task_map.at(status)] += delta;
            }
            task_count -= delta;
            cout << "post: s=" << status2str(status) 
                << "<b:" << buff[status] 
                << "->" << buff[task_map.at(status)] << ">"
                << " d=" << delta << endl;
            cout << "post: " << tasks2str(updated,untouched) << endl;
        }
        emp2tasks[person] = buff;
        
        return {updated, untouched};
    };
private:
    map<string, TasksInfo> emp2tasks;
};


void PrintTasksInfo(const TasksInfo& tasks_info) {
    if (tasks_info.count(TaskStatus::NEW)) {
        std::cout << "NEW: " << tasks_info.at(TaskStatus::NEW) << " ";
    }
    if (tasks_info.count(TaskStatus::IN_PROGRESS)) {
        std::cout << "IN_PROGRESS: " << tasks_info.at(TaskStatus::IN_PROGRESS) << " ";
    }
    if (tasks_info.count(TaskStatus::TESTING)) {
        std::cout << "TESTING: " << tasks_info.at(TaskStatus::TESTING) << " ";
    }
    if (tasks_info.count(TaskStatus::DONE)) {
        std::cout << "DONE: " << tasks_info.at(TaskStatus::DONE) << " ";
    }
}
 
void PrintTasksInfo(const TasksInfo& updated_tasks, const TasksInfo& untouched_tasks) {
    std::cout << "Updated: [";
    PrintTasksInfo(updated_tasks);
    std::cout << "] ";
 
    std::cout << "Untouched: [";
    PrintTasksInfo(untouched_tasks);
    std::cout << "] ";
 
    std::cout << std::endl;
}



 
int main() {
    TeamTasks tasks;
    TasksInfo updated_tasks;
    TasksInfo untouched_tasks;
 
 
    /* TEST 3 */
    std::cout << "\nLisa" << std::endl;
 
    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]
 
    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]
 
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
    std::cout << std::endl;
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 4);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]
 
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
    std::cout << std::endl;
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 4, "DONE": 1}, {"TESTING": 4}]
 
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"TESTING": 8, "DONE": 2}
    std::cout << std::endl;
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 8}, {}]
 
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]
 
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;
 
    tasks.AddNewTask("Lisa");
 
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 1, "DONE": 10}
    std::cout << std::endl;
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]
 
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 1, "DONE": 10}
    std::cout << std::endl;
 
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Bob", 3);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]
 
    return 0;
}


/*Lisa
Updated: [IN_PROGRESS: 5 ] Untouched: [] 
Updated: [TESTING: 5 ] Untouched: [] 
Updated: [DONE: 1 ] Untouched: [TESTING: 4 ] 
Updated: [IN_PROGRESS: 2 ] Untouched: [NEW: 3 TESTING: 4 ] 
NEW: 3 IN_PROGRESS: 2 TESTING: 4 DONE: 1 
Updated: [IN_PROGRESS: 3 TESTING: 1 ] Untouched: [IN_PROGRESS: 1 TESTING: 4 ] 
IN_PROGRESS: 4 TESTING: 5 DONE: 1 
Updated: [TESTING: 4 DONE: 1 ] Untouched: [TESTING: 4 ] 
TESTING: 8 DONE: 2 
Updated: [DONE: 8 ] Untouched: [] 
DONE: 10 
Updated: [] Untouched: [] 
DONE: 10 
NEW: 1 DONE: 10 
Updated: [IN_PROGRESS: 1 ] Untouched: [] 
IN_PROGRESS: 1 DONE: 10 
Updated: [] Untouched: [] */

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь.
/*void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks"s
         << ", "s << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"s
         << ", "s << tasks_info[TaskStatus::TESTING] << " tasks are being tested"s
         << ", "s << tasks_info[TaskStatus::DONE] << " tasks are done"s << endl;
}*/

/*int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia"s);
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan"s);
    }
    cout << "Ilia's tasks: "s;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"s));
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 2);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 10);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
}*/