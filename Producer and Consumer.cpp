#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <queue>

using namespace std;
using namespace std::chrono;

struct TradePacket {
    int seq_id;
    system_clock::time_point caller_time;
    system_clock::time_point receiver_time;
    system_clock::time_point time_prod;
    system_clock::time_point time_cons;
};

class Buffer {
private:
    queue<TradePacket> buffer;
    const size_t max_size = 5;
    mutex mtx;
    condition_variable cv_produce;
    condition_variable cv_consume;

public:
    void produce(int thread_id, int& seq_counter) {
        while (true) {
            TradePacket packet;
            {
                unique_lock<mutex> lock(mtx);
                cv_produce.wait(lock, [this] { return buffer.size() < max_size; });

                packet.seq_id = ++seq_counter;
                packet.caller_time = system_clock::now();
                packet.time_prod = system_clock::now();

                buffer.push(packet);
                cout << "[Producer-" << thread_id << "] Produced Seq ID: " << packet.seq_id << endl;
            }

            cv_consume.notify_all();
            this_thread::sleep_for(milliseconds(100 + rand() % 200));
        }
    }

    void consume(int thread_id) {
        while (true) {
            TradePacket packet;
            {
                unique_lock<mutex> lock(mtx);
                cv_consume.wait(lock, [this] { return !buffer.empty(); });

                packet = buffer.front();
                buffer.pop();

                packet.receiver_time = system_clock::now();
                packet.time_cons = system_clock::now();

                cout << "[Consumer-" << thread_id << "] Consumed Seq ID: " << packet.seq_id
                     << " | Latency (ms): "
                     << duration_cast<milliseconds>(packet.time_cons - packet.time_prod).count()
                     << endl;
            }

            cv_produce.notify_all();
            this_thread::sleep_for(milliseconds(150 + rand() % 150));
        }
    }
};

class ThreadManager {
private:
    Buffer& buffer;
    vector<thread> producers;
    vector<thread> consumers;
    int sequence_id = 0;

public:
    ThreadManager(Buffer& buf) : buffer(buf) {}

    void start(int num_producers, int num_consumers) {
        for (int i = 0; i < num_producers; ++i) {
            producers.emplace_back(&Buffer::produce, &buffer, i + 1, ref(sequence_id));
        }

        for (int i = 0; i < num_consumers; ++i) {
            consumers.emplace_back(&Buffer::consume, &buffer, i + 1);
        }
    }

    void join() {
        for (auto& t : producers) t.join();
        for (auto& t : consumers) t.join();
    }
};

int main() {
    cout << "[Main] Starting threaded system with thread management..." << endl;

    Buffer buffer;
    ThreadManager manager(buffer);

    manager.start(4, 4);  // 4 producers, 4 consumers
    manager.join();

    return 0;
}
