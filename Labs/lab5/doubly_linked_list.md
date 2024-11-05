
# 双端链表

比起朴素链表，双端链表额外维护了每一个节点的前继，支持我们进行更多操作

## 双端链表结构

![双端链表结构](static/list-1.png)

- data：数据
- nxt：记录这个节点之后的节点
- pre：记录这个节点之前的节点

```C
typedef int Type;
//Type可以是任何你需要的数据类型
struct Node{
    struct Node *pre,*nxt;
    Type data;
};
typedef struct Node node;
```

我们申请空间时会得到一个指向该空间的指针，所以pre和nxt的类型也是指针，指向相邻节点的地址

当我们需要遍历链表时，肯定需要有一个起点，我们称这个起点为头指针，指向最靠前的节点，该节点的pre为NULL

当我们向链表插入节点时，没有特殊的要求时会将其插入到尾部，也就是最后一个节点之后，指向该节点的指针成为尾指针，该节点的nxt为null

```C
node *head=NULL,*tail=NULL;
//虽然全局变量初值皆为0，但是初始化是个好习惯🤓
```

## 双端链表操作

### 遍历双端链表

与朴素链表无异

```C
/*
传入位次
返回指向对应节点地址的指针
*/
node *find(int rank){
    int i=0;
    node *tmp=head;
    for(;i<rank-1;i++){
        tmp = tmp->nxt;
    }
    return tmp;
}
```

![遍历双端链表-1](static/list-2.png)

![遍历双端链表-2](static/list-3.png)

### 尾部插入节点

与朴素链表几乎无异，仅需要额外更新pre属性

```C
void add_tail(Type data){
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->pre = NULL;
    tmp->nxt = NULL;
    if(head == NULL){
        head = tmp;
        tail = tmp;
        return;
    }
    tail->nxt = tmp;
    tmp->pre = tail;
    tail = tmp;
    return;
}
```

![尾部插入节点-1](static/list-4.png)

![尾部插入节点-2](static/list-5.png)

![尾部插入节点-3](static/list-6.png)

### 指定节点后插入节点

与朴素链表几乎无异，仅需要额外更新pre属性

```C
void add_node(node *pos,Type data){
    if(pos==tail){
        add_tail(data);
        return;
    }
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->pre = NULL;
    tmp->nxt = NULL;
    tmp->pre=pos;
    tmp->nxt=pos->nxt;
    pos->nxt->pre=tmp;
    pos->nxt=tmp;
}
```

![指定节点后插入节点-1](static/list-7.png)

![指定节点后插入节点-2](static/list-8.png)

![指定节点后插入节点-3](static/list-9.png)

### 删除指定节点

与朴素链表几乎无异，仅需要额外更新pre属性

```C
void delete(node *pos){
    if(head==tail){
        head = NULL;
        tail = NULL;
        return;
    }else if(pos == head){
        head=pos->nxt;
        head->pre=NULL;
    }else if(pos == tail){
        tail = pos->pre;
        tail->nxt = NULL;
    }else{
        pos->nxt->pre=pos->pre;
        pos->pre->nxt=pos->nxt;
    }
    free(pos);// 不要忘！
    return;
}
```

![删除指定节点-1](static/list-10.png)

![删除指定节点-2](static/list-11.png)

![删除指定节点-3](static/list-12.png)
