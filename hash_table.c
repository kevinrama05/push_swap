#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct entry_t {
    unsigned int key;
    unsigned int value;
    struct entry_t *next;
} entry_t;

typedef struct {
    size_t size;
    entry_t **entries;
} ht_t;

unsigned int hash(int key, size_t size) {
    unsigned int x = (unsigned int)key;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % size;
}

entry_t *ht_pair(unsigned int key, unsigned int value) {
    entry_t *entry = malloc(sizeof(entry_t) * 1);
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

ht_t *ht_create(size_t size) {
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);
    hashtable->entries = malloc(sizeof(entry_t*) * size);
    hashtable->size = size;
    size_t i = 0;
    while (i < size)
	    hashtable->entries[i++] = NULL;

    return hashtable;
}

void ht_set(ht_t *hashtable, unsigned int key, unsigned int value, size_t size) {
    unsigned int slot = hash(key, size);
    entry_t *entry = hashtable->entries[slot];
    if (entry == NULL) {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }
    entry_t *prev;
    while (entry != NULL) {
        if (entry->key == key) {
            entry->value = value;
            return;
        }
        prev = entry;
        entry = prev->next;
    }
    prev->next = ht_pair(key, value);
}

unsigned int ht_get(ht_t *hashtable, unsigned int key, size_t size) {
    unsigned int slot = hash(key, size);
    entry_t *entry = hashtable->entries[slot];
    if (entry == NULL) {
        return -1;
    }
    while (entry != NULL) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

void ht_dump(ht_t *hashtable, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        entry_t *entry = hashtable->entries[i];
        if (entry == NULL) {
            continue;
        }
        printf("slot[%4ld]: ", i);
        for(;;) {
            printf("%u=%u ", entry->key, entry->value);
            if (entry->next == NULL) {
                break;
            }
            entry = entry->next;
        }
        printf("\n");
    }
}

/* void free_ht(ht_t *table)
{
    size_t i;
    entry_t *current;
    entry_t *temp;

    if (!table || !table->entries)
        return;

    i = 0;
    while (i < table->size)
    {
        current = table->entries[i];
        while (current)
        {
            temp = current;
            current = current->next;
            free(temp);
        }
        i++;
    }

    free(table->entries);
    free(table);
} */


void free_ht(ht_t *table) {
    if (!table || !table->entries)
        return;
    for (size_t i = 0; i < table->size; ++i) {
        entry_t *entry = table->entries[i];
        while (entry) {
            entry_t *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(table->entries);
    free(table);
}

/* int main(void) {
    ht_t *ht = ht_create(20);
    int i = 20;
    ht_set(ht, 2, 0, i);
    ht_set(ht, 6, 1, i);
    ht_set(ht, 10, 2, i);
    ht_set(ht, 18, 3, i);
    ht_set(ht, 20, 4, i);
    ht_set(ht, 26, 5, i);
    ht_set(ht, 28, 6, i);
    printf("%u\n", ht_get(ht, 2, i));
    ht_dump(ht, i);
    free_ht(ht);
    return 0;
}
 */