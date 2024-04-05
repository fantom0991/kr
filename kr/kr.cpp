#include <iostream>
#include <string>
using namespace std;

struct Task
{
    string name;
    int priority;
    string description;
    string datetime;
    Task* next;
};

class TodoList
{
private:
    Task* head;

public:
    TodoList() : head(nullptr) {}

    void addTask(string name, int priority, string description, string datetime)
    {
        Task* newTask = new Task;
        newTask->name = name;
        newTask->priority = priority;
        newTask->description = description;
        newTask->datetime = datetime;
        newTask->next = head;
        head = newTask;
    }

    void displayTask(Task* task)
    {
        cout << "Название: " << task->name << endl;
        cout << "Описание: " << task->description << endl;
        cout << "Приоритет: " << task->priority << endl;
        cout << "Дата и время: " << task->datetime << endl;
        cout << "---------------------" << endl;
    }

    void displayTasks()
    {
        Task* current = head;
        while (current != nullptr)
        {
            displayTask(current);
            current = current->next;
        }
    }

    void deleteTask(string taskName)
    {
        Task* current = head;
        Task* previous = nullptr;

        while (current != nullptr)
        {
            if (current->name == taskName)
            {
                if (previous == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                delete current;
                break;
            }
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Задача с таким названием не найдена" << endl;
        }
    }

    void searchByName(string name)
    {
        Task* current = head;
        bool found = false;
        while (current != nullptr)
        {
            if (current->name == name)
            {
                found = true;
                displayTask(current);
            }
            current = current->next;
        }
        if (!found)
        {
            cout << "Задача с таким названием не найдена" << endl;
        }
    }

    void searchByPriority(int priority)
    {
        Task* current = head;
        bool found = false;
        while (current != nullptr)
        {
            if (current->priority == priority)
            {
                found = true;
                displayTask(current);
            }
            current = current->next;
        }
        if (!found)
        {
            cout << "Задачи с таким приоритетом не найдены" << endl;
        }
    }

    void searchByDescription(string description)
    {
        Task* current = head;
        bool found = false;
        while (current != nullptr)
        {
            if (current->description == description)
            {
                found = true;
                displayTask(current);
            }
            current = current->next;
        }
        if (!found)
        {
            cout << "Задачи с таким описанием не найдены" << endl;
        }
    }

    void searchByDateTime(string datetime)
    {
        Task* current = head;
        bool found = false;
        while (current != nullptr)
        {
            if (current->datetime == datetime)
            {
                found = true;
                displayTask(current);
            }
            current = current->next;
        }
        if (!found)
        {
            cout << "Задачи с такой датой и временем не найдены" << endl;
        }
    }
};




int main()
{
    setlocale(LC_ALL, "Russian");
    TodoList myTodoList;
    while (true)
    {
        cout << "1. Добавить задачу\n2. Удалить задачу\n3. Отобразить задачи\n4. Выход\n";
        int choice;
        cout << "Введите ваш выбор: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            string name, description, datetime;
            int priority;
            cout << "Введите название задачи: ";
            getline(cin, name);
            cout << "Введите описание задачи: ";
            getline(cin, description);
            cout << "Введите дату и время (дд.мм.гггг чч:мм): ";
            getline(cin, datetime);
            cout << "Введите приоритет (1-Высокий, 2-Средний, 3-Низкий): ";
            cin >> priority;
            myTodoList.addTask(name, priority, description, datetime);
        }
        else if (choice == 2)
        {
            string taskName;
            cout << "Введите название задачи для удаления: ";
            getline(cin, taskName);
            myTodoList.deleteTask(taskName);
        }
        else if (choice == 3)
        {
            cout << endl;
            cout << "1. Отобразить все задачи\n2. Отобразить по дате\n3. Отобразить по приоритету\n4. Отобразить по названию\n5. Отобразить по описанию\n";
            int search;
            cin >> search;
            cin.ignore();
            if (search == 1)
            {
                myTodoList.displayTasks();
            }
            else if (search == 2)
            {
                string datetime;
                cout << "Введите дату и время для поиска (дд.мм.гггг чч:мм): ";
                getline(cin, datetime);
                myTodoList.searchByDateTime(datetime);
            }
            else if (search == 3)
            {
                int priority;
                cout << "Введите приоритет для поиска (1-Высокий, 2-Средний, 3-Низкий): ";
                cin >> priority;
                myTodoList.searchByPriority(priority);
            }
            else if (search == 4)
            {
                string name;
                cout << "Введите название для поиска: ";
                getline(cin, name);
                myTodoList.searchByName(name);
            }
            else if (search == 5)
            {
                string description;
                cout << "Введите описание для поиска: ";
                getline(cin, description);
                myTodoList.searchByDescription(description);
            }
        }
    }
}