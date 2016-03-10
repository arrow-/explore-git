#The `liquid` 

`liquid` is a simple CLI math application that can solve simple math problems.

#How is the code organised?

This is the directory structure:
```
└── liquid
    ├── liquid.cpp
    ├── testing.cpp
    ├── shunting-yard.cpp
    ├── shunting-yard.h
    ├── Makefile
    └── src
        ├── math-lib.h
        ├── ml_add.cpp
        ├── ml_div.cpp
        ├── ml_mul.cpp
        ├── ml_sub.cpp
        ├── .
        ├── .
        ├── .
        └── ml_*****.cpp
```


We've already made the CLI which can be used to input a math expression and get the result.
>Credit: @bamos for implementing the Shunting-Yard Algorithm in `cpp`.
It's basically the RPN expression parser, which pushes into a `stack` to parse an expression and then evaluate based on priority rules by `popping` the `stack`.

The name of the CLI file is `liquid.cpp`. *You don't have to edit `liquid.cpp`.*

#What do I edit?

See the `src/` directory? Read `math-lib.h`. This is the list of functions that provide the computational functionality to `liquid`.
```
double ml_add(double, double);
double ml_mul(double, double);
double ml_div(double, double);
double ml_sub(double, double);

```
But, except the `add`, `mul`, `div`, and `sub`, files, the rest are empty.
And there's also a template file (`ml_template.cpp`).

#Appendix

**CLI**
*Command Line Interface. It means a* **terminal** *is opened for the user, not a GUI.*