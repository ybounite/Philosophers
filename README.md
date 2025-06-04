<div align="center">
  <!-- Project Image -->
  <img src="README_files/logo.png" alt="Dining Philosophers" width="500"/>
  
  <!-- Project Title -->
  <h1>Philosophers Project</h1>

  <!-- Badges -->
  <p>
    <img src="https://img.shields.io/badge/score-108%20%2F%20100-success?style=for-the-badge" />
    <img src="https://img.shields.io/github/repo-size/ybounite/Philosophers?style=for-the-badge&logo=github" />
    <img src="https://img.shields.io/github/languages/count/ybounite/Philosophers?style=for-the-badge" />
    <img src="https://img.shields.io/github/last-commit/ybounite/Philosophers?style=for-the-badge" />
  </p>

  <h3>
    <a href="#-about-project">📜 About Project</a> .
    <a href="#-mandatory-part">🔷 Mandatory Part</a> .
    <a href="#-bonus-part">🌟 Bonus Part</a> .
    <a href="#usage">👨‍💻 Usage</a>
  </h3>
</div>


---
  ## 📜 About Project
>42 School Philosophers project designed around Edsger Dijkstra's famous [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). \
> For this project, we must learn about concurrent programming and shared memory synconization.


For detailed information, refer to the [**subject of this project**](README_files/philo_subject.pdf).

	🚀 TLDR: This project is an introduction to the basics of multithreading and multiprocessing.
    	 Work on the same memory space, learn about mutexes, semaphores, and shared memory.
> [🚨 ​!NOTE] \
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.

## 🔷 Mandatory Part

#### The subject describes the problem as follows:

* One or more philosophers sit at a round table.
* There is a large bowl of spaghetti in the middle of the table.
* The spaghetti can only be eaten with two forks.
* There are only as many forks as there are philosophers.
* Each philosopher successively eats, sleeps and thinks.
* If a philosopher hasn't eaten in a certain timeframe, he will die of starvation.
* Philosophers cannot communicate with each other.


#### The program takes the following arguments:

`./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>
[number_of_times_each_philosopher_must_eat]`

* **```number_of_philosophers```**: the number of philosophers around the table.
* **```time_to_die```**: a number representing the time in milliseconds a philosopher has to live after a meal. If a philosopher hasn’t started eating time_to_die milliseconds after the beginning of his last meal or the beginning of the simulation, he will die.
* **```time_to_eat```**: a number representing the time in milliseconds a philosopher takes to finish his meal. During that time, the philosopher keeps his two forks in hand.
* **```time_to_sleep```**: the time in milliseconds that a philosopher spends sleeping.
* **```number_of_times_each_philosopher_must_eat```**: an optional argument that allows the program to stop if all the philosophers have eaten at least that many times. If this argument is not specified, the simulation carries on unless a philosopher dies.



#### Program logs philosophers actions in this format. X is philosopher ID:

```
timestamp_in_ms     X  has taken a fork :
        0           1  is thinking
        0           2  is thinking
        0           2  has taken a fork
        0           2  is eating
        60          2  is sleeping
        60          1  has taken a fork
        60          1  is eating
```
https://github.com/user-attachments/assets/7783cfa4-fd5e-4024-94c2-686b14f92875
