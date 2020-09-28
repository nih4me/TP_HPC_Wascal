#include <queue>
#include <thread>
#include <iostream>
#include <mutex>

/* THE QUEUE PROBLEM #1
 * 0 1 2 3
 * Two threads (A and B) read the front value of a queue and pop it immediately after.
 * [ QUESTION ] : Do the two threads together always retrieve all the elements of the queue?
 */

void retrieve_and_delete(std::queue<int>& rawQueue, std::string threadName, std::mutex& m) {
    if( !rawQueue.empty() ) {
        m.lock();
        std::string out = "[ " + threadName + " ] front " + std::to_string(rawQueue.front());
        rawQueue.pop();
        out += " | new front " + std::to_string(rawQueue.front())  + "\n";
        std::cout << out;
        m.unlock();
    }
}

int main() {
    std::queue<int> rawQueue;
    std::mutex m; // rawQueue's red door

    // queue 0 to 19
    for ( int i = 0; i < 20; i++) {
        rawQueue.push(i);
        std::cout << i << " ";
    }

    // two threads reading the front value and popping it immediately after
    for ( int i = 0; i < 10; i++) {
        std::thread tA(retrieve_and_delete, std::ref(rawQueue), "A", std::ref(m));
        std::thread tB(retrieve_and_delete, std::ref(rawQueue), "B", std::ref(m));
        tA.join();
        tB.join();
    }
}

/* [ ANSWER ] : No, they don't.
 *
 * POSSIBLE OUTPUT:
 * [ A ] front 0 | new front 2
 * [ B ] front 0 | new front 1
 * [ .... ]
 *
 * As you can see thread B reads 0 and pops 0 (new front is 1), but thread A reads 0 and pops 1 (new front is 2).
 * 1 is deleted, but never retrieved.
*/
