* [Collaborative Projects worth making](#collaborative-projects-worth-making)
    - [Math-Lib](#math-lib-gnu-c)
        + [List of Functions](#list-of-functions)
    - [String Processing](#string-processing)
        + [List of Functions](#list-of-functions_1)
    - [Game](#game)
        + [Candidates](#candidates)
        + [List of Functions](#list-of-functions_1)
* [Non Collaborative, yet..](#non-collaborative-yet)
        + [List of Functions](#list-of-functions-1)
    - [Game](#game)
        + [Candidates](#candidates)
        + [List of Functions](#list-of-functions-2)

#IDEAS

Some nice software should come out of this event.

##Collaborative Projects worth making

The projects *must* follow the [guidelines](CONTRIBUTING.md).

###Math-Lib `[gnu c++]`

Build a CLI math solver which uses functions defined by the teams. Teams can work on non-overlapping functionalities.

* Simple code, as it's based on intermediate maths, which everyone knows.
* Correctness and testing is easy.
* Little documentation required.

<<<<<<< HEAD
**We'll have to make the glue application, in `c++`, mostly working on user input handling, displaying results, etc.**
Teams will implement their function(s) in small source files (as already [done](cpp/math-lib/src/arithmetic.cpp)).
=======
**We'll have to make the glue application, in `c++`, mostly working on user input handling, displaying results, etc. See [cpp-expression-parser](https://github.com/bamos/cpp-expression-parser)**
Teams will implement their function(s) in small source files (as already [done](cpp/liquid/src/ml_add.cpp)).
>>>>>>> d8c0f38cd79e2b30f6f7afe773a61962e177c3c4
The app is built using `make`. They need not understand what it does. Teams who have time left can add documentation, review other PRs, perform testing and flag issues, or add even more functionality!

####List of Functions
* arithmetic {+-*/%} ("pre-done")
* power
>w/ and w/o `<cmath>`

* factorize
* isPrime
* nextPrime
* base_conversions
* nth_roots
>w/ and w/o using `<cmath.sqrt` or `cmath.pow`

* GCD, LCM
* *Matrix Algebra {only `double` matrices}
    - arithmetic {+-*/} ("pre-done")
    - power
    - adjoint, cofactor, inverse
* *Plot a function
>Directly use gnuplot?

* *Numerical Methods {this is from SICP! I'm sure y'all forgot!}
    - Differentiation
    - Integration

###String Processing

I can't think of a *"cool"* glue application for these functions yet, but these are pretty easy to implement, so...

####List of Functions
* word_count
* char_count, alpha_count, numeric_count, punctuation_count, ...
* convert tabs to 4 whitespaces, vice versa
* search and replace
* histograms
    - char, word
* spell check (standard english dictionary avlbl as `plain-text`)
* palindromes

###Game

We can use `python` to visualise the game, yet keep the game engine in `c++`. So, we select a ***super simple POPULAR*** game, a game with very simple mechanics.

####Candidates
+ Pocket Tanks (complicated terrain physics)
+ Brick smasher
+ ping pong
+ mario/dave/platformer

We write the game engine completely, test it. Then remove most of the core part which needs to be filled in by the teams.
*Suited for second/third year teams.*
Since all game objects are predefined, teams won't be "clueless" *(I hope!)*.

* Cool end product, completion is itself a strong incentive.
* Teams need not worry about graphics, human interaction. Just implement the function as specified in the docs.
* Requires very good documentation.
* High challenge (need to read docs, source code then write compliant code), but more close to real industry situations.

####List of Functions
Typically, teams will implement:

* Map generation
* scoring (health, mana, score, etc)
* game mechanics (turn policy, this is the overall mainloop)
* game physics
<<<<<<< HEAD
* *game-specific methods*

##Non Collaborative, yet..

**help in learning `git`**
=======
* *game-specific methods*
>>>>>>> d8c0f38cd79e2b30f6f7afe773a61962e177c3c4
