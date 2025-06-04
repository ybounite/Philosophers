<a name="readme-top"></a>
<div aling="center">
  <!-- logo-->
  <a href="https://github.com/ybounite/Philosophers">
  <img src="README_files/logo.png" alt="Logo" width="80" height="80">
  </a>
 
  <!-- Project Name -->
  <h1>Philosophers Project</h1>
  
  <!-- Short Description -->
  <!-- Badges -->
  <p>
  <img src="https://img.shields.io/badge/score-108%20%2F%20100-success?style=for-the-badge" />
  <img src="https://img.shields.io/github/repo-size/ybounite/Philosophers?style=for-the-badge&logo=github" />
  <img src="https://img.shields.io/github/languages/count/ybounite/Philosophers?style=for-the-badge&logo=" />
  <img src="https://img.shields.io/github/last-commit/ybounite/Philosophers?style=for-the-badge">
  <img src=>
  </p>
  <h3>
       <a href="#-about-project"> 📜 About Project</a>
    <span> . </span>
      <a href="#-mandatory-part">🔷 Mandatory Part</a>
    <span> . </span>
      <a href="#-bonus-part">🌟 Bonus Part</a>
    <span> . </span>
      <a herf="#usage"> 👨‍💻 Usage</a>
  </h3>
</div>

---
  ## 📜 About Project
>42 School Philosophers project designed around Edsger Dijkstra's famous [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). \
> For this project, we must learn about concurrent programming and shared memory synconization.


For detailed information, refer to the [**subject of this project**](README_files/philo_subject.pdf).

	🚀 TLDR: This project is an introduction to the basics of multithreading and multiprocessing.
    	 Work on the same memory space, learn about mutexes, semaphores, and shared memory.
> [!NOTE]  
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

