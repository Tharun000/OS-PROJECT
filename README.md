# OS-PROJECT
Operating System simulation based projects.



#-----------------------------------------------------------Question:-07----------------------------------------------------------------
Problem:
       Researchers designed one system that classified interactive and noninteractive processes automatically by looking at the amount of terminal I/O. If a process did not input or output to the terminal in a 1-second interval, the process was classified as noninteractive and was moved to a lower-priority queue. In response to this policy, one programmer modified his programs to write an arbitrary character to the terminal at regular intervals of less than 1 second. The system gave his programs a high priority, even though the terminal output was completely meaningless.

Explantion:
          In the above problem actually researchers designed a system to classify the processes into two categories(i.e., Interactive processes and non-interactive processes)
1.Interactice process:- If response time is less than one second.(<1s)
2.Non-Interactive process:-If response time is greater or equal to  one second(>=1s).
If the process is interactive it will be sent to high priority queue otherwise to low priority queue. This is working on the basis of priority scheduling algorithm.

Many of the user’s or programmers are not interested in running only a particular processes like if interactive processes are given priority over non-interactive processes then the programmer could divide larger process(more time taking) into smaller process(Interactive processes) and make it interactive process and is interested in sending it to high priority queue same thing has done by programmer in this problem.





#-----------------------------------------------------------Question:-10----------------------------------------------------------------












Problem:
There are 3 student processes and 1 teacher process. Students are supposed to do their assignments and they need 3 things for that pen, paper and question paper. The teacher has an infinite supply of all the three things. One students has pen,an other has paper and another has question paper. The teacher places two things on a shared table and the student having the third complementary thing makes the assignment and tells the teacher on completion. The teacher then places another two things out of the three and again the student having the third thing makes the assignment and tells the teacher on completion. This cycle continues. WAP to synchronize the teacher and the students.



Explanation: 1. In the given solution I have taken all the student processes and resources in 2D array and initialized then to 0. 2. I have made 3 student processes in three different functions which will be executed by single s_thread and one t_thread for execution of teacher process. 3. User will get a menu to select any two out of three resources that are to be placed on shared table. 4. If one process is completed there will be a message printed on the screen saying process is completed. 5. When one process is executing no other student or teacher process will execute and for achieving this I have used Mutex lock. 6. When a process starts to execute it acquires the lock and when it completes the execution releases the lock. 7. After completion of all the three processes the program will end.
