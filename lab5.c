#include <stdio.h> 
#include <stdlib.h>
#define N 10

typedef enum {false = 0,true = 1} bool;
typedef bool (*FUNC) (bool);

typedef struct gate{
    bool in;
    bool out;
    FUNC  behavior;
    struct gate *next;
} GATE;

bool gate_func_not(bool);
GATE * create_gate();
void create_linked_list(GATE *);
void calculate_circuit_output(GATE *);

int main(void){
    GATE *head=create_gate();
    head->in=1;
    create_linked_list(head);
    
    calculate_circuit_output(head);
    return 0;
}


bool gate_func_not(bool in) {
    return !in;
}

void create_linked_list(GATE *head){
    GATE  *tmp=head;
    for(int i=1;i<N;i++){
        tmp->next=create_gate();
        tmp=tmp->next;
    }
}

GATE * create_gate(){
        //ΣΥΜΠΛΗΡΩΣΤΕ ΤΟΝ ΚΩΔΙΚΑ ΤΗΣ ΣΥΝΑΡΤΗΣΗΣ
        GATE *gatePTR;
        gatePTR = malloc(sizeof (GATE));
        gatePTR->in = true;
        gatePTR->out = true;
        gatePTR->next = NULL;
        gatePTR->behavior = gate_func_not;

    return gatePTR;
}

void calculate_circuit_output(GATE *head){
        //ΣΥΜΠΛΗΡΩΣΤΕ ΤΟΝ ΚΩΔΙΚΑ ΤΗΣ ΣΥΝΑΡΤΗΣΗΣ
        GATE *temp = head;
        int i=1;
        while(temp->next != NULL){
            temp->out = temp->behavior(temp->in);
            printf("GATE No%d           IN:%d   OUT:%d\n", i, temp->in, temp->out);
            temp->next->in = temp->out;
            temp = temp->next;
            i++;
        }
        temp->out = gate_func_not(temp->in);
        printf("GATE No%d           IN:%d   OUT:%d\n", i, temp->in, temp->out);

    return;
}
