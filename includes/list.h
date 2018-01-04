#ifndef _LIST_H_
#define _LIST_H_

#include <stddef.h>

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

static inline list_head* list_remove_at(list_head* head, int pos) {
	list_head* node = head;
	for (int i = 0; i < pos + 1; node = node->next, i++);

	if (node->next != NULL) {
		node->next->prev = node->prev;
	}
	node->prev->next = node->next;

	return node;
}

static inline int list_size(list_head* head) {
	list_head* node = head;
	int i = 0;
	for (;node->next != NULL; node = node->next, i++);
	return i;
}
