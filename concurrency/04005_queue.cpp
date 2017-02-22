#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>

using namespace std; 

template<typename T>
class threadsafe_queue
{
private:
    mutable std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;

public:
    threadsafe_queue()
    {}
    threadsafe_queue(threadsafe_queue const& other)
    {
        std::lock_guard<std::mutex> lk(other.mut);
        data_queue=other.data_queue;
    }
    void push(T new_value)
    {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }
    void wait_and_pop(T& value)
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk,[this]{return !data_queue.empty();});
        value=data_queue.front();
        data_queue.pop();
    }
    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk,[this]{return !data_queue.empty();});
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    bool try_pop(T& value)
    {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty())
            return false;
        value=data_queue.front();
        data_queue.pop();
        return true;
    }
    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }
};

threadsafe_queue<int> data_queue;

void data_preparation_thread()
{
    int i=0;
    while(i < 20)
    {
        data_queue.push(i);
        cout << i << " pushed\n";
        i++;
    }
}

void data_processing_thread()
{
    while(true)
    {
        int i=-1;

        data_queue.wait_and_pop(i);

        cout << i << " popped\n";

        if (i == 19) 
            break; 
    }
}

queue<int> q2; 

void data_preparation_thread2()
{
    int i=0;
    while(i < 20)
    {
        q2.push(i);
        cout << i << " pushed2\n";
        i++;
    }
}

void data_processing_thread2()
{
    while(true)
    {
        int i=-1;

        if (!q2.empty()) {
            i = q2.front();
            q2.pop();

            cout << i << " popped2\n";

            if (i == 19) 
                break; 
        }
    }
}


int main()
{
    thread t1(data_preparation_thread);
    thread t2(data_processing_thread);

    t1.join();
    t2.join();


    thread t3(data_preparation_thread2);
    thread t4(data_processing_thread2);

    t3.join();
    t4.join();
}


