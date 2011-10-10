//! Created by Chris Miller on 24 December 2009.
//! Copyright 2010 FSDEV. Aw richts is pitten by.
//! Updated to an ERB-based generator on 10 October 2011.
//! This file is generated; modifying it is totally OK, but
//! your modifications might get removed if this file is
//! regenerated again (ie. automated build tools).

#ifndef __INT_VECTOR_H__
#define __INT_VECTOR_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * This defines how much the vector will grow when it needs to expand. By default, this is `2.0f`.
 */    
extern
float __int_vector_growth;

struct int_vector {
    int* data;
    union {
        size_t length;
        size_t size;
    };
    size_t capacity;
};

struct int_vector* int_vector_create(register size_t capacity);
void int_vector_free(struct int_vector* v);
void int_vector_free_with_block(struct int_vector* v, void(^block)(int));
void int_vector_grow(struct int_vector* v);
void int_vector_grow_to(struct int_vector* v, register size_t s);
void int_vector_shrink(struct int_vector* v);
void int_vector_push_back(struct int_vector* v, const int t);
int int_vector_pop_back(struct int_vector* v);
void int_vector_insert(struct int_vector* v, register const size_t idx, const int t);
void int_vector_insert_range(struct int_vector* v, register const size_t idx, int* begin, int* end);
void int_vector_remove_range(struct int_vector* v, register const size_t begin, register const size_t end);
void int_vector_remove_range_with_block(struct int_vector* v, register const size_t begin, register const size_t end, void(^block)(int));
void int_vector_remove(struct int_vector* v, register const size_t idx);

#endif