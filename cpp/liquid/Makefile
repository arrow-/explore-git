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
			ml_div

#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#
# 				 DON'T TOUCH BELOW THIS           #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

srcdir = src/
build_dir = build/

DEPS = math-lib.h

CXXFLAGS = -Wall -c -I $(srcdir)

SOURCES = $(src_files:%=$(srcdir)%.cpp)
OBJECTS = $(src_files:%=$(build_dir)%.o)

# $@ is TARGET
# $< is first pre-requisite
# $^ is space-separated list of all pre-requisites

$(build_dir)%.o: $(srcdir)%.cpp $(srcdir)math-lib.h
	$(CXX) $(CXXFLAGS) $< -o $@

liquid: $(OBJECTS)
	$(CXX) -Wall -I $(srcdir) $(LDFLAGS) $@.cpp $? -o $@

clean:
	@rm build/*.[ao]
	@rm *.[ao]