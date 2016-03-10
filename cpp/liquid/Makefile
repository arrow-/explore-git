# ADD THE SOURCE FILE NAME THAT YOU HAVE JUST CREATED to the `src_files` VARIABLE.
# FOLLOW THE CONVENTION:
# 		prefix function name with `ml_`
# 
# run:
# 
# $ make liquid
# 
# YOU'LL FIND AN EXECUTABLE CALLED `liquid`
# 
# launch it using 
# 
# $ ./liquid

# ADD THE FILE NAME HERE
# \/\/\/\/\/\/\/\/\/\/\/
src_files = ml_add \
			ml_sub \
			ml_mul \
			ml_div \
			ml_mod \
			ml_power \
			ml_perms \
			ml_combos \
			ml_isPrime \
			ml_nextPrime \
			ml_factorial \
			ml_factorise \
			ml_gcd \
			ml_lcm

#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#
# 				 DON'T TOUCH BELOW THIS           #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

srcdir = src/
build_dir = build/

DEPS = math-lib.h

CFLAGS = -Wall -std=c99 -c -I. -I$(srcdir)
LDFLAGS = -lm
SOURCES = $(src_files:%=$(srcdir)%.cpp)
OBJECTS = $(src_files:%=$(build_dir)%.o)

# $@ is TARGET
# $< is first pre-requisite
# $^ is space-separated list of all pre-requisites

$(build_dir)%.o: $(srcdir)%.c $(srcdir)math-lib.h
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

%.o: %.c shunting-yard.h stack.h $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

liquid: liquid.o $(OBJECTS) shunting-yard.o stack.o
	$(CC) -Wall -std=c99 -I $(srcdir) -I. $? -o $@ $(LDFLAGS)

again: clean liquid

test:
	./liquid

clean:
	@rm build/*.[ao]
	@rm *.[ao]
