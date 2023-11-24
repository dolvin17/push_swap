Push Swap

Push Swap is a sorting algorithm project implemented in C. It focuses on efficiently sorting a stack of integers using a set of predefined instructions while aiming to minimize the number of instructions used.
Project Description

The primary goal of Push Swap is to develop a program that receives an unsorted stack of integers and returns a sequence of instructions to sort the stack in ascending order. The challenge lies in achieving this with the fewest possible instructions, making it an exercise in optimization.
Features

* Efficient sorting algorithm: Push Swap implements a custom sorting algorithm that minimizes the number of instructions required to sort the stack.
* Input validation: The program handles various input scenarios, ensuring the stack's integrity and validating user input.
* Detailed instructions: Push Swap provides clear and concise output instructions for sorting the stack.

Usage

To use Push Swap, provide an unsorted stack as command-line arguments, and the program will output a sequence of instructions to sort the stack efficiently.

bash

./push_swap $(cat nbrs.txt)

Getting Started

To get started with Push Swap, clone the repository and compile the code using the provided Makefile. Then, you can run the program with your input data.

bash

1) git clone https://github.com/dolvin17/push_swap.git
2) cd push_swap
3) make
4) edit size of nbrs array on random.c at main.
5) gcc random.c
6) ./a.out > nbrs.txt
7) ./push_swap $(cat nbrs.txt) | ./checker_Mac $(cat nbrs.txt)

cheers!


