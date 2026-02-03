#include <bits/stdc++.h>
using namespace std;

class Job {
public:
    int id;
    int priority;
    int deadline;
    int executionTime;

    Job(int id, int priority, int deadline, int executionTime) {
        this->id = id;
        this->priority = priority;
        this->deadline = deadline;
        this->executionTime = executionTime;
    }
};

// Custom comparator for Priority Queue
class Compare {
public:
    bool operator()(const Job &a, const Job &b) const {
        // Higher priority first
        if (a.priority == b.priority) {
            // Earlier deadline first if priority same
            return a.deadline > b.deadline;
        }
        return a.priority < b.priority;
    }
};

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    priority_queue<Job, vector<Job>, Compare> pq;

    cout << "Enter tasks (id priority deadline executionTime):\n";
    for (int i = 0; i < n; i++) {
        int id, priority, deadline, executionTime;
        cin >> id >> priority >> deadline >> executionTime;
        pq.push(Job(id, priority, deadline, executionTime));
    }

    cout << "\nTask Execution Order:\n";

    int currentTime = 0;

    while (!pq.empty()) {
        Job current = pq.top();
        pq.pop();

        currentTime += current.executionTime;

        cout << "Job ID: " << current.id
             << " | Priority: " << current.priority
             << " | Deadline: " << current.deadline
             << " | Execution Time: " << current.executionTime
             << " | Completion Time: " << currentTime;

        if (currentTime > current.deadline)
            cout << " (Delayed)";

        cout << endl;
    }

    return 0;
}
