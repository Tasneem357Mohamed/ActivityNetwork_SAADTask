#include <bits/stdc++.h>
using namespace std;

// Structure to represent each task
struct Task
{
    int duration;
    int early_start = 0;
    int early_finish = 0;
    int late_start = INT32_MAX;
    int late_finish = INT32_MAX;
    vector<int> dependents;
    vector<int> dependencies;
};

void findCriticalPaths(int current, const vector<Task> &tasks, const vector<bool> &isCritical, vector<int> &path, vector<vector<int> > &allPaths)
{
    path.push_back(current);

    if (tasks[current].dependents.empty())
    {
        allPaths.push_back(path);
    }
    else
    {
        for (auto &next : tasks[current].dependents)
        {
            if (isCritical[next])
            {
                findCriticalPaths(next, tasks, isCritical, path, allPaths);
            }
        }
    }

    path.pop_back();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num_of_tasks;
    cin >> num_of_tasks;

    vector<Task> tasks(num_of_tasks + 1);

    for (int i = 0; i < num_of_tasks; i++)
    {
        int task_id, dur, num_of_dependencies;
        cin >> task_id >> dur >> num_of_dependencies;
        tasks[task_id].duration = dur;
        for (int j = 0; j < num_of_dependencies; j++)
        {
            int dep_id;
            cin >> dep_id;
            tasks[task_id].dependencies.push_back(dep_id);
            tasks[dep_id].dependents.push_back(task_id);
        }
    }

    cout << "Dependencies and Dependents:\n";
    for (int i = 1; i <= num_of_tasks; i++)
    {
        cout << "Task " << i << " Dependencies: ";
        for (auto &dep : tasks[i].dependencies)
            cout << dep << " ";
        cout << "| Dependents: ";
        for (auto &dep : tasks[i].dependents)
            cout << dep << " ";
        cout << "\n";
    }
    cout << "\n";

    vector<int> in_degree(num_of_tasks + 1, 0);
    for (int i = 1; i <= num_of_tasks; i++)
    {
        for (auto &dep : tasks[i].dependents)
        {
            in_degree[dep]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= num_of_tasks; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
            tasks[i].early_start = 0;
            tasks[i].early_finish = tasks[i].duration;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : tasks[u].dependents)
        {
            tasks[v].early_start = max(tasks[v].early_start, tasks[u].early_finish);
            tasks[v].early_finish = tasks[v].early_start + tasks[v].duration;
            if (--in_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    int project_end = 0;
    for (int i = 1; i <= num_of_tasks; i++)
    {
        project_end = max(project_end, tasks[i].early_finish);
    }

    cout << "After Forward Pass:\n";
    cout << "Task\tES\tEF\n";
    for (int i = 1; i <= num_of_tasks; i++)
    {
        cout << i << "\t" << "\t" << tasks[i].early_start << "\t" << tasks[i].early_finish << "\n";
    }
    cout << "\n";

    vector<int> out_degree(num_of_tasks + 1, 0);
    for (int i = 1; i <= num_of_tasks; i++)
    {
        out_degree[i] = tasks[i].dependents.size();
    }

    for (int i = 1; i <= num_of_tasks; i++)
    {
        if (out_degree[i] == 0)
        {
            tasks[i].late_finish = project_end;
            tasks[i].late_start = tasks[i].late_finish - tasks[i].duration;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : tasks[u].dependencies)
        {
            // Update Late Finish for dependency task
            tasks[v].late_finish = min(tasks[v].late_finish, tasks[u].late_start);
            tasks[v].late_start = tasks[v].late_finish - tasks[v].duration;

            // Decrease out-degree and enqueue if it becomes 0
            if (--out_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    cout << "After Backward Pass:\n";
    cout << "Task\tLS\tLF\n";
    for (int i = 1; i <= num_of_tasks; i++)
    {
        cout << i << "\t" << "\t" << tasks[i].late_start << "\t" << tasks[i].late_finish << "\n";
    }
    cout << "\n";

    vector<bool> isCritical(num_of_tasks + 1, false);
    for (int i = 1; i <= num_of_tasks; i++)
    {
        if (tasks[i].early_start == tasks[i].late_start)
        {
            isCritical[i] = true;
        }
    }

    vector<vector<int> > allCriticalPaths;
    vector<int> path;

    for (int i = 1; i <= num_of_tasks; i++)
    {
        if (tasks[i].dependencies.empty() && isCritical[i])
        {
            findCriticalPaths(i, tasks, isCritical, path, allCriticalPaths);
        }
    }

    // Output Early and Late Times for Each Task (Final Output)
    cout << "Task\tES\tEF\tLS\tLF\n";
    for (int i = 1; i <= num_of_tasks; i++)
    {
        cout << i << "\t" << "\t" << tasks[i].early_start << "\t" << tasks[i].early_finish
             << "\t" << tasks[i].late_start << "\t" << tasks[i].late_finish << "\n";
    }
    cout << "\n";

    // Output All Critical Paths
    cout << "Critical Paths:\n";
    for (auto &cp : allCriticalPaths)
    {
        for (auto &task_id : cp)
        {
            cout << task_id << " ";
        }
        cout << "\n";
    }
    cout << "Project Duration: " << project_end << "\n";

    return 0;
}