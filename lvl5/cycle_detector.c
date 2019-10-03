// Assignment name  : cycle_detector
// Expected files   : cycle_detector.c
// Allowed functions: malloc, free
// --------------------------------------------------------------------------------
//
// Create a function named cycle_detector that takes a const t_list *list
// as argument, and check if the given linked list contains no cycles.
//
// A cycle is defined when you go at least twice through the same link, when you
// travel inside a linked list.
//
// This function should returnw 1 if it detects a cycle inside the given linked
// list, otherwise it returns 0.
//
// This function should be prototyped like this:
//
//     int        cycle_detector(const t_list *list)
//
// The type t_list is:
//
//     typedef struct     s_list
//     {
//         int            data;
//         struct s_list  *next;
//     }                  t_list;
//
// This type will be included in a header named "list.h". You don't have to turn-in
// your "list.h", we will use ours during the evaluation.

#include "list.h"

int        cycle_detector(const t_list *list)
{
	const t_list	*slow;
	const t_list	*fast;

	slow = list;
	fast = list;
	if (!list)
		return (0);
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}
