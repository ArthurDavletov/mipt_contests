#include "cstring.h"

size_t Strlen(const char* str) {
  size_t index = 0;
  while (str[index] != '\0') {
    index++;
  }
  return index;
}

int Strcmp(const char* first, const char* second) {
  size_t index = 0;
  while (true) {
    if (first[index] < second[index]) {
      return -1;
    }
    if (first[index] > second[index]) {
      return 1;
    }
    if (first[index] == '\0' || second[index] == '\0') {
      break;
    }
    index++;
  }
  return 0;
}

int Strncmp(const char* first, const char* second, size_t count) {
  for (size_t index = 0; index < count; index++) {
    if (first[index] < second[index]) {
      return -1;
    }
    if (first[index] > second[index]) {
      return 1;
    }
    if (first[index] == '\0' || second[index] == '\0') {
      break;
    }
  }
  return 0;
}

char* Strcpy(char* dest, const char* src) {
  size_t index = 0;
  while (true) {
    dest[index] = src[index];
    if (src[index] == '\0') {
      break;
    }
    index++;
  }
  return dest;
}

char* Strncpy(char* dest, const char* src, size_t count) {
  size_t index = 0;
  for (; index < count; index++) {
    if (src[index] == '\0') {
      break;
    }
    dest[index] = src[index];
  }
  for (; index < count; index++) {
    dest[index] = '\0';
  }
  return dest;
}

char* Strcat(char* dest, const char* src) {
  size_t index = 0;
  while (dest[index] != '\0') {
    index++;
  }
  for (size_t i = 0; src[i] != '\0'; i++) {
    dest[index++] = src[i];
  }
  return dest;
}

char* Strncat(char* dest, const char* src, size_t count) {
  size_t index = 0;
  while (dest[index] != '\0') {
    index++;
  }
  for (size_t i = 0; i < count; i++) {
    dest[index++] = src[i];
    if (src[i] == '\0') {
      return dest;
    }
  }
  dest[index] = '\0';
  return dest;
}

const char* Strchr(const char* str, char symbol) {
  size_t i = 0;
  for (; str[i] != '\0'; i++) {
    if (str[i] == symbol) {
      return &str[i];
    }
  }
  if (symbol == '\0') {
    return &str[i];
  }
  return nullptr;
}

const char* Strrchr(const char* str, char symbol) {
  size_t index = 0;
  while (str[index] != '\0') {
    index++;
  }
  for (; index > 0; index--) {
    if (str[index] == symbol) {
      return &str[index];
    }
  }
  if (str[0] == symbol) {
    return &str[0];
  }
  return nullptr;
}

size_t Strspn(const char* dest, const char* src) {
  size_t index = 0;
  for (; dest[index] != '\0'; index++) {
    if (!Strchr(src, dest[index])) {
      return index;
    }
  }
  return index;
}

size_t Strcspn(const char* dest, const char* src) {
  size_t index = 0;
  for (; dest[index] != '\0'; index++) {
    if (Strchr(src, dest[index])) {
      return index;
    }
  }
  return index;
}

const char* Strpbrk(const char* dest, const char* breakset) {
  for (size_t index = 0; dest[index] != '\0'; index++) {
    if (Strchr(breakset, dest[index])) {
      return &dest[index];
    }
  }
  return nullptr;
}

const char* Strstr(const char* str, const char* pattern) {
  size_t str_len = Strlen(str);
  size_t pattern_len = Strlen(pattern);
  if (pattern_len > str_len) {
    return nullptr;
  }
  for (size_t i = 0; i < str_len - pattern_len + 1; i++) {
    size_t j = 0;
    for (; j < pattern_len; j++) {
      if (str[i + j] != pattern[j]) {
        break;
      }
    }
    if (j == pattern_len) {
      return &str[i];
    }
  }
  return nullptr;
}