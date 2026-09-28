#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)
{
  l = malloc(sizeof(list_node));
  l->data == NULL;
  l->next == NULL;
  return l;
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */
list_ptr list_add(sprite_t sprite, list_ptr list)
{
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
  if (l == NULL) return true;
  return false;
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
  return NULL;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
  while (l->next != NULL) l = l->next;
  sprite_t s = l->data;
  free(l);
  return s;
}

/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
}

/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
  if (l->next != NULL) {
    list_free(l->next);
  }
  sprite_free(l->data);
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
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
  return NULL;
}
