#include <stdio.h>
#include <stdlib.h>

typedef struct Packet
{
    int arrival;
    int processing;
} Packet;

typedef struct Node
{
    int finish_time;
    struct Node* next;
} Node;;


typedef struct Buffer
{
    int size;
    Node* head;
    Node* tail;
    int current_size;
}Buffer;

void push(int time);
void remove_finished_packets(int index);
void process_packet(Packet packet);
Buffer buffer;

int main() {
    int s, n;
    scanf("%d%d", &s,&n);
    buffer.size = s;
    buffer.current_size = 0;
    buffer.head = NULL;
    buffer.tail = NULL;
    Packet packet;
    for (int i = 0;  i < n; i++) {
        scanf("%d", &packet.arrival);
        scanf("%d", &packet.processing);
        process_packet(packet);
    }
    return 0;
}

void process_packet(Packet packet) {

    remove_finished_packets(packet.arrival);

    if (buffer.current_size == 0) {

        printf("%d\n", packet.arrival);
        push(packet.arrival + packet.processing);

    } else if (buffer.current_size < buffer.size) {

        int start_time = buffer.tail->finish_time;

        printf("%d\n", start_time);

        push(start_time + packet.processing);

    } else {

        printf("-1\n");
    }
}

void push(int time) {
    Node* node = malloc(sizeof(Node));
    node->finish_time = time;
    node->next = NULL;
    if(buffer.head == NULL)  {
        buffer.head = node;
        buffer.tail = node;
    }else {
        (buffer.tail)->next = node;
        buffer.tail = node;
    }
    buffer.current_size++;
}

void remove_finished_packets(int index) {
    Node* current = buffer.head;
    Node* tmp;
    while(current != NULL && current->finish_time <= index) {
        tmp = current;
        current = current->next;
        free(tmp);
        buffer.current_size--;
    }
    buffer.head = current;
    if (buffer.current_size == 0) {
        buffer.tail = NULL;
    }
}