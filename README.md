# Operating Systems Lab

A collection of C programs developed for the Operating Systems Laboratory, covering process management, inter-process communication, CPU scheduling, and page replacement algorithms.

## 🧪 List of Experiments

| S.No. | Experiment | Source Code | Status |
| ----- | ---------- | ----------- | ------ |
| 1 | Demonstration of `fork()` System Call | [Program](July31/Class/q2_parent_child.c) | Complete |
| 2 | Parent Process Computes Sum of Odd Numbers and Child Process Computes Sum of Even Numbers Using `fork()` | [Program](Oct23/odd_even_sum_fork.c) | Complete |
| 3 | Demonstration of `wait()` System Call | [Program](July31/Class/q3_wait.c) | Complete |
| 4 | Implementation of Orphan Process and Zombie Process | [Orphan](July31/Homework/orphan_process_demo.c), [Zombie](July31/Homework/zombie_process_demo.c) | Complete |
| 5 | Implementation of Pipe | [Program](Oct23/pipe.c) | Complete |
| 6 | Implementation of FIFO / Named Pipe | [Writer](Oct23/fifo_writer.c), [Reader](Oct23/fifo_reader.c) | Complete |
| 7 | Implementation of Message Queue | [Sender](Oct23/message_sender.c), [Receiver](Oct23/message_receiver.c) | Complete |
| 8 | Implementation of Shared Memory | [Writer](Oct23/shared_writer.c), [Reader](Oct23/shared_reader.c) | Complete |
| 9 | Implementation of FCFS CPU Scheduling | [Program](Oct30/fcfs.c) | Complete |
| 10 | Implementation of SJF CPU Scheduling | [Program](Oct30/sjf.c) | Complete |
| 11 | Implementation of Priority Scheduling | [Program](Oct30/priority.c) | Complete |
| 12 | Implementation of FIFO Page Replacement Algorithm | [Program](Oct30/fifo_page.c) | Complete |
| 13 | Implementation of LRU Page Replacement Algorithm | [Program](Oct30/lru_page.c) | Complete |

### Repository Structure

```text
Aug7/Class/
Aug17/Class/
July31/
  Class/
  Homework/
Sep18/
Sep25/
  Sep25/
  __MACOSX/
Oct16/
Oct23/  Process sums and IPC
Oct30/  CPU scheduling and page replacement
README.md
```

### Compilation and Execution

From the repository root, compile and run a program on Linux:

```bash
gcc -Wall -Wextra Oct23/odd_even_sum_fork.c -o odd_even_sum_fork
./odd_even_sum_fork
```

Compile the two files in each IPC pair separately. Run both executables from the same working directory.

- **Named pipe** — Run the writer in one terminal and enter a message. While the writer waits, run the reader in a second terminal. The reader removes `myfifo`.
- **Message queue** — Run the sender first and then the receiver. The receiver removes the queue.
- **Shared memory** — Run the writer to completion before running the reader. The reader removes the shared memory segment.

The scheduling programs assume that all processes are available at time zero. FCFS uses input order. SJF and priority scheduling are non-preemptive and use input order for ties. A smaller priority number indicates higher priority.

### Technologies Used

C, GCC, Linux/Unix, and GitHub.

### Reference

Operating Systems Laboratory Manual, Academic Session 2026–27.

### Notes

[OS Lab notes on Google Drive](https://drive.google.com/drive/folders/1cgoAxjrQ6s09EXEoFg5ZmxytkWOAT7B0?usp=sharing)
