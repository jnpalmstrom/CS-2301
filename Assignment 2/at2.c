at3.c                                                                                               0000664 0001752 0001752 00000003740 13066346223 014230  0                                                                                                    ustar   jackpalmstrom                   jackpalmstrom                                                                                                                                                                                                          /** file at3.c
 * @author Mike Ciaraldi
 *
 * Program to demonstrate fixed-size arrays in C.
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

// --------------------- Header Files -------------------------------- //
                                                                       //
#include <stdio.h>                                                     //
#include <stdlib.h>                                                    //
#include <time.h>                                                      //
#include "print_arrays.h"                                              //
#include "sort.h"                                                      //
// ------------------------------------------------------------------- //

// --------------------- CONSTANTS ----------------------------------- //
//                                                                     //
#define SAMPLE_INT_ARRAY_SIZE (10)                                     //
// ------------------------------------------------------------------- //

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main() {

// -------------------- Variables -----------------------------------  //
                                                                       // 
  int i;                                                               // Loop Counter
  int a[SAMPLE_INT_ARRAY_SIZE];                                        // Sample array for demonstration
// ------------------------------------------------------------------- //
  
  srand(time(NULL));

  populate_random(a, SAMPLE_INT_ARRAY_SIZE);

  // Prints the array of unsorted random integers
  printf("Unsorted Random Integers: \n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);
  
  bubble_sort(a, SAMPLE_INT_ARRAY_SIZE);

  printf("\n");
  printf("Sorted Random Integers: \n");
  // Prints the array of sorted random integers
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);

  return 0;
}
                                at.c                                                                                                0000664 0001752 0001752 00000003776 13066344714 014161  0                                                                                                    ustar   jackpalmstrom                   jackpalmstrom                                                                                                                                                                                                          /** file at.c
 * @author Mike Ciaraldi
 *
 * Program to demonstrate fixed-size arrays in C.
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

// --------------------- Header Files --------------------- //
//                                                          //
#include <stdio.h>                                          //
#include "print_arrays.h"                                   //
// -------------------------------------------------------- //

// --------------------- CONSTANTS ------------------------ //
//                                                          //
#define SAMPLE_INT_ARRAY_SIZE (10)                          //
#define SAMPLE_DOUBLE_ARRAY_SIZE (5)                        //
// ---------------------------------------------------------//

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main() {
// -------------------- Variables ------------------------- //
                                                            //
  int i = 0;                                                // Loop counter
  int j = 0;                                                // Loop counter for array of doubles
  double dub = 0.0;                                         // 
  int a[SAMPLE_INT_ARRAY_SIZE];                             // Sample array for int demonstration
  double b[SAMPLE_INT_ARRAY_SIZE];                          // Sample array for doubles
// -------------------------------------------------------- //
  
  // Fill the array with consecutive integers
  for (i; i < SAMPLE_INT_ARRAY_SIZE; i++) {
    a[i] = i;
  }
  
  // Fill the array with consecutive doubles
  for (j; j < SAMPLE_DOUBLE_ARRAY_SIZE; j++) {
    b[j] = dub;
    dub += 1.0;
  }
  printf("Consecutive Integers: \n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);
  printf("\n");
  printf("Consecutive Doubles: \n");
  print_double_array(b, SAMPLE_DOUBLE_ARRAY_SIZE);

  return 0; // Success!
}
  print_arrays.c                                                                                      0000664 0001752 0001752 00000004724 13066342160 016255  0                                                                                                    ustar   jackpalmstrom                   jackpalmstrom                                                                                                                                                                                                          /** file print_arrays.c
 * @author Mike Ciaraldi
 *
 * Functions for printing arrays.
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

// --------------------- Header Files --------------------- //
//                                                          //
#include <stdio.h>                                          //
#include <stdlib.h>                                         //
#include "print_arrays.h"                                   //
// -------------------------------------------------------- //

/** Print an array of ints, one per line.
 *  @param a Array to print
 *  @param num_entries Number of entries in the array
 */

void print_int_array(int a[], int num_entries) {

// -------------------- Variables ------------------------- //
  int i;                                                    // Loop counter
// -------------------------------------------------------- //

  for (i = 0; i < num_entries; i++) {
    printf("%d\n", a[i]);
  }
}


/** Print an array of doubles, one per line.
 *  @param d Array to print
 *  @param num_entries Number of entries in the array
*/

void print_double_array(double d[], int num_entries) {

// -------------------- Variables ------------------------- //       
  int i;                                                    // Loop Counter
// -------------------------------------------------------- //

  for (i = 0; i < num_entries; i++){
    printf("%f\n", d[i]);
  }
}

/** Seperate function for getting integer data from the command line
 *  and storing it into an array
 * @param argc Number of elements in the array 
 * @param argv Array of characters from command line input
 * @param storage_array Array to fill with integers
 * @param size_of_array Size of the array being filled with ints
 */
  
int fillArray(int argc, const char* argv[], int storage_array[], int size_of_array) {

// -------------------- Variables ------------------------- // 
  int i;                                                    // Loop Counter
  int index = 0;                                            // Index counter
// -------------------------------------------------------- //
  
  // Fill the array with ints from the command line
  for (i = 0; i < size_of_array; i++) {

    
    if ((i + 1) > (argc - 1)) {
      index = argc - 1;
      break;
    }
    
        
    storage_array[index] = atoi(argv[i + 1]);
    index += 1;
  } 
  return index; 
}
                                            sort.c                                                                                              0000664 0001752 0001752 00000003476 13066346617 014545  0                                                                                                    ustar   jackpalmstrom                   jackpalmstrom                                                                                                                                                                                                          /** file sort.c
 * @author Jack Palmstrom
 *
 * Program to sort arrays and generate random integers .
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

// --------------------- Header Files -------------------------------- //
                                                                       //
#include <stdlib.h>                                                    //
// ------------------------------------------------------------------- //

// --------------------- CONSTANTS ----------------------------------- //
//                                                                     //
#define MAX_RANDOM_INT (10)                                            //
// ------------------------------------------------------------------- //

/**
 * sorts the given array of integers into ascending order using bubble sort
 * @param array Array of integers to be sorted
 * @param num_elements total number of elements in the array
 */

