/*******************************************************************
 linekedList operations:
 1. create
 2. print
 3. getlength
 4. reverse
 5. reverseprint
 6. getkthnode
 7. has circle
 8. the cirle begin node in a circle
 9. merge two sort lists
 8. two lists Intersection

  related url: http://blog.csdn.net/luckyxiaoqiang/article/details/7393134

********************************************************************/
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct node {
	int val;
	node *next;
};

node * createLinkedList(int n) {
	node * linkedlist = new node();
	linkedlist->val = 0;
	linkedlist->next = NULL;

	int tmp;
	node * p = linkedlist;
	for (int i = 0; i < n; i++) {
		node * linktmp = new node();
		cin >> linktmp->val;
		linktmp->next = NULL;
		p->next = linktmp;
		p = p->next;
	}
	return linkedlist->next;
}

void print(node * phead) {
	cout << "print the list:" << endl;
	node *p = phead;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return;
}

int getLength(node * linkedlist) {
	int len = 0;
	node * p = linkedlist;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	cout << "The total length is:" << len << endl;
	return len;
}

node * reverse(node * linkedlist) {
	//        2-->3-->1-->4
	// null<--2<--3   1<--4
	node * pcurrent = linkedlist;
	node * pre = NULL;

	while (pcurrent != NULL) {
		node * tmp = pcurrent->next;
		pcurrent->next = pre;
		pre = pcurrent;
		pcurrent = tmp;
	}

	return pre;
}

int getKthNode(node * linkedlist, int k) {
	int len = getLength(linkedlist);
	if (k < 0 || k >= len)
		return 0;
	node * fast = linkedlist;
	node * slow = linkedlist;

	for (int i = 0; i < k; i++) {
		fast = fast->next;
	}

	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow->val;

}

void Rprint(node * linkedlist) {
	if (linkedlist == NULL) {
		cout << endl;
		return;
	}
	Rprint(linkedlist->next);
	cout << linkedlist->val << " ";
}

/*void Rprint(node * linkedlist) {
	stack<node*> st;
	node * p = linkedlist;
	while (p) {
		st.push(p);
		p = p->next;
	}
	while (!st.empty()) {
		node* tmp = st.top();
		cout << tmp->val << " ";
		st.pop();
	}
	cout << endl;

	return;
} */


node * merge(node * a, node * b) {
	node * head = new node();
	head->next = NULL;
	head->val = 0;

	node * p = head;

	node * pa = a;
	node * pb = b;
	while (pa != NULL || pb != NULL) {
		if (pa == NULL) {
			p->next = pb;
			break;
		}
		else if (pb == NULL) {
			p->next = pa;
			break;
		}
		else {
			if (pa->val <= pb->val) {
				p->next = pa;
				pa = pa->next;
			}
			else {
				p->next = pb;
				pb = pb->next;
			}
			p = p->next;
		}

	}
	return head->next;
}

bool hasCircle(node * head) {
	node * fast = head;
	node * slow = head;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {
			return true;
		}
	}

	return false;
}

node* findLoopPoint(node* head) {
	if (head == NULL || head->next == NULL) {
		return NULL;
	}

	node * fast = head;
	node * slow = head;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {
			break;
		}
	}

	if (fast != slow) return NULL;

	fast = head;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}

bool isInsert(node * a, node *b) {
	if (a == NULL || b == NULL)
		return false;
	int lena = getLength(a);
	int lenb = getLength(b);

	node * pa = a;
	node * pb = b;
	if (lena >= lenb) {
		for (int i = 0; i < (lena - lenb); i++) {
			pa = pa->next;
		}
	}
	else {
		for (int i = 0; i < (lena - lenb); i++) {
			pb = pb->next;
		}
	}

	while (pa && pb && pa != pb) {
		pa = pa->next;
		pb = pb->next;
	}

	return pa;

}

// sort

int main() {
	int n,m;

	cout << "please input the number of linkedlist:" << endl;
	cin >> n;

	node * LS = createLinkedList(n);  // create

	//print(LS);  // print

	//int len = getLength(LS); // length

	//node * reverseList = reverse(LS); // reverse

	//LS = reverse(reverseList);

	/*int k;
	cin >> k;
	int kth = getKthNode(LS, k);
	cout << kth << endl; */

	//Rprint(LS); // iterator && uniterator

	//node * sortList = Sort(LS);
	//print(sortList);

	cin >> m;
	node * LS2 = createLinkedList(m);

	node * mergelist = merge(LS, LS2);

	print(mergelist);

	//system("pause");
	return 0;
}
