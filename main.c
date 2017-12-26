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
	list_push(&head, &t.list);
	list_push(&head, &t2.list);
	test* p = list_entry(head.next->next, test, list);
	printf("%d\n", p->no);

	list_head* node;
	list_for_each(node, &head) {
		test* t = list_entry(node, test, list);
		printf("%d\n", t->no);
	}

}
