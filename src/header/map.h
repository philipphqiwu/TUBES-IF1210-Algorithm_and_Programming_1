#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include <string.h>

#define MAX_MAP_SIZE 100
#define MAX_KEY_LENGTH 50
#define MAX_VAL_LENGTH 50

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VAL_LENGTH];
} MapPair;

typedef struct {
    MapPair items[MAX_MAP_SIZE];
    int size;
} Map;

void initializeMap(Map *m);
bool isMapEmpty(const Map *m);
bool isMapFull(const Map *m);
void addMap(Map *m, const char *key, const char *value);
const char* getMap(Map *m, const char *key);
void removeMap(Map *m, const char *key);
void printMap(const Map *m);

#endif