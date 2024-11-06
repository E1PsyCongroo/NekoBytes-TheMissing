#include "linkedlist.h"

void insert(zuma *node, zuma *new_node) {
  new_node->pre = node;
  new_node->nxt = node->nxt;
  if (node->nxt != NULL)
    node->nxt->pre = new_node;
  else
    tail = new_node;
  node->nxt = new_node;
  return;
}

void delete(zuma *node) {
  if (node == head)
    head = node->nxt;
  if (node == tail)
    tail = node->pre;
  if (node->pre != NULL)
    node->pre->nxt = node->nxt;
  if (node->nxt != NULL)
    node->nxt->pre = node->pre;
  free(node);
  len--;
  return;
}