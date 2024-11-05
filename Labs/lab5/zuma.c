#include "zuma.h"

int len;
zuma *head = NULL, *tail = NULL;
int ans = 0;
int K = 0;

void match(zuma *node) {
  if (node == ____)
    return;
  zuma *l = node, *r = node;
  int cnt = 1;
  while (l->pre != ____ && l->color == ____) {
    ____;
    ____;
  }
  while (r->nxt != ____ && r->color == ____) {
    ____;
    ____;
  }
  if (cnt >= 3) {
    ____++;
    zuma *tmp = ____;
    int sum = 0;
    int i;
    for (i = 0; i < cnt; i++) {
      sum += ____;
      zuma *tmp = ____;
      l = ____;
      delete (tmp);
    }
    ans += ____;
    match(tmp);
  }
  return;
}

void insert(zuma *node, zuma *new_node) {
  new_node->pre = ____;
  new_node->nxt = ____;
  if (node->nxt != NULL)
    node->nxt->____ = new_node;
  else
    ____ = new_node;
  node->nxt = ____;
  return;
}
void Insert(int k, int color, int val) {
  if (k > len) {
    printf("illegal operation occurs in Insert");
    exit(0);
  }
  zuma *new_node = ____;
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
  zuma *iter = ____;
  for (i = 0; i < k - 1; i++) {
    ____;
  }
  insert(____);
  match(____);
  return;
}

void delete(zuma *node) {
  if (node == head)
    head = ____;
  if (node == tail)
    tail = ____;
  if (node->pre != NULL)
    node->pre->____ = ____;
  if (node->nxt != NULL)
    node->nxt->____ = ____;
  ____;
  ____--;
  return;
}
void Delete(int k) {
  if (k > len) {
    printf("illegal operation occurs in Delete");
    exit(0);
  }
  int i;
  zuma *iter = ____;
  for (i = 0; i < k - 1; i++) {
    ____;
  }
  zuma *tmp = ____;
  delete (____);
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
  zuma *tmp = ____;
  for (i = 0; i < k - 1; i++) {
    ____; // 仔细思考，将移动前面一整段等价于一个一个____？
  }
  match(____);
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
    if (____)
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

int main() {
  // freopen("random_case.in", "r", stdin); //在使用judge时取消引用这句话
  // freopen("myans.out", "w", stdout); //在使用judge时取消引用这句话

  // 你可以使用freopen更方便地对样例进行测试（包括你自己造的样例）
  // 关于freopen:https://zh.cppreference.com/w/c/io/freopen

  // freopen("case1.in", "r", stdin); //使用case1.in作为输入
  // freopen("myans.out", "w", stdout); //输出至myans.out

  init();
  while (1) {
    ____ = 0;
    solve();
  }
  return 0;
}