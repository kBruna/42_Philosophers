*This project has been created as part of the 42 curriculum by buehara.*

# 42_Philosophers

42's Project Philosophers

## Description

### Overview

This is 42's project tackling the classic problem proposed by Edsger Dijkstra, the Dining Philosophers. It's a famous problem about concurrent algorithm to ilustrate issues with threads and processes synchronization, and the techniques for resolving them.
The simulation starts with N philosophers with N forks available on the table. All philosophers can eat, think and sleep all day, but they can only eat with two forks available. So, they can only eat if they take turns to use the forks. 


### Goal

The main goal if the project is not to make the philosopher live forever, but to understand the main tecniques to orchestrate threads in a way to solve the common problems of data racing, race conditions, and other problems that may happen when dealing with threads.

## Instructions
The program take the following arguments:


◦ number_of_philosophers: The number of philosophers and also the number of forks.

◦ time_to_die (in milliseconds): If a philosopher has not started eating within time_to_die milliseconds since the start of their last meal or the start of the simulation, they die.

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

• Each philosopher has a number ranging from 1 to number_of_philosophers.

• Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher, numbered N, sits between philosopher N - 1 and philosopher N + 1.

To install this project on Linux systems, run the following command in the terminal:
```bash
git clone https://github.com/kBruna/42_Philosophers.git philo && cd philo && make
```

The Makefile will handle the basic installation.

To run this program, follow this command structure:
```bash
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
```

The numbers can be separated with spaces as individual arguments:
```bash
./philo 4 420 150 150
```

## Resources

Here are some of the links and references used in this project, along with some comments about the use of AI:

- [Light and easy tester by MichelleJiam](https://github.com/MichelleJiam/LazyPhilosophersTester)
- [Medium article about Data Racing and Race Conditions](https://abdulahd1996.medium.com/data-races-vs-race-conditions-understanding-the-differences-in-concurrency-602042cd54b2)
- [Wiki Article about the Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Oceano YouTube Video about the 42's Philo project](https://www.youtube.com/watch?v=zOpzGHwJ3MU)
- [DeRuina GitHub project walthrough](https://github.com/DeRuina/philosophers)



### About AI

Yes, I used AI, mostly to understand the problem and the consequences of the common problems that usually appear during this project. Also to check the alowed functions and understand how to use those.
