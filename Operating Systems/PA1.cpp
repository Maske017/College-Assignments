// Bounded Buffer Producer/Consumer in jBACI
0 0 semaphore Full;   // Semaphore to count full slots in the buffer
0 0 semaphore Empty;  // Semaphore to count empty slots in the buffer
0 0 semaphore Mutex;  // Semaphore for mutual exclusion
0 0 int buffer[5];    // Buffer of size 5
0 0 int in = 0;       // Index for the next produced item
0 0 int out = 0;      // Index for the next consumed item
0 0 int producedCount = 0; // Count of produced items

0 0 void producer() {
    for (int i = 0; i < 20; i++) {
        p(Empty);      // Wait for an empty slot
        p(Mutex);      // Enter critical section

        // Produce an item
        buffer[in] = i + 1; // Produce item (1 to 20)
        cout << "Item " << buffer[in] << " produced" << endl;
        in = (in + 1) % 5; // Move to the next index

        v(Mutex);      // Exit critical section
        v(Full);       // Signal that a new item is available
    }
}

0 0 void consumer() {
    while (producedCount < 20) {
        p(Full);       // Wait for a full slot
        p(Mutex);      // Enter critical section

        // Consume an item
        int item = buffer[out]; // Consume item
        cout << "Item " << item << " consumed" << endl;
        out = (out + 1) % 5; // Move to the next index
        producedCount++; // Increment the count of consumed items

        v(Mutex);      // Exit critical section
        v(Empty);      // Signal that an empty slot is available
    }
}

0 0 main() {
    initialsem(Full, 0);   // Initially, the buffer is empty
    initialsem(Empty, 5);  // Initially, all slots are empty
    initialsem(Mutex, 1);  // Mutex is available

    cobegin {
        producer();        // Start producer
        consumer();       // Start consumer
    }
}