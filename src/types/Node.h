#pragma once

typedef struct Node {
  struct Task *value;
  struct Node *prev, *next;
} Node;
