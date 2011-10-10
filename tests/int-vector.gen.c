//! Created by Chris Miller on 24 December 2009.
//! Copyright 2010 FSDEV. Aw richts is pitten by.
//! Updated to an ERB-based generator on 10 October 2011.
//! This file is generated; modifying it is totally OK, but
//! your modifications might get removed if this file is
//! regenerated again.

#include "int-vector.gen.h"

float __int_vector_growth = 2.0f;

struct int_vector* int_vector_create(register size_t capacity) {
    struct int_vector* v = (struct int_vector*)malloc(sizeof(struct int_vector));
    v->data = (int*)malloc(sizeof(int)*capacity);
    v->length = 0;
    v->capacity = capacity;
    return v;
}
void int_vector_free(struct int_vector* v) {
    free(v->data);
    free(v);
}
void int_vector_free_with_block(struct int_vector* v, void(^block)(int)) {
    for (size_t i=0; i<v->length; ++i)
        block(v->data[i]);
    free(v->data);
    free(v);
}
void int_vector_grow(struct int_vector* v) {
    register size_t new_capacity = v->capacity * __int_vector_growth;
    v-> data = (int*)realloc(v->data,
        (size_t)(sizeof(int) * new_capacity));
    v->capacity = new_capacity;
}
void int_vector_grow_to(struct int_vector* v, register size_t s) {
    v->data = (int*)realloc(v->data, (size_t)(sizeof(int) * s));
    v->capacity = s;
}
void int_vector_shrink(struct int_vector* v) {
    int_vector_grow_to(v, v->size);
}
void int_vector_push_back(struct int_vector* v, const int t) {
    if (v->capacity <= v->length)
        int_vector_grow(v);
    v->data[v->length ++] = t;
}
int int_vector_pop_back(struct int_vector* v) {
    return v->data[-- v->length];
}
void int_vector_insert(struct int_vector* v,
                         register const size_t idx,
                         const int t) {
    if(v->capacity <= v->length)
        int_vector_grow(v);
    memmove(v->data+idx+1, v->data+idx, sizeof(t) * (v->length - idx));
    ++ v->length;
    v->data[idx] = t;
}
void int_vector_insert_range(struct int_vector* v,
                               register const size_t idx,
                               int* begin,
                               int* end) {
    register size_t a1 = end - begin;
    register size_t a2 = a1 + v->length;
    if(v->capacity <= a2)
        int_vector_grow_to(v, a2);
    memmove(v->data+idx+a1, v->data+idx, sizeof(int) * (v->length - idx));
    memcpy(v->data+idx, begin, sizeof(int) * a1);
    v->length += a1;
}
void int_vector_remove_range(struct int_vector* v,
                               register const size_t begin,
                               register const size_t end) {
    int* tmp = (int*)calloc(v->length - end, sizeof(int));
    memcpy(tmp, v->data+end, sizeof(int) * (v->length - end));
    memcpy(v->data+begin, tmp, sizeof(int) * (v->length - end));
    v->length -= end - begin;
    free(tmp);
}
void int_vector_remove_range_with_block(struct int_vector* v,
                                          register const size_t begin,
                                          register const size_t end,
                                          void(^block)(int)) {
    int* tmp = (int*)calloc(v->length - end, sizeof(int));
    memcpy(tmp, v->data+end, sizeof(int) * (v->length - end));
    memcpy(v->data+begin, tmp, sizeof(int) * (v->length - end));
    for (register size_t i=0; i<v->length-end; ++i)
        block(tmp[i]);
    v->length -= end - begin;
    free(tmp);
}
void int_vector_remove(struct int_vector* v, register const size_t idx) {
    int_vector_remove_range(v, idx, idx+1);
}
