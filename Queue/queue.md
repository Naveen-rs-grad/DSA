# Queue

A queue is a data structure that follows FIFO (First In, First Out). The first item you add is the first item you remove. If you add 10, 20, and 30 in that order, the queue gives you 10 first. A stack would give you 30 first.

A queue has two ends. The front holds the next item to remove. The rear holds the most recently added item.

enqueue is a push_back, and dequeue is a pop_front.

enqueue - push_back
dequeue - pop_front

circular array queue in C, also called a ring buffer.

rear can be less than front. They’re array indices, and each wraps independently. rear is the next slot to write, while front is the next slot to read.