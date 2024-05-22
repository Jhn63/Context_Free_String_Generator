# Context-free String Generator

A context-free grammar is a set of recursive rules used to generate patterns of strings. <br>
In this project, we made a program that spits out strings from a context-free grammar

![grammar](image/grammar.png)

## Solution approach

To make a reasonable generation of strings, it was need to use the data struct N-ary tree and the breadth-first search algorithm

![tree](image/tree.png)

Each branch of the tree is a possible route for the generation and the nodes are the state of the string. The tree grows following the breadth-first search concept, once a leaf is hit we back-track the path done and it will be shown

By using this method we guarantee none of the branches will be generated more than once

## How to use

There's an executable inside the bin folder <br>
To run the program call it from a terminal and pass a text file as a reference, for example: CFString_Generator sample.txt

There are two modes of execution

- **Fast One**: It uses the method previously explained, you can generate as many strings as you want, or as many as the grammar (or your machine) is capable of doing

- **Detail One**: Here you can choose which branch you want to follow. The program will ask what are the next derivation of the most left non-terminal symbol until it reaches 0 non-terminals, which means a leaf node

## Issues

Besides the program evades generating repeated strings, this is only possible for non-ambiguous grammar. In an ambiguous grammar, the same string could be generated from two or more syntactic trees, therefore our approach could not recognize this scenario

## Additional information

That was an academic project made by [João Barreto](https://github.com/Jhn63) and [João Cirilo](https://github.com/jcirilo). <br>
We also made a [video](https://youtu.be/Ml0ykvG_4J8) where we explain and show the project

If you have any question be free to contact me, thank you
