#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s", message);
	return -1;
}

int is_full(QueueType* q) {
	return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
void init_queue(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.\n");
	}
	else {
		/*q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;*/
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element dequeue(QueueType* q) {
	int item;
	if (is_empty(q)) {
		error("큐가 비어있습니다.\n");
	}
	else {
		/*q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		printf("큐에서 삭제된 원소 : %d", q->data[q->front]);
		return (q->data[q->front]);*/
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

void print_queue(QueueType* q) {
	/*int i;
	for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 2) % MAX_QUEUE_SIZE) {
		printf("%d, ", q->data[i]);
	}
	printf("%d", q->data[i]);*/
	int i = (q->front + 1) % MAX_QUEUE_SIZE;
	while (i != (q->rear + 1) % MAX_QUEUE_SIZE) {
		printf("%d ", q->data[i]);
		i = (i + 1) % MAX_QUEUE_SIZE;
	}
}

int main() {
	QueueType queue;
	//element e;

	init_queue(&queue);

	int choice, num;
	char input[100];
	do{
		printf("1. 큐에 원소를 삽입\n");
		printf("2. 큐에서 원소를 삭제\n");
		printf("3. 큐의 원소를 출력\n");
		printf("4. 종료\n");
		printf("메뉴를 선택하세요: ");
		scanf_s("%d", &choice);
		printf("----------------\n");

		while (getchar() != '\n');

		switch (choice) {
		case 1:
			printf("큐에 삽입할 숫자를 입력하세요 : ");
			fgets(input, sizeof(input), stdin);
			num = strtol(input, NULL, 10);
			enqueue(&queue, num);
			printf("----------------\n");
			break;
		case 2:
			printf("큐에서 삭제된 원소 : %d\n", dequeue(&queue));
			printf("----------------\n");
			break;
		case 3:
			printf("현재 큐의 상태 : ");
			print_queue(&queue);
			printf("\n");
			printf("----------------\n");
			break;
		case 4:
			exit(1);
		default:
			printf("잘못된 선택입니다.\n");
		}
	} while (choice != 4);

	return 0;
	//enqueue(&queue, 1); print_queue(&queue);
	//enqueue(&queue, 2); print_queue(&queue);
	//enqueue(&queue, 3); print_queue(&queue);
	//enqueue(&queue, 4); print_queue(&queue);
	//enqueue(&queue, 5); print_queue(&queue);
	//enqueue(&queue, 6); print_queue(&queue);
	//e = dequeue(&queue); printf("<%2d>", e); print_queue(&queue);
	//e = dequeue(&queue); printf("<%2d>", e); print_queue(&queue);
	//e = dequeue(&queue); printf("<%2d>", e); print_queue(&queue);

}