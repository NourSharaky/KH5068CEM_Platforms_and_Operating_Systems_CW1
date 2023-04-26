<hr>

NOUR SHARAKY - 2020000149 - NS00149@tkh.edu.eg

Coventry University - The Knowledge Hub Universities branch - Bsc of Ethical Hacking and Cybersecurity - Level 5.

KH5068CEM Platforms and Operating Systems - Coursework 1

<hr>

<h2>Process Control Block (PCB) Implementation</h2>
This C program is an implementation of the Process Control Block (PCB) data structure  and a FIFO (First In First Out) queue in a simple operating system. The PCB is used to store information about each process, such as its ID, state, name, priority, arrival time, and burst time. The FIFO queue is used to store the processes in the order in which they arrive.

<h3>Stored Information in the PCB</h3>

<b>process_id:</b> An integer representing the ID of the process. <br>
<b>state:</b> A character array representing the state of the process (e.g. NEW, READY, RUNNING, WAITING, TERMINATED). <br>
<b>process_name:</b> A character array representing the name of the process. <br>
<b>priority:</b> An integer representing the priority of the process. <br>
<b>burst_time:</b> An integer representing the amount of time the process needs to complete its execution. <br>
<b>arrival_time:</b> An integer representing the time at which the process arrives. <br>
<b>next_pcb:</b> A pointer to the next PCB in the queue. <br>