void bubble_sort(int a[], int num_elements) {

  int i, j, temp;
  
  for(i = 0; i < num_elements; i++){
    
    for(j = 0; j < num_elements; j++){
      
      if(a[i] < a[j]){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

/**
 * generates a random integer from 0 to max inclusive
 * @param max the largest possible number returned 
 * @return the generated random integer
 */
int gen_random(int max){
  
  int rand_gen; //the random integer to be generated
  
  rand_gen = rand() % (max + 1); //generate random int between 0 and max inclusive
  return rand_gen;
}

/**
 * populates an array with random integers
 * @param a the Array to be filled
 * @param num_elements the length of the array
 */
void populate_random(int a[], int num_elements){

  int i = 0;

  for(i; i < num_elements; i++){
    
    a[i] = gen_random(MAX_RANDOM_INT);
    
  }
}
                                                                                                                                                                                                  print_arrays.h                                                                                      0000664 0001752 0001752 00000001013 13066345614 016255  0                                                                                                    ustar   jackpalmstrom                   jackpalmstrom                                                                                                                                                                                                          /** File print_arrays.h
 * @author Mike Ciaraldi
 *
 * Header file for functions that print arrays.
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

#ifndef PRINT_ARRAYS_H
#define PRINT_ARRAYS_H

// Function prototypes:

void print_int_array(int a[], int size);
void print_double_array(double a[], int size);
int fillArray(int argc, const char* argv[], int storage_array[], int size_of_array);
void double_fillArray(int argc, const char* argv[], double storage_array[], int size_of_array);

#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     sort.h                                                                                              0000664 0001752 0001752 00000000533 13066345513 014533  0                                                                                                    ustar   jackpalmstrom                   jackpalmstrom                                                                                                                                                                                                          /** File sort.h
 * @author Jack Palmstrom
 *
 * Header file for functions that sort arrays.
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

#ifndef SORT_H
#define SORT_H

// Function Prototypes
void bubble_sort(int a[], int num_elements);
int gen_random(int max);
void populate_random(int a[], int num_elements);

#endif
                                                                                                                                                                     makefile                                                                                            0000664 0001752 0001752 00000001325 13066345576 015104  0                                                                                                    ustar   jackpalmstrom                   jackpalmstrom                                                                                                                                                                                                          all: at at2 at3

at: at.o print_arrays.o
	gcc -g --std=gnu99 at.o print_arrays.o -o at

at.o: at.c print_arrays.h
	gcc -g --std=gnu99 -c at.c

at2: at2.o print_arrays.o sort.o
	gcc -g --std=gnu99 at2.o print_arrays.o sort.o -o at2

at2.o: at2.c print_arrays.h sort.h
	gcc -g --std=gnu99 -c at2.c

at3: at3.o print_arrays.o sort.o
	gcc -g --std=gnu99 at3.o print_arrays.o sort.o -o at3

at3.o: at3.c print_arrays.h sort.h
	gcc -g --std=gnu99 -c at3.c

print_arrays.o: print_arrays.c print_arrays.h
	gcc -g --std=gnu99 -c print_arrays.c

sort.o: sort.c sort.h
	gcc -g --std=gnu99 -c sort.c

docs:
	doxygen
	chmod ugo+rwx -R html
	chmod go-w -R html
	cp -p -r ./html/* ~/public_html/cs2301assig2


clean:
	rm -f *.o at at2 at3

                                                                                                                                                                                                                                                                                                           Doxyfile                                                                                            0000664 0001752 0001752 00000147476 12460513724 015121  0                                                                                                    ustar   jackpalmstrom                   jackpalmstrom                                                                                                                                                                                                          # Doxyfile 1.4.7

# This file describes the settings to be used by the documentation system
# doxygen (www.doxygen.org) for a project
#
# All text after a hash (#) is considered a comment and will be ignored
# The format is:
#       TAG = value [value, ...]
# For lists items can also be appended using:
#       TAG += value [value, ...]
# Values that contain spaces should be placed between quotes (" ")

#---------------------------------------------------------------------------
# Project related configuration options
#---------------------------------------------------------------------------

# The PROJECT_NAME tag is a single word (or a sequence of words surrounded 
# by quotes) that should identify the project.

PROJECT_NAME           = lab2

# The PROJECT_NUMBER tag can be used to enter a project or revision number. 
# This could be handy for archiving the generated documentation or 
# if some version control system is used.

PROJECT_NUMBER         = 

# The OUTPUT_DIRECTORY tag is used to specify the (relative or absolute) 
# base path where the generated documentation will be put. 
# If a relative path is entered, it will be relative to the location 
# where doxygen was started. If left blank the current directory will be used.

OUTPUT_DIRECTORY       = 

# If the CREATE_SUBDIRS tag is set to YES, then doxygen will create 
# 4096 sub-directories (in 2 levels) under the output directory of each output 
# format and will distribute the generated files over these directories. 
# Enabling this option can be useful when feeding doxygen a huge amount of 
# source files, where putting all generated files in the same directory would 
# otherwise cause performance problems for the file system.

CREATE_SUBDIRS         = NO

# The OUTPUT_LANGUAGE tag is used to specify the language in which all 
# documentation generated by doxygen is written. Doxygen will use this 
# information to generate all constant output in the proper language. 
# The default language is English, other supported languages are: 
# Brazilian, Catalan, Chinese, Chinese-Traditional, Croatian, Czech, Danish, 
# Dutch, Finnish, French, German, Greek, Hungarian, Italian, Japanese, 
# Japanese-en (Japanese with English messages), Korean, Korean-en, Norwegian, 
# Polish, Portuguese, Romanian, Russian, Serbian, Slovak, Slovene, Spanish, 
# Swedish, and Ukrainian.

OUTPUT_LANGUAGE        = English

# This tag can be used to specify the encoding used in the generated output. 
# The encoding is not always determined by the language that is chosen, 
# but also whether or not the output is meant for Windows or non-Windows users. 
# In case there is a difference, setting the USE_WINDOWS_ENCODING tag to YES 
# forces the Windows encoding (this is the default for the Windows binary), 
# whereas setting the tag to NO uses a Unix-style encoding (the default for 
# all platforms other than Windows).

USE_WINDOWS_ENCODING   = NO

# If the BRIEF_MEMBER_DESC tag is set to YES (the default) Doxygen will 
# include brief member descriptions after the members that are listed in 
# the file and class documentation (similar to JavaDoc). 
# Set to NO to disable this.

BRIEF_MEMBER_DESC      = YES

# If the REPEAT_BRIEF tag is set to YES (the default) Doxygen will prepend 
# the brief description of a member or function before the detailed description. 
# Note: if both HIDE_UNDOC_MEMBERS and BRIEF_MEMBER_DESC are set to NO, the 
# brief descriptions will be completely suppressed.

REPEAT_BRIEF           = YES

# This tag implements a quasi-intelligent brief description abbreviator 
# that is used to form the text in various listings. Each string 
# in this list, if found as the leading text of the brief description, will be 
# stripped from the text and the result after processing the whole list, is 
# used as the annotated text. Otherwise, the brief description is used as-is. 
# If left blank, the following values are used ("$name" is automatically 
# replaced with the name of the entity): "The $name class" "The $name widget" 
# "The $name file" "is" "provides" "specifies" "contains" 
# "represents" "a" "an" "the"

ABBREVIATE_BRIEF       = 

# If the ALWAYS_DETAILED_SEC and REPEAT_BRIEF tags are both set to YES then 
# Doxygen will generate a detailed section even if there is only a brief 
# description.

ALWAYS_DETAILED_SEC    = NO

# If the INLINE_INHERITED_MEMB tag is set to YES, doxygen will show all 
# inherited members of a class in the documentation of that class as if those 
# members were ordinary class members. Constructors, destructors and assignment 
# operators of the base classes will not be shown.

INLINE_INHERITED_MEMB  = NO

# If the FULL_PATH_NAMES tag is set to YES then Doxygen will prepend the full 
# path before files name in the file list and in the header files. If set 
# to NO the shortest path that makes the file name unique will be used.

FULL_PATH_NAMES        = NO

# If the FULL_PATH_NAMES tag is set to YES then the STRIP_FROM_PATH tag 
# can be used to strip a user-defined part of the path. Stripping is 
# only done if one of the specified strings matches the left-hand part of 
# the path. The tag can be used to show relative paths in the file list. 
# If left blank the directory from which doxygen is run is used as the 
# path to strip.

STRIP_FROM_PATH        = 

# The STRIP_FROM_INC_PATH tag can be used to strip a user-defined part of 
# the path mentioned in the documentation of a class, which tells 
# the reader which header file to include in order to use a class. 
# If left blank only the name of the header file containing the class 
# definition is used. Otherwise one should specify the include paths that 
# are normally passed to the compiler using the -I flag.

STRIP_FROM_INC_PATH    = 

# If the SHORT_NAMES tag is set to YES, doxygen will generate much shorter 
# (but less readable) file names. This can be useful is your file systems 
# doesn't support long names like on DOS, Mac, or CD-ROM.

SHORT_NAMES            = NO

# If the JAVADOC_AUTOBRIEF tag is set to YES then Doxygen 
# will interpret the first line (until the first dot) of a JavaDoc-style 
# comment as the brief description. If set to NO, the JavaDoc 
# comments will behave just like the Qt-style comments (thus requiring an 
# explicit @brief command for a brief description.

JAVADOC_AUTOBRIEF      = NO

# The MULTILINE_CPP_IS_BRIEF tag can be set to YES to make Doxygen 
# treat a multi-line C++ special comment block (i.e. a block of //! or /// 
# comments) as a brief description. This used to be the default behaviour. 
# The new default is to treat a multi-line C++ comment block as a detailed 
# description. Set this tag to YES if you prefer the old behaviour instead.

MULTILINE_CPP_IS_BRIEF = NO

# If the DETAILS_AT_TOP tag is set to YES then Doxygen 
# will output the detailed description near the top, like JavaDoc.
# If set to NO, the detailed description appears after the member 
# documentation.

DETAILS_AT_TOP         = NO

# If the INHERIT_DOCS tag is set to YES (the default) then an undocumented 
# member inherits the documentation from any documented member that it 
# re-implements.

INHERIT_DOCS           = YES

# If the SEPARATE_MEMBER_PAGES tag is set to YES, then doxygen will produce 
# a new page for each member. If set to NO, the documentation of a member will 
# be part of the file/class/namespace that contains it.

SEPARATE_MEMBER_PAGES  = NO

# The TAB_SIZE tag can be used to set the number of spaces in a tab. 
# Doxygen uses this value to replace tabs by spaces in code fragments.

TAB_SIZE               = 8

# This tag can be used to specify a number of aliases that acts 
# as commands in the documentation. An alias has the form "name=value". 
# For example adding "sideeffect=\par Side Effects:\n" will allow you to 
# put the command \sideeffect (or @sideeffect) in the documentation, which 
# will result in a user-defined paragraph with heading "Side Effects:". 
# You can put \n's in the value part of an alias to insert newlines.

ALIASES                = 

# Set the OPTIMIZE_OUTPUT_FOR_C tag to YES if your project consists of C 
# sources only. Doxygen will then generate output that is more tailored for C. 
# For instance, some of the names that are used will be different. The list 
# of all members will be omitted, etc.

OPTIMIZE_OUTPUT_FOR_C  = NO

# Set the OPTIMIZE_OUTPUT_JAVA tag to YES if your project consists of Java 
# sources only. Doxygen will then generate output that is more tailored for Java. 
# For instance, namespaces will be presented as packages, qualified scopes 
# will look different, etc.

OPTIMIZE_OUTPUT_JAVA   = NO

# If you use STL classes (i.e. std::string, std::vector, etc.) but do not want to 
# include (a tag file for) the STL sources as input, then you should 
# set this tag to YES in order to let doxygen match functions declarations and 
# definitions whose arguments contain STL classes (e.g. func(std::string); v.s. 
# func(std::string) {}). This also make the inheritance and collaboration 
# diagrams that involve STL classes more complete and accurate.

BUILTIN_STL_SUPPORT    = NO

# If member grouping is used in the documentation and the DISTRIBUTE_GROUP_DOC 
# tag is set to YES, then doxygen will reuse the documentation of the first 
# member in the group (if any) for the other members of the group. By default 
# all members of a group must be documented explicitly.

DISTRIBUTE_GROUP_DOC   = NO

# Set the SUBGROUPING tag to YES (the default) to allow class member groups of 
# the same type (for instance a group of public functions) to be put as a 
# subgroup of that type (e.g. under the Public Functions section). Set it to 
# NO to prevent subgrouping. Alternatively, this can be done per class using 
# the \nosubgrouping command.

SUBGROUPING            = YES

#---------------------------------------------------------------------------
# Build related configuration options
#---------------------------------------------------------------------------

# If the EXTRACT_ALL tag is set to YES doxygen will assume all entities in 
# documentation are documented, even if no documentation was available. 
# Private class members and static file members will be hidden unless 
# the EXTRACT_PRIVATE and EXTRACT_STATIC tags are set to YES

EXTRACT_ALL            = YES

# If the EXTRACT_PRIVATE tag is set to YES all private members of a class 
# will be included in the documentation.

EXTRACT_PRIVATE        = YES

# If the EXTRACT_STATIC tag is set to YES all static members of a file 
# will be included in the documentation.

EXTRACT_STATIC         = YES

# If the EXTRACT_LOCAL_CLASSES tag is set to YES classes (and structs) 
# defined locally in source files will be included in the documentation. 
# If set to NO only classes defined in header files are included.

EXTRACT_LOCAL_CLASSES  = YES

# This flag is only useful for Objective-C code. When set to YES local 
# methods, which are defined in the implementation section but not in 
# the interface are included in the documentation. 
# If set to NO (the default) only methods in the interface are included.

EXTRACT_LOCAL_METHODS  = NO

# If the HIDE_UNDOC_MEMBERS tag is set to YES, Doxygen will hide all 
# undocumented members of documented classes, files or namespaces. 
# If set to NO (the default) these members will be included in the 
# various overviews, but no documentation section is generated. 
# This option has no effect if EXTRACT_ALL is enabled.

HIDE_UNDOC_MEMBERS     = NO

# If the HIDE_UNDOC_CLASSES tag is set to YES, Doxygen will hide all 
# undocumented classes that are normally visible in the class hierarchy. 
# If set to NO (the default) these classes will be included in the various 
# overviews. This option has no effect if EXTRACT_ALL is enabled.

HIDE_UNDOC_CLASSES     = NO

# If the HIDE_FRIEND_COMPOUNDS tag is set to YES, Doxygen will hide all 
# friend (class|struct|union) declarations. 
# If set to NO (the default) these declarations will be included in the 
# documentation.

HIDE_FRIEND_COMPOUNDS  = NO

# If the HIDE_IN_BODY_DOCS tag is set to YES, Doxygen will hide any 
# documentation blocks found inside the body of a function. 
# If set to NO (the default) these blocks will be appended to the 
# function's detailed documentation block.

HIDE_IN_BODY_DOCS      = NO

# The INTERNAL_DOCS tag determines if documentation 
# that is typed after a \internal command is included. If the tag is set 
# to NO (the default) then the documentation will be excluded. 
# Set it to YES to include the internal documentation.

INTERNAL_DOCS          = NO

# If the CASE_SENSE_NAMES tag is set to NO then Doxygen will only generate 
# file names in lower-case letters. If set to YES upper-case letters are also 
# allowed. This is useful if you have classes or files whose names only differ 
# in case and if your file system supports case sensitive file names. Windows 
# and Mac users are advised to set this option to NO.

CASE_SENSE_NAMES       = YES

# If the HIDE_SCOPE_NAMES tag is set to NO (the default) then Doxygen 
# will show members with their full class and namespace scopes in the 
# documentation. If set to YES the scope will be hidden.

HIDE_SCOPE_NAMES       = NO

# If the SHOW_INCLUDE_FILES tag is set to YES (the default) then Doxygen 
# will put a list of the files that are included by a file in the documentation 
# of that file.

SHOW_INCLUDE_FILES     = YES

# If the INLINE_INFO tag is set to YES (the default) then a tag [inline] 
# is inserted in the documentation for inline members.

INLINE_INFO            = YES

# If the SORT_MEMBER_DOCS tag is set to YES (the default) then doxygen 
# will sort the (detailed) documentation of file and class members 
# alphabetically by member name. If set to NO the members will appear in 
# declaration order.

SORT_MEMBER_DOCS       = YES

# If the SORT_BRIEF_DOCS tag is set to YES then doxygen will sort the 
# brief documentation of file, namespace and class members alphabetically 
# by member name. If set to NO (the default) the members will appear in 
# declaration order.

SORT_BRIEF_DOCS        = NO

# If the SORT_BY_SCOPE_NAME tag is set to YES, the class list will be 
# sorted by fully-qualified names, including namespaces. If set to 
# NO (the default), the class list will be sorted only by class name, 
# not including the namespace part. 
# Note: This option is not very useful if HIDE_SCOPE_NAMES is set to YES.
# Note: This option applies only to the class list, not to the 
# alphabetical list.

SORT_BY_SCOPE_NAME     = NO

# The GENERATE_TODOLIST tag can be used to enable (YES) or 
# disable (NO) the todo list. This list is created by putting \todo 
# commands in the documentation.

GENERATE_TODOLIST      = YES

# The GENERATE_TESTLIST tag can be used to enable (YES) or 
# disable (NO) the test list. This list is created by putting \test 
# commands in the documentation.

GENERATE_TESTLIST      = YES

# The GENERATE_BUGLIST tag can be used to enable (YES) or 
# disable (NO) the bug list. This list is created by putting \bug 
# commands in the documentation.

GENERATE_BUGLIST       = YES

# The GENERATE_DEPRECATEDLIST tag can be used to enable (YES) or 
# disable (NO) the deprecated list. This list is created by putting 
# \deprecated commands in the documentation.

GENERATE_DEPRECATEDLIST= YES

# The ENABLED_SECTIONS tag can be used to enable conditional 
# documentation sections, marked by \if sectionname ... \endif.

ENABLED_SECTIONS       = 

# The MAX_INITIALIZER_LINES tag determines the maximum number of lines 
# the initial value of a variable or define consists of for it to appear in 
# the documentation. If the initializer consists of more lines than specified 
# here it will be hidden. Use a value of 0 to hide initializers completely. 
# The appearance of the initializer of individual variables and defines in the 
# documentation can be controlled using \showinitializer or \hideinitializer 
# command in the documentation regardless of this setting.

MAX_INITIALIZER_LINES  = 30

# Set the SHOW_USED_FILES tag to NO to disable the list of files generated 
# at the bottom of the documentation of classes and structs. If set to YES the 
# list will mention the files that were used to generate the documentation.

SHOW_USED_FILES        = YES

# If the sources in your project are distributed over multiple directories 
# then setting the SHOW_DIRECTORIES tag to YES will show the directory hierarchy 
# in the documentation. The default is NO.

SHOW_DIRECTORIES       = NO

# The FILE_VERSION_FILTER tag can be used to specify a program or script that 
# doxygen should invoke to get the current version for each file (typically from the 
# version control system). Doxygen will invoke the program by executing (via 
# popen()) the command <command> <input-file>, where <command> is the value of 
# the FILE_VERSION_FILTER tag, and <input-file> is the name of an input file 
# provided by doxygen. Whatever the program writes to standard output 
# is used as the file version. See the manual for examples.

FILE_VERSION_FILTER    = 

#---------------------------------------------------------------------------
# configuration options related to warning and progress messages
#---------------------------------------------------------------------------

# The QUIET tag can be used to turn on/off the messages that are generated 
# by doxygen. Possible values are YES and NO. If left blank NO is used.

QUIET                  = NO

# The WARNINGS tag can be used to turn on/off the warning messages that are 
# generated by doxygen. Possible values are YES and NO. If left blank 
# NO is used.

WARNINGS               = YES

# If WARN_IF_UNDOCUMENTED is set to YES, then doxygen will generate warnings 
# for undocumented members. If EXTRACT_ALL is set to YES then this flag will 
# automatically be disabled.

WARN_IF_UNDOCUMENTED   = YES

# If WARN_IF_DOC_ERROR is set to YES, doxygen will generate warnings for 
# potential errors in the documentation, such as not documenting some 
# parameters in a documented function, or documenting parameters that 
# don't exist or using markup commands wrongly.

WARN_IF_DOC_ERROR      = YES

# This WARN_NO_PARAMDOC option can be abled to get warnings for 
# functions that are documented, but have no documentation for their parameters 
# or return value. If set to NO (the default) doxygen will only warn about 
# wrong or incomplete parameter documentation, but not about the absence of 
# documentation.

WARN_NO_PARAMDOC       = NO

# The WARN_FORMAT tag determines the format of the warning messages that 
# doxygen can produce. The string should contain the $file, $line, and $text 
# tags, which will be replaced by the file and line number from which the 
# warning originated and the warning text. Optionally the format may contain 
# $version, which will be replaced by the version of the file (if it could 
# be obtained via FILE_VERSION_FILTER)

WARN_FORMAT            = "$file:$line: $text"

# The WARN_LOGFILE tag can be used to specify a file to which warning 
# and error messages should be written. If left blank the output is written 
# to stderr.

WARN_LOGFILE           = 

#---------------------------------------------------------------------------
# configuration options related to the input files
#---------------------------------------------------------------------------

# The INPUT tag can be used to specify the files and/or directories that contain 
# documented source files. You may enter file names like "myfile.cpp" or 
# directories like "/usr/src/myproject". Separate the files or directories 
# with spaces.

INPUT                  = 

# If the value of the INPUT tag contains directories, you can use the 
# FILE_PATTERNS tag to specify one or more wildcard pattern (like *.cpp 
# and *.h) to filter out the source-files in the directories. If left 
# blank the following patterns are tested: 
# *.c *.cc *.cxx *.cpp *.c++ *.java *.ii *.ixx *.ipp *.i++ *.inl *.h *.hh *.hxx 
# *.hpp *.h++ *.idl *.odl *.cs *.php *.php3 *.inc *.m *.mm *.py

FILE_PATTERNS          = 

# The RECURSIVE tag can be used to turn specify whether or not subdirectories 
# should be searched for input files as well. Possible values are YES and NO. 
# If left blank NO is used.

RECURSIVE              = NO

# The EXCLUDE tag can be used to specify files and/or directories that should 
# excluded from the INPUT source files. This way you can easily exclude a 
# subdirectory from a directory tree whose root is specified with the INPUT tag.

EXCLUDE                = 

# The EXCLUDE_SYMLINKS tag can be used select whether or not files or 
# directories that are symbolic links (a Unix filesystem feature) are excluded 
# from the input.

EXCLUDE_SYMLINKS       = NO

# If the value of the INPUT tag contains directories, you can use the 
# EXCLUDE_PATTERNS tag to specify one or more wildcard patterns to exclude 
# certain files from those directories. Note that the wildcards are matched 
# against the file with absolute path, so to exclude all test directories 
# for example use the pattern */test/*

EXCLUDE_PATTERNS       = 

# The EXAMPLE_PATH tag can be used to specify one or more files or 
# directories that contain example code fragments that are included (see 
# the \include command).

EXAMPLE_PATH           = 

# If the value of the EXAMPLE_PATH tag contains directories, you can use the 
# EXAMPLE_PATTERNS tag to specify one or more wildcard pattern (like *.cpp 
# and *.h) to filter out the source-files in the directories. If left 
# blank all files are included.

EXAMPLE_PATTERNS       = 

# If the EXAMPLE_RECURSIVE tag is set to YES then subdirectories will be 
# searched for input files to be used with the \include or \dontinclude 
# commands irrespective of the value of the RECURSIVE tag. 
# Possible values are YES and NO. If left blank NO is used.

EXAMPLE_RECURSIVE      = NO

# The IMAGE_PATH tag can be used to specify one or more files or 
# directories that contain image that are included in the documentation (see 
# the \image command).

IMAGE_PATH             = 

# The INPUT_FILTER tag can be used to specify a program that doxygen should 
# invoke to filter for each input file. Doxygen will invoke the filter program 
# by executing (via popen()) the command <filter> <input-file>, where <filter> 
# is the value of the INPUT_FILTER tag, and <input-file> is the name of an 
# input file. Doxygen will then use the output that the filter program writes 
# to standard output.  If FILTER_PATTERNS is specified, this tag will be 
# ignored.

INPUT_FILTER           = 

# The FILTER_PATTERNS tag can be used to specify filters on a per file pattern 
# basis.  Doxygen will compare the file name with each pattern and apply the 
# filter if there is a match.  The filters are a list of the form: 
# pattern=filter (like *.cpp=my_cpp_filter). See INPUT_FILTER for further 
# info on how filters are used. If FILTER_PATTERNS is empty, INPUT_FILTER 
# is applied to all files.

FILTER_PATTERNS        = 

# If the FILTER_SOURCE_FILES tag is set to YES, the input filter (if set using 
# INPUT_FILTER) will be used to filter the input files when producing source 
# files to browse (i.e. when SOURCE_BROWSER is set to YES).

FILTER_SOURCE_FILES    = NO

#---------------------------------------------------------------------------
# configuration options related to source browsing
#---------------------------------------------------------------------------

# If the SOURCE_BROWSER tag is set to YES then a list of source files will 
# be generated. Documented entities will be cross-referenced with these sources. 
# Note: To get rid of all source code in the generated output, make sure also 
# VERBATIM_HEADERS is set to NO.

SOURCE_BROWSER         = NO

# Setting the INLINE_SOURCES tag to YES will include the body 
# of functions and classes directly in the documentation.

INLINE_SOURCES         = NO

# Setting the STRIP_CODE_COMMENTS tag to YES (the default) will instruct 
# doxygen to hide any special comment blocks from generated source code 
# fragments. Normal C and C++ comments will always remain visible.

STRIP_CODE_COMMENTS    = YES

# If the REFERENCED_BY_RELATION tag is set to YES (the default) 
# then for each documented function all documented 
# functions referencing it will be listed.

REFERENCED_BY_RELATION = YES

# If the REFERENCES_RELATION tag is set to YES (the default) 
# then for each documented function all documented entities 
# called/used by that function will be listed.

REFERENCES_RELATION    = YES

# If the REFERENCES_LINK_SOURCE tag is set to YES (the default)
# and SOURCE_BROWSER tag is set to YES, then the hyperlinks from
# functions in REFERENCES_RELATION and REFERENCED_BY_RELATION lists will
# link to the source code.  Otherwise they will link to the documentstion.

REFERENCES_LINK_SOURCE = YES

# If the USE_HTAGS tag is set to YES then the references to source code 
# will point to the HTML generated by the htags(1) tool instead of doxygen 
# built-in source browser. The htags tool is part of GNU's global source 
# tagging system (see http://www.gnu.org/software/global/global.html). You 
# will need version 4.8.6 or higher.

USE_HTAGS              = NO

# If the VERBATIM_HEADERS tag is set to YES (the default) then Doxygen 
# will generate a verbatim copy of the header file for each class for 
# which an include is specified. Set to NO to disable this.

VERBATIM_HEADERS       = YES

#---------------------------------------------------------------------------
# configuration options related to the alphabetical class index
#---------------------------------------------------------------------------

# If the ALPHABETICAL_INDEX tag is set to YES, an alphabetical index 
# of all compounds will be generated. Enable this if the project 
# contains a lot of classes, structs, unions or interfaces.

ALPHABETICAL_INDEX     = NO

# If the alphabetical index is enabled (see ALPHABETICAL_INDEX) then 
# the COLS_IN_ALPHA_INDEX tag can be used to specify the number of columns 
# in which this list will be split (can be a number in the range [1..20])

COLS_IN_ALPHA_INDEX    = 5

# In case all classes in a project start with a common prefix, all 
# classes will be put under the same header in the alphabetical index. 
# The IGNORE_PREFIX tag can be used to specify one or more prefixes that 
# should be ignored while generating the index headers.

IGNORE_PREFIX          = 

#---------------------------------------------------------------------------
# configuration options related to the HTML output
#---------------------------------------------------------------------------

# If the GENERATE_HTML tag is set to YES (the default) Doxygen will 
# generate HTML output.

GENERATE_HTML          = YES

# The HTML_OUTPUT tag is used to specify where the HTML docs will be put. 
# If a relative path is entered the value of OUTPUT_DIRECTORY will be 
# put in front of it. If left blank `html' will be used as the default path.

HTML_OUTPUT            = html

# The HTML_FILE_EXTENSION tag can be used to specify the file extension for 
# each generated HTML page (for example: .htm,.php,.asp). If it is left blank 
# doxygen will generate files with .html extension.

HTML_FILE_EXTENSION    = .html

# The HTML_HEADER tag can be used to specify a personal HTML header for 
# each generated HTML page. If it is left blank doxygen will generate a 
# standard header.

HTML_HEADER            = 

# The HTML_FOOTER tag can be used to specify a personal HTML footer for 
# each generated HTML page. If it is left blank doxygen will generate a 
# standard footer.

HTML_FOOTER            = 

# The HTML_STYLESHEET tag can be used to specify a user-defined cascading 
# style sheet that is used by each HTML page. It can be used to 
# fine-tune the look of the HTML output. If the tag is left blank doxygen 
# will generate a default style sheet. Note that doxygen will try to copy 
# the style sheet file to the HTML output directory, so don't put your own 
# stylesheet in the HTML output directory as well, or it will be erased!

HTML_STYLESHEET        = 

# If the HTML_ALIGN_MEMBERS tag is set to YES, the members of classes, 
# files or namespaces will be aligned in HTML using tables. If set to 
# NO a bullet list will be used.

HTML_ALIGN_MEMBERS     = YES

# If the GENERATE_HTMLHELP tag is set to YES, additional index files 
# will be generated that can be used as input for tools like the 
# Microsoft HTML help workshop to generate a compressed HTML help file (.chm) 
# of the generated HTML documentation.

GENERATE_HTMLHELP      = NO

# If the GENERATE_HTMLHELP tag is set to YES, the CHM_FILE tag can 
# be used to specify the file name of the resulting .chm file. You 
# can add a path in front of the file if the result should not be 
# written to the html output directory.

CHM_FILE               = 

# If the GENERATE_HTMLHELP tag is set to YES, the HHC_LOCATION tag can 
# be used to specify the location (absolute path including file name) of 
# the HTML help compiler (hhc.exe). If non-empty doxygen will try to run 
# the HTML help compiler on the generated index.hhp.

HHC_LOCATION           = 

# If the GENERATE_HTMLHELP tag is set to YES, the GENERATE_CHI flag 
# controls if a separate .chi index file is generated (YES) or that 
# it should be included in the master .chm file (NO).

GENERATE_CHI           = NO

# If the GENERATE_HTMLHELP tag is set to YES, the BINARY_TOC flag 
# controls whether a binary table of contents is generated (YES) or a 
# normal table of contents (NO) in the .chm file.

BINARY_TOC             = NO

# The TOC_EXPAND flag can be set to YES to add extra items for group members 
# to the contents of the HTML help documentation and to the tree view.

TOC_EXPAND             = NO

# The DISABLE_INDEX tag can be used to turn on/off the condensed index at 
# top of each HTML page. The value NO (the default) enables the index and 
# the value YES disables it.

DISABLE_INDEX          = NO

# This tag can be used to set the number of enum values (range [1..20]) 
# that doxygen will group on one line in the generated HTML documentation.

ENUM_VALUES_PER_LINE   = 4

# If the GENERATE_TREEVIEW tag is set to YES, a side panel will be
# generated containing a tree-like index structure (just like the one that 
# is generated for HTML Help). For this to work a browser that supports 
# JavaScript, DHTML, CSS and frames is required (for instance Mozilla 1.0+, 
# Netscape 6.0+, Internet explorer 5.0+, or Konqueror). Windows users are 
# probably better off using the HTML help feature.

GENERATE_TREEVIEW      = NO

# If the treeview is enabled (see GENERATE_TREEVIEW) then this tag can be 
# used to set the initial width (in pixels) of the frame in which the tree 
# is shown.

TREEVIEW_WIDTH         = 250

#---------------------------------------------------------------------------
# configuration options related to the LaTeX output
#---------------------------------------------------------------------------

# If the GENERATE_LATEX tag is set to YES (the default) Doxygen will 
# generate Latex output.

GENERATE_LATEX         = YES

# The LATEX_OUTPUT tag is used to specify where the LaTeX docs will be put. 
# If a relative path is entered the value of OUTPUT_DIRECTORY will be 
# put in front of it. If left blank `latex' will be used as the default path.

LATEX_OUTPUT           = latex

# The LATEX_CMD_NAME tag can be used to specify the LaTeX command name to be 
# invoked. If left blank `latex' will be used as the default command name.

LATEX_CMD_NAME         = latex

# The MAKEINDEX_CMD_NAME tag can be used to specify the command name to 
# generate index for LaTeX. If left blank `makeindex' will be used as the 
# default command name.

MAKEINDEX_CMD_NAME     = makeindex

# If the COMPACT_LATEX tag is set to YES Doxygen generates more compact 
# LaTeX documents. This may be useful for small projects and may help to 
# save some trees in general.

COMPACT_LATEX          = NO

# The PAPER_TYPE tag can be used to set the paper type that is used 
# by the printer. Possible values are: a4, a4wide, letter, legal and 
# executive. If left blank a4wide will be used.

PAPER_TYPE             = a4wide

# The EXTRA_PACKAGES tag can be to specify one or more names of LaTeX 
# packages that should be included in the LaTeX output.

EXTRA_PACKAGES         = 

# The LATEX_HEADER tag can be used to specify a personal LaTeX header for 
# the generated latex document. The header should contain everything until 
# the first chapter. If it is left blank doxygen will generate a 
# standard header. Notice: only use this tag if you know what you are doing!

LATEX_HEADER           = 

# If the PDF_HYPERLINKS tag is set to YES, the LaTeX that is generated 
# is prepared for conversion to pdf (using ps2pdf). The pdf file will 
# contain links (just like the HTML output) instead of page references 
# This makes the output suitable for online browsing using a pdf viewer.

PDF_HYPERLINKS         = NO

# If the USE_PDFLATEX tag is set to YES, pdflatex will be used instead of 
# plain latex in the generated Makefile. Set this option to YES to get a 
# higher quality PDF documentation.

USE_PDFLATEX           = NO

# If the LATEX_BATCHMODE tag is set to YES, doxygen will add the \\batchmode. 
# command to the generated LaTeX files. This will instruct LaTeX to keep 
# running if errors occur, instead of asking the user for help. 
# This option is also used when generating formulas in HTML.

LATEX_BATCHMODE        = NO

# If LATEX_HIDE_INDICES is set to YES then doxygen will not 
# include the index chapters (such as File Index, Compound Index, etc.) 
# in the output.

LATEX_HIDE_INDICES     = NO

#---------------------------------------------------------------------------
# configuration options related to the RTF output
#---------------------------------------------------------------------------

# If the GENERATE_RTF tag is set to YES Doxygen will generate RTF output 
# The RTF output is optimized for Word 97 and may not look very pretty with 
# other RTF readers or editors.

GENERATE_RTF           = NO

# The RTF_OUTPUT tag is used to specify where the RTF docs will be put. 
# If a relative path is entered the value of OUTPUT_DIRECTORY will be 
# put in front of it. If left blank `rtf' will be used as the default path.

RTF_OUTPUT             = rtf

# If the COMPACT_RTF tag is set to YES Doxygen generates more compact 
# RTF documents. This may be useful for small projects and may help to 
# save some trees in general.

COMPACT_RTF            = NO

# If the RTF_HYPERLINKS tag is set to YES, the RTF that is generated 
# will contain hyperlink fields. The RTF file will 
# contain links (just like the HTML output) instead of page references. 
# This makes the output suitable for online browsing using WORD or other 
# programs which support those fields. 
# Note: wordpad (write) and others do not support links.

RTF_HYPERLINKS         = NO

# Load stylesheet definitions from file. Syntax is similar to doxygen's 
# config file, i.e. a series of assignments. You only have to provide 
# replacements, missing definitions are set to their default value.

RTF_STYLESHEET_FILE    = 

# Set optional variables used in the generation of an rtf document. 
# Syntax is similar to doxygen's config file.

RTF_EXTENSIONS_FILE    = 

#---------------------------------------------------------------------------
# configuration options related to the man page output
#---------------------------------------------------------------------------

# If the GENERATE_MAN tag is set to YES (the default) Doxygen will 
# generate man pages

GENERATE_MAN           = NO

# The MAN_OUTPUT tag is used to specify where the man pages will be put. 
# If a relative path is entered the value of OUTPUT_DIRECTORY will be 
# put in front of it. If left blank `man' will be used as the default path.

MAN_OUTPUT             = man

# The MAN_EXTENSION tag determines the extension that is added to 
# the generated man pages (default is the subroutine's section .3)

MAN_EXTENSION          = .3

# If the MAN_LINKS tag is set to YES and Doxygen generates man output, 
# then it will generate one additional man file for each entity 
# documented in the real man page(s). These additional files 
# only source the real man page, but without them the man command 
# would be unable to find the correct page. The default is NO.

MAN_LINKS              = NO

#---------------------------------------------------------------------------
# configuration options related to the XML output
#---------------------------------------------------------------------------

# If the GENERATE_XML tag is set to YES Doxygen will 
# generate an XML file that captures the structure of 
# the code including all documentation.

GENERATE_XML           = NO

# The XML_OUTPUT tag is used to specify where the XML pages will be put. 
# If a relative path is entered the value of OUTPUT_DIRECTORY will be 
# put in front of it. If left blank `xml' will be used as the default path.

XML_OUTPUT             = xml

# The XML_SCHEMA tag can be used to specify an XML schema, 
# which can be used by a validating XML parser to check the 
# syntax of the XML files.

XML_SCHEMA             = 

# The XML_DTD tag can be used to specify an XML DTD, 
# which can be used by a validating XML parser to check the 
# syntax of the XML files.

XML_DTD                = 

# If the XML_PROGRAMLISTING tag is set to YES Doxygen will 
# dump the program listings (including syntax highlighting 
# and cross-referencing information) to the XML output. Note that 
# enabling this will significantly increase the size of the XML output.

XML_PROGRAMLISTING     = YES

#---------------------------------------------------------------------------
# configuration options for the AutoGen Definitions output
#---------------------------------------------------------------------------

# If the GENERATE_AUTOGEN_DEF tag is set to YES Doxygen will 
# generate an AutoGen Definitions (see autogen.sf.net) file 
# that captures the structure of the code including all 
# documentation. Note that this feature is still experimental 
# and incomplete at the moment.

GENERATE_AUTOGEN_DEF   = NO

#---------------------------------------------------------------------------
# configuration options related to the Perl module output
#---------------------------------------------------------------------------

# If the GENERATE_PERLMOD tag is set to YES Doxygen will 
# generate a Perl module file that captures the structure of 
# the code including all documentation. Note that this 
# feature is still experimental and incomplete at the 
# moment.

GENERATE_PERLMOD       = NO

# If the PERLMOD_LATEX tag is set to YES Doxygen will generate 
# the necessary Makefile rules, Perl scripts and LaTeX code to be able 
# to generate PDF and DVI output from the Perl module output.

PERLMOD_LATEX          = NO

# If the PERLMOD_PRETTY tag is set to YES the Perl module output will be 
# nicely formatted so it can be parsed by a human reader.  This is useful 
# if you want to understand what is going on.  On the other hand, if this 
# tag is set to NO the size of the Perl module output will be much smaller 
# and Perl will parse it just the same.

PERLMOD_PRETTY         = YES

# The names of the make variables in the generated doxyrules.make file 
# are prefixed with the string contained in PERLMOD_MAKEVAR_PREFIX. 
# This is useful so different doxyrules.make files included by the same 
# Makefile don't overwrite each other's variables.

PERLMOD_MAKEVAR_PREFIX = 

#---------------------------------------------------------------------------
# Configuration options related to the preprocessor   
#---------------------------------------------------------------------------

# If the ENABLE_PREPROCESSING tag is set to YES (the default) Doxygen will 
# evaluate all C-preprocessor directives found in the sources and include 
# files.

ENABLE_PREPROCESSING   = YES

# If the MACRO_EXPANSION tag is set to YES Doxygen will expand all macro 
# names in the source code. If set to NO (the default) only conditional 
# compilation will be performed. Macro expansion can be done in a controlled 
# way by setting EXPAND_ONLY_PREDEF to YES.

MACRO_EXPANSION        = NO

# If the EXPAND_ONLY_PREDEF and MACRO_EXPANSION tags are both set to YES 
# then the macro expansion is limited to the macros specified with the 
# PREDEFINED and EXPAND_AS_DEFINED tags.

EXPAND_ONLY_PREDEF     = NO

# If the SEARCH_INCLUDES tag is set to YES (the default) the includes files 
# in the INCLUDE_PATH (see below) will be search if a #include is found.

SEARCH_INCLUDES        = YES

# The INCLUDE_PATH tag can be used to specify one or more directories that 
# contain include files that are not input files but should be processed by 
# the preprocessor.

INCLUDE_PATH           = 

# You can use the INCLUDE_FILE_PATTERNS tag to specify one or more wildcard 
# patterns (like *.h and *.hpp) to filter out the header-files in the 
# directories. If left blank, the patterns specified with FILE_PATTERNS will 
# be used.

INCLUDE_FILE_PATTERNS  = 

# The PREDEFINED tag can be used to specify one or more macro names that 
# are defined before the preprocessor is started (similar to the -D option of 
# gcc). The argument of the tag is a list of macros of the form: name 
# or name=definition (no spaces). If the definition and the = are 
# omitted =1 is assumed. To prevent a macro definition from being 
# undefined via #undef or recursively expanded use the := operator 
# instead of the = operator.

PREDEFINED             = 

# If the MACRO_EXPANSION and EXPAND_ONLY_PREDEF tags are set to YES then 
# this tag can be used to specify a list of macro names that should be expanded. 
# The macro definition that is found in the sources will be used. 
# Use the PREDEFINED tag if you want to use a different macro definition.

EXPAND_AS_DEFINED      = 

# If the SKIP_FUNCTION_MACROS tag is set to YES (the default) then 
# doxygen's preprocessor will remove all function-like macros that are alone 
# on a line, have an all uppercase name, and do not end with a semicolon. Such 
# function macros are typically used for boiler-plate code, and will confuse 
# the parser if not removed.

SKIP_FUNCTION_MACROS   = YES

#---------------------------------------------------------------------------
# Configuration::additions related to external references   
#---------------------------------------------------------------------------

# The TAGFILES option can be used to specify one or more tagfiles. 
# Optionally an initial location of the external documentation 
# can be added for each tagfile. The format of a tag file without 
# this location is as follows: 
#   TAGFILES = file1 file2 ... 
# Adding location for the tag files is done as follows: 
#   TAGFILES = file1=loc1 "file2 = loc2" ... 
# where "loc1" and "loc2" can be relative or absolute paths or 
# URLs. If a location is present for each tag, the installdox tool 
# does not have to be run to correct the links.
# Note that each tag file must have a unique name
# (where the name does NOT include the path)
# If a tag file is not located in the directory in which doxygen 
# is run, you must also specify the path to the tagfile here.

TAGFILES               = 

# When a file name is specified after GENERATE_TAGFILE, doxygen will create 
# a tag file that is based on the input files it reads.

GENERATE_TAGFILE       = 

# If the ALLEXTERNALS tag is set to YES all external classes will be listed 
# in the class index. If set to NO only the inherited external classes 
# will be listed.

ALLEXTERNALS           = NO

# If the EXTERNAL_GROUPS tag is set to YES all external groups will be listed 
# in the modules index. If set to NO, only the current project's groups will 
# be listed.

EXTERNAL_GROUPS        = YES

# The PERL_PATH should be the absolute path and name of the perl script 
# interpreter (i.e. the result of `which perl').

PERL_PATH              = /usr/bin/perl

#---------------------------------------------------------------------------
# Configuration options related to the dot tool   
#---------------------------------------------------------------------------

# If the CLASS_DIAGRAMS tag is set to YES (the default) Doxygen will 
# generate a inheritance diagram (in HTML, RTF and LaTeX) for classes with base 
# or super classes. Setting the tag to NO turns the diagrams off. Note that 
# this option is superseded by the HAVE_DOT option below. This is only a 
# fallback. It is recommended to install and use dot, since it yields more 
# powerful graphs.

CLASS_DIAGRAMS         = YES

# If set to YES, the inheritance and collaboration graphs will hide 
# inheritance and usage relations if the target is undocumented 
# or is not a class.

HIDE_UNDOC_RELATIONS   = YES

# If you set the HAVE_DOT tag to YES then doxygen will assume the dot tool is 
# available from the path. This tool is part of Graphviz, a graph visualization 
# toolkit from AT&T and Lucent Bell Labs. The other options in this section 
# have no effect if this option is set to NO (the default)

HAVE_DOT               = NO

# If the CLASS_GRAPH and HAVE_DOT tags are set to YES then doxygen 
# will generate a graph for each documented class showing the direct and 
# indirect inheritance relations. Setting this tag to YES will force the 
# the CLASS_DIAGRAMS tag to NO.

CLASS_GRAPH            = YES

# If the COLLABORATION_GRAPH and HAVE_DOT tags are set to YES then doxygen 
# will generate a graph for each documented class showing the direct and 
# indirect implementation dependencies (inheritance, containment, and 
# class references variables) of the class with other documented classes.

COLLABORATION_GRAPH    = YES

# If the GROUP_GRAPHS and HAVE_DOT tags are set to YES then doxygen 
# will generate a graph for groups, showing the direct groups dependencies

GROUP_GRAPHS           = YES

# If the UML_LOOK tag is set to YES doxygen will generate inheritance and 
# collaboration diagrams in a style similar to the OMG's Unified Modeling 
# Language.

UML_LOOK               = NO

# If set to YES, the inheritance and collaboration graphs will show the 
# relations between templates and their instances.

TEMPLATE_RELATIONS     = YES

# If the ENABLE_PREPROCESSING, SEARCH_INCLUDES, INCLUDE_GRAPH, and HAVE_DOT 
# tags are set to YES then doxygen will generate a graph for each documented 
# file showing the direct and indirect include dependencies of the file with 
# other documented files.

INCLUDE_GRAPH          = YES

# If the ENABLE_PREPROCESSING, SEARCH_INCLUDES, INCLUDED_BY_GRAPH, and 
# HAVE_DOT tags are set to YES then doxygen will generate a graph for each 
# documented header file showing the documented files that directly or 
# indirectly include this file.

INCLUDED_BY_GRAPH      = YES

# If the CALL_GRAPH and HAVE_DOT tags are set to YES then doxygen will 
# generate a call dependency graph for every global function or class method. 
# Note that enabling this option will significantly increase the time of a run. 
# So in most cases it will be better to enable call graphs for selected 
# functions only using the \callgraph command.

CALL_GRAPH             = NO

# If the CALLER_GRAPH and HAVE_DOT tags are set to YES then doxygen will 
# generate a caller dependency graph for every global function or class method. 
# Note that enabling this option will significantly increase the time of a run. 
# So in most cases it will be better to enable caller graphs for selected 
# functions only using the \callergraph command.

CALLER_GRAPH           = NO

# If the GRAPHICAL_HIERARCHY and HAVE_DOT tags are set to YES then doxygen 
# will graphical hierarchy of all classes instead of a textual one.

GRAPHICAL_HIERARCHY    = YES

# If the DIRECTORY_GRAPH, SHOW_DIRECTORIES and HAVE_DOT tags are set to YES 
# then doxygen will show the dependencies a directory has on other directories 
# in a graphical way. The dependency relations are determined by the #include
# relations between the files in the directories.

DIRECTORY_GRAPH        = YES

# The DOT_IMAGE_FORMAT tag can be used to set the image format of the images 
# generated by dot. Possible values are png, jpg, or gif
# If left blank png will be used.

DOT_IMAGE_FORMAT       = png

# The tag DOT_PATH can be used to specify the path where the dot tool can be 
# found. If left blank, it is assumed the dot tool can be found in the path.

DOT_PATH               = 

# The DOTFILE_DIRS tag can be used to specify one or more directories that 
# contain dot files that are included in the documentation (see the 
# \dotfile command).

DOTFILE_DIRS           = 

# The MAX_DOT_GRAPH_WIDTH tag can be used to set the maximum allowed width 
# (in pixels) of the graphs generated by dot. If a graph becomes larger than 
# this value, doxygen will try to truncate the graph, so that it fits within 
# the specified constraint. Beware that most browsers cannot cope with very 
# large images.

MAX_DOT_GRAPH_WIDTH    = 1024

# The MAX_DOT_GRAPH_HEIGHT tag can be used to set the maximum allows height 
# (in pixels) of the graphs generated by dot. If a graph becomes larger than 
# this value, doxygen will try to truncate the graph, so that it fits within 
# the specified constraint. Beware that most browsers cannot cope with very 
# large images.

MAX_DOT_GRAPH_HEIGHT   = 1024

# The MAX_DOT_GRAPH_DEPTH tag can be used to set the maximum depth of the 
# graphs generated by dot. A depth value of 3 means that only nodes reachable 
# from the root by following a path via at most 3 edges will be shown. Nodes 
# that lay further from the root node will be omitted. Note that setting this 
# option to 1 or 2 may greatly reduce the computation time needed for large 
# code bases. Also note that a graph may be further truncated if the graph's 
# image dimensions are not sufficient to fit the graph (see MAX_DOT_GRAPH_WIDTH 
# and MAX_DOT_GRAPH_HEIGHT). If 0 is used for the depth value (the default), 
# the graph is not depth-constrained.

MAX_DOT_GRAPH_DEPTH    = 0

# Set the DOT_TRANSPARENT tag to YES to generate images with a transparent 
# background. This is disabled by default, which results in a white background. 
# Warning: Depending on the platform used, enabling this option may lead to 
# badly anti-aliased labels on the edges of a graph (i.e. they become hard to 
# read).

DOT_TRANSPARENT        = NO

# Set the DOT_MULTI_TARGETS tag to YES allow dot to generate multiple output 
# files in one run (i.e. multiple -o and -T options on the command line). This 
# makes dot run faster, but since only newer versions of dot (>1.8.10) 
# support this, this feature is disabled by default.

DOT_MULTI_TARGETS      = NO

# If the GENERATE_LEGEND tag is set to YES (the default) Doxygen will 
# generate a legend page explaining the meaning of the various boxes and 
# arrows in the dot generated graphs.

GENERATE_LEGEND        = YES

# If the DOT_CLEANUP tag is set to YES (the default) Doxygen will 
# remove the intermediate dot files that are used to generate 
# the various graphs.

DOT_CLEANUP            = YES

#---------------------------------------------------------------------------
# Configuration::additions related to the search engine   
#---------------------------------------------------------------------------

# The SEARCHENGINE tag specifies whether or not a search engine should be 
# used. If set to NO the values of all tags below this one will be ignored.

SEARCHENGINE           = NO
                                                                                                                                                                                                  README.txt                                                                                          0000664 0001752 0001752 00000002202 13066343625 015066  0                                                                                                    ustar   jackpalmstrom                   jackpalmstrom                                                                                                                                                                                                          Name: Jack Palmstrom
Date: 3/27/2017
Class: CS2301
Section: D03

Brief Description of Each Program:

	at: This program prints an array of consecutive integers, and then it prints an array of consecutive doubles.  	

	at2: This program prints an array of integers entered on the command line, sorts in ascending order, and then prints them again.

	at3: This program generates an array of random integers, prints them, then sorts in ascending order, and then prints them again.

Instructions on How to Compile and Link Programs:

	at: This program can be ran from the command shell with-
			./at

	at2: This program can be ran from the command shell with-
			./at2 n1 n2 n3 ... n(i-1)
             
	
	at3: This program can be ran from the command shell with-
			./at3

Test Data:

	at: No test data (Doesn't rely on input from command line)

	at2: 
		1. I tested 5, 4, 3, 2, 1                       Output: 1, 2, 3, 4, 5
		2. I tested 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0    Output: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 
		3. I tested 9, 8, 7, 5, 6, 4, 3, 2, 1, 0.	Output: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9	

	at3: No test data (Doesn't rely on input from command line)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              