#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)
{
  list_ptr l = malloc(sizeof(struct list_node));
  l->data = NULL;
  l->next = NULL;
  return l;
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */
list_ptr list_add(sprite_t sprite, list_ptr list)
{
  if ((list == NULL) || (list->data == NULL)) {
    list_ptr l = list_new();
    l->data = sprite;
    return l;
  }
  list_ptr l_tmp = list;
  while (l_tmp->next != NULL) l_tmp = l_tmp->next;
  list_ptr nl = list_new();
  nl->data = sprite;
  l_tmp->next = nl;
  return list;
}

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
  return l == NULL || l->data == NULL;
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
  if (l == NULL || l->next == NULL) return NULL;
  return l->next;
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{
  if (l == NULL) return NULL;
  return l->data;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
  if (l == NULL) return NULL;
  while ((*l)->next != NULL) l = &(*l)->next;

  list_ptr last = *l;
  sprite_t s = last->data;
  
  *l = NULL;
  free(last);
  return s;
}

/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
  if ((l == NULL) || (elt == NULL)) return;
  list_ptr previous = *l;
  while ((*l != elt) || (l == NULL)) {
    previous = *l;
    l = &(*l)->next;
  }
  if (l != NULL) {
    previous->next = (*l)->next;
    free(*l);
  }
}

/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
  if (l == NULL) return;
  if (l->next != NULL) {
    list_free(l->next);
  }
  if (l->data != NULL) sprite_free(l->data);
  free(l);
}

/* Return the length of a list
 * */
int list_length(list_ptr l)
{
  if (l == NULL) return 0;
  int cpt = 1;
  while((l = l->next) != NULL) cpt++;
  return cpt;
}

/* Reverse the order of a list
 * */
void list_reverse(list_ptr * l)
{
  if (l == NULL) return;
  list_ptr hold_l = *l;
  while (hold_l->next != NULL){
    list_ptr new_l = hold_l->next;
    hold_l->next = new_l->next;
    // Ajoute à la tête le terme qui suit le premier terme de la liste non reverse
    new_l->next = *l;
    *l = new_l;
  }
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
  if (list == NULL) return NULL;
  list_ptr l_new = list_new();
  list_ptr l_new_head = l_new;
  do {
    l_new->data = list->data;
    l_new->next = list_new();
    l_new = l_new->next;
  } while((list = list->next) != NULL);
  free(l_new->next);
  l_new->next = NULL;
  return l_new_head;
}
