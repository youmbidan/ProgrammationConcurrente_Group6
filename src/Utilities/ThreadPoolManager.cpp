//
// Created by seand on 12/7/2024.
//

#include "ThreadPoolManager.h"


// Define static members
queue<function<void()>> ThreadPoolManager::tasks_;
mutex ThreadPoolManager::queue_mutex_;
condition_variable ThreadPoolManager::cv_;


/**
 * @brief According to https://www.geeksforgeeks.org/thread-pool-in-cpp/
 *
 */

ThreadPoolManager::ThreadPoolManager() {
    // const size_t num_threads = thread::hardware_concurrency();
    const size_t num_threads = 5;
    cout << "threads in the pool: " << num_threads << endl;

    for (size_t i = 0; i < num_threads; ++i) {
        threads_.emplace_back([this] {
            while (true) {
                function<void()> task;
                // The reason for putting the below code
                // here is to unlock the queue before
                // executing the task so that other
                // threads can perform enqueue tasks
                {
                    // Locking the queue so that data
                    // can be shared safely
                    unique_lock lock(
                        queue_mutex_);

                    // Waiting until there is a task to
                    // execute or the pool is stopped
                    cv_.wait(lock, [this] {
                        return !tasks_.empty() || stop_;
                    });

                    // exit the thread in case the pool
                    // is stopped and there are no tasks
                    if (stop_ && tasks_.empty()) {
                        return;
                    }

                    // Get the next task from the queue
                    task = move(tasks_.front());
                    tasks_.pop();
                }

                task();
            }
        });
    }
}

ThreadPoolManager::~ThreadPoolManager() {
    {
        // Lock the queue to update the stop flag safely
        unique_lock<mutex> lock(queue_mutex_);
        stop_ = true;
    }

    // Notify all threads
    cv_.notify_all();

    // Joining all worker threads to ensure they have
    // completed their tasks
    for (auto& thread : threads_) {
        thread.join();
    }
}


void ThreadPoolManager::enqueue(function<void()> task) {
    {
        cout << "new task queued" << endl;
        unique_lock lock(queue_mutex_);
        tasks_.emplace(move(task));
    }
    cv_.notify_one();
}

