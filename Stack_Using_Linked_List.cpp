#include<bits/stdc++.h>
using namespace std;
struct node {
	int val;
	struct node *next;
};


class Stack {
public:
	struct node *top;
	Stack() {
		top = NULL;
	}

	void push(int val) {
		struct node *temp = (node *)malloc(sizeof(node));
		temp->val = val;
		temp->next = NULL;
		if(top == NULL) {
			top = temp;
		} else {
			temp->next = top;
			top = temp;
		}
	}


	void pop() {
		if(top == NULL)
			cout << "The stack is already empty.\n";
		else {
			struct node *temp = top;
			top = top->next;
			free(temp);
		}
	}

	int getTop() {
		if(top == NULL) {
			cout << "The stack is empty.\n";
		} else {
			return top->val;
		}
		return 0;
	}

	bool isEmpty() {
		return top == NULL;
	}

};
int main() {
	Stack s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	cout << s1.getTop() << "\n";
	s1.pop();
	s1.pop();
	cout << s1.getTop() << "\n";
	return 0;
}
