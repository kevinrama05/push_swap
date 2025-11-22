#ifndef GENERATED_H
#define GENERATED_H

unsigned int hash(int key, size_t size) ;
entry_t *ht_pair(unsigned int key, unsigned int value) ;
ht_t *ht_create(size_t size) ;
void ht_set(ht_t *hashtable, unsigned int key, unsigned int value, size_t size) ;
unsigned int ht_get(ht_t *hashtable, unsigned int key, size_t size) ;
void ht_dump(ht_t *hashtable, size_t size) ;
void free_ht(ht_t *table) ;

#endif
