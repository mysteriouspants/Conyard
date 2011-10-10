# Generators

Previously I have used absolutely evil C Preprocessor macros to generate code; this is a new experiment in using Ruby to generate such code.

## Vector

Usage: `rake vector[name, type, file]`

* `name` is the name of the vector in code.
* `type` is the data type that the vector will contain.
* `file` is the output location of the files to be generated.

So if I ran this:

    rake vector[int_vector, int, ~/Code/test/int-vector]

What I would get are two files, `~/Code/test/int-vector.gen.h` and `~/Code/test/int-vector.gen.c`. I would use the vector like so:

    #include "int-vector.h"
    // ...
    struct int_vector* v = int_vector_create(10);
    for(int i=0; i<10; ++i)
        int_vector_push_back(v, i);
    // ...
    int_vector_free(v);
    
This vector is built to be lean and mean. It performs no input sanity checking, and it really doesn't give a crap about what you do to it. Garbage in, garbage out (or possibly a segfault). It also supports `_free_with_block` and `remove_range_with_block`, the purpose of which is the ability to `release` Objective-C objects that may be managed by the vector.

C arrays are much faster than `NSArray`, though they are a heck of a lot harder to work with. If you're having an issue with the performance of an `NSArray`, then this might be your answer. The actual data type is really really simple, so you could very easily write your own custom functions to handle specialized operations. I've just included the basic things that I think are necessary.