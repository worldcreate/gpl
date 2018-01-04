#include <stdio.h>

#include "includes/list.h"

typedef struct test {
	int no;
	list_head list;
} test;

int main(void) {
	list_head head;
	list_init(&head);
	test t;
	t.no = 3;
	test t2;
	t2.no = 4;
	test t3;
	t3.no = 5;
	list_push(&head, &t.list);
	list_push(&head, &t2.list);
	list_push(&head, &t3.list);

	list_head* node;
	list_for_each(node, &head) {
		test* t = list_entry(node, test, list);
		printf("%d\n", t->no);
	}

	printf("size = %d\n", list_size(&head));
	list_remove_at(&head, 2);

	list_for_each(node, &head) {
		test* t = list_entry(node, test, list);
		printf("%d\n", t->no);
	}

	printf("size = %d\n", list_size(&head));
}
