#include <stdio.h> 
#include <stdlib.h>
#define N 10

typedef enum {false = 0,true = 1} bool;
typedef bool (*FUNC) (bool);

typedef struct  gate{
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
    GATE  *head=create_gate();
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
    
    return;
}

void calculate_circuit_output(GATE *head){
        //ΣΥΜΠΛΗΡΩΣΤΕ ΤΟΝ ΚΩΔΙΚΑ ΤΗΣ ΣΥΝΑΡΤΗΣΗΣ
    return;
}
