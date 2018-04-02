#include<stdio.h>
#include<malloc.h>


#define MAX 100

struct NODE {
	int data;
	NODE *link;
};

NODE *front = NULL;
NODE *rear = NULL;
int count = 0;

bool ADD(int data) {
	if (count >= MAX) {
		printf("큐 오버플로\n");
		return false;
	}

	NODE *pNODE = (NODE *)malloc(sizeof(NODE));

	if (pNODE == NULL) {
		printf("메모리 부족\n");
		return false;
	}

	pNODE->data = data;
	pNODE->link = NULL;

	if (count == 0) {
		rear = pNODE;
		front = pNODE;
	}
	else {
		rear->link = pNODE;
		rear = pNODE;
	}

	count++;

	printf("ADD : %d\n", data);

	return true;
}

bool DELETE(int *pdata) {
	if (count == 0) {
		printf("큐 언더플로\n");
		return false;
	}

	*pdata = front->data;

	NODE *pDelNODE = front;
	front = front->link;
	free(pDelNODE);

	count--;
	if (count == 0) {
		front = NULL;
		rear = NULL;
	}

	printf("DELETE : %d\n", *pdata);
	return true;
}

void PrintQ() {
	printf("큐 : ");

	NODE *pNODE = front;
	while (pNODE != NULL) {
		printf("%d ", pNODE->data);
		pNODE = pNODE->link;
	}
	printf("\n");
}

int main() {
	int data = 0;

	ADD(10);
	ADD(20);
	ADD(30);
	ADD(40);

	PrintQ();

	DELETE(&data);
	DELETE(&data);
	DELETE(&data);
	DELETE(&data);
	DELETE(&data);

	PrintQ();

	return 0;
}

