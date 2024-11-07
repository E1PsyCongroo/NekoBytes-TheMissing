#include "zuma.h"
#include "linkedlist.h"

int len;
zuma *head = NULL, *tail = NULL;
int ans = 0;
int K = 0;

void match(zuma *node) {
  if (node == NULL)
    return;
  zuma *l = node, *r = node;
  int cnt = 1;
  while (l->pre != NULL && l->color == l->pre->color) {
    cnt++;
    l = l->pre;
  }
  while (r->nxt != NULL && r->color == r->nxt->color) {
    cnt++;
    r = r->nxt;
  }
  if (cnt >= 3) {
    K++;
    zuma *tmp = l->pre;
    int sum = 0;
    int i;
    for (i = 0; i < cnt; i++) {
      sum += l->val;
      zuma *tmp = l;
      l = l->nxt;
      delete (tmp);
    }
    ans += sum * K;
    match(tmp);
  }
  return;
}

void Insert(int k, int color, int val) {
  if (k > len) {
    printf("illegal operation occurs in Insert");
    exit(0);
  }
  zuma *new_node = (zuma *)malloc(sizeof(zuma));
  len++;
  new_node->color = color;
  new_node->val = val;
  new_node->pre = NULL;
  new_node->nxt = NULL;
  if (k == 0) {
    tail = new_node;
    head = new_node;
    return;
  }
  int i;
  zuma *iter = head;
  for (i = 0; i < k - 1; i++) {
    iter = iter->nxt;
  }
  insert(iter, new_node);
  match(new_node);
  return;
}

void Delete(int k) {
  if (k > len) {
    printf("illegal operation occurs in Delete");
    exit(0);
  }
  int i;
  zuma *iter = head;
  for (i = 0; i < k - 1; i++) {
    iter = iter->nxt;
  }
  zuma *tmp = iter->pre;
  delete (iter);
  match(tmp);
  return;
}

void move_back() {
  zuma *node = head;
  head = head->nxt;
  head->pre = NULL;
  tail->nxt = node;
  node->pre = tail;
  node->nxt = NULL;
  tail = node;
  return;
}

void set_top(int k) {
  int i;
  zuma *tmp = head;
  for (i = 0; i < k - 1; i++) {
    move_back();
  }
  match(tmp);
  return;
}

void init() {
  int N;
  scanf("%d", &N);
  int i;
  for (i = 0; i < N; i++) {
    int color, val;
    scanf("%d %d", &color, &val);
    Insert(len, color, val);
  }
  return;
}

void solve() {
  int k = 0, T = 0;
  scanf("%d", &k);
  if (k == 0) {
    if (len == 0)
      ans *= 2;
    printf("%d\n", ans);
    fflush(stdout);
    exit(0);
  }
  scanf("%d", &T);
  if (T == 4) {
    Delete(k);
  } else if (T == 5) {
    set_top(k);
  } else {
    int val = 0;
    scanf("%d", &val);
    Insert(k, T, val);
  }
  return;
}

void print_all() {
  printf("DEBUG:BEGIN\n");
  zuma *iter = head;
  while (iter != NULL) {
    printf("DEBUG:%d %d\n", iter->color, iter->val);
    iter = iter->nxt;
  }
  printf("DEBUG:END\n");
  return;
}

