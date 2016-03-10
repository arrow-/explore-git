// Copyright 2011 - 2012, 2014 Brian Marshall. All rights reserved.
//
// Use of this source code is governed by the BSD 2-Clause License that can be
// found in the LICENSE file.

#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "math-lib.h"

#define 	M_PI   3.141592653589793238
#define 	M_E   2.71828182845905
typedef enum {
    OK,
    ERROR_SYNTAX,
    ERROR_OPEN_PARENTHESIS,
    ERROR_CLOSE_PARENTHESIS,
    ERROR_UNRECOGNIZED,
    ERROR_NO_INPUT,
    ERROR_UNDEFINED_FUNCTION,
    ERROR_FUNCTION_ARGUMENTS,
    ERROR_UNDEFINED_CONSTANT
} Status;

// Calculates the result of a mathematical expression.
Status shunting_yard(const char *expression, double *result);

#endif
