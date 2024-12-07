//
// Created by seand on 12/7/2024.
//

#ifndef THREADPOOLMANAGER_H
#define THREADPOOLMANAGER_H

#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

/**
 * @class ThreadPoolManager
 *
 * @brief manages pool of threads
 */
class ThreadPoolManager {

    public:
    ThreadPoolManager();
    ~ThreadPoolManager();

    /**
     * @brief to add a task to the queue of those to execute
     *
     * @param task
     */
    static void enqueue(function<void()> task);

private:
    // Vector to store worker threads
    vector<thread> threads_;

    // Queue of tasks
    static queue<function<void()> > tasks_;

    // Mutex to synchronize access to shared data
    static mutex queue_mutex_;

    // Condition variable to signal changes in the state of
    // the tasks queue
    static condition_variable cv_;

    // Flag to indicate whether the thread pool should stop
    // or not
    bool stop_ = false;
};

};



#endif //THREADPOOLMANAGER_H
