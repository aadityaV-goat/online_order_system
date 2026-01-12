#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

int getValidatedChoice();
int getValidatedInt(const char *prompt);
void getValidatedName(const char *prompt, char *name, size_t size);

#endif


