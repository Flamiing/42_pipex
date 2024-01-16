# <p align="center">🛠️PIPEX🛠️</p>

### <p align="center">Redirections and Pipes</p>

---
**What is this project about?**</br>
**PIPEX** is a command line program written in **C** that aims to replicate redirections and pipes in **Bash**.</br>

---
## Biggest Challenges 💪:

It was a challenging but intriguing task to replicate the functionality of redirections and pipes in Bash. The primary difficulty was to ensure that my program behaved in exactly the same way as Bash would. One of the most daunting aspects of this project was to make sure that my program provided the same status code as Bash in similar situations and handled the redirection of input and output files correctly even if they were inaccessible.

## How to use?:
Using this program is really simple. After cloning the repository, navigate to the folder and run `make` to compile the program. Once compiled, execute it using a command similar to this:
```bash
./pipex infile command1 command2 outfile
```

## Examples:

- Example 1:
  ```
  ./pipex infile "ls -l" "wc -l" outfile
  ```
  Should behave as:
  ```bash
  < infile ls -l | wc -l > outfile
  ```

- Example 2:
  ```
  ./pipex infile "grep a1" "wc -w" outfile
  ```
  Should behave as:
  ```bash
  < infile grep a1 | wc -w > outfile
  ```
