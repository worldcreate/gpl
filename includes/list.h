#ifndef _LIST_H_
#define _LIST_H_

#include <stddef.h>

int lib_hello();

typedef struct list_head {
	struct list_head* prev;
	struct list_head* next;
} list_head;

#define list_entry(ptr, type, member) ({ \
	void *__ptr = (void*) ptr;             \
	(type*)(__ptr - offsetof(type, member));        \
})

static inline void list_init(list_head* list) {
	list->next = NULL;
	list->prev = NULL;
}

static inline void list_push(list_head* head, list_head* list) {
	list_head* node = head;

	for (; node->next != NULL; node = node->next);
	node->next = list;
	list->prev = node;
	list->next = NULL;
}

#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != NULL; pos = (pos)->next)

#endif
