#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *list=(List *) malloc(sizeof(List));
  list->head=NULL;
  list->tail=NULL;
  list->current=NULL;
     return list;
}

void * firstList(List * list) {
  //retorna y mueve la lista a su primer valor
  if(list->head!=NULL && list->head->data){
    list->current=list->head;
    
    return (void *)list->current->data;
    
  }
  return NULL;
}

void * nextList(List * list) {
  //se confirma que no sea null el sig valor
   if (list->current && list->current->next!=NULL){
     list->current=list->current->next;
     return (void *)list->current->data;
   }
    return NULL;
}

void * lastList(List * list) {
  if(list->tail && list->tail->data){
    list->current=list->tail;
    return (void *)list->current->data;
  }
    return NULL;
}

void * prevList(List * list) {
  if(list->current && list->current->prev){
    list->current=list->current->prev;
    return (void *)list->current->data;
  }
    return NULL;
}

void pushFront(List * list, const void * data) {
  Node *n = createNode(data);
 if(list->head==NULL){
    list->head=n;
    list->tail=n;
 }else{
   n->next=list->head;
   list->head=n;
 }
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
 Node *n= createNode(data);

     n->prev=list->current;
     if(list->current==list->tail){
     list->current->next=n;
     list->tail=n;
     }else{
       n->next=list->current->next;
       list->current->next->prev=n;
       list->current->next=n;
     }
     
  }




void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
const void *valor=list->current->data;
  //si el current es head
  if(list->current==list->head){
    list->current=list->head->next;
    list->head=list->head->next;
    free(list->head->prev);
    list->head->prev=NULL;
    return (void *)valor;
}
  //si el current es tail
  if(list->current==list->tail){
    list->tail=list->tail->prev;
    free(list->head->next);
    list->tail->next=NULL;
    list->current=list->head->next;
    return (void *)valor;
  }
  //si el list current se encuentra entre dos nodos 
  if(list->current!=list->head && list->current!=list->tail){
      printf("por aca paso rana");
  }
return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}