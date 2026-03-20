//Marin Aske
//HW4
//Computer Architecture Montagne


#include <stdio.h>

#define MAXPROGRAMSIZE 100

// Define the instruction structure
typedef struct {
    int opCode;
    int addrOrDevice;
} Instruction;

// Define data registers and memory
int PC = 0;
int A;
Instruction IM[MAXPROGRAMSIZE];
int DM[MAXPROGRAMSIZE];

// Function to perform LOAD
void LOAD(int addr) {
    A = DM[addr];
}

// Function to perform ADD
void ADD(int addr) {
    A += DM[addr];
}

// Function to perform STORE
void STORE(int addr) {
    DM[addr] = A;
}

// Function to perform SUB
void SUB(int addr) {
    A -= DM[addr];
}

// Function to perform IN
void IN(int device) {
    printf("/* input value */\n");
    scanf("%d", &A);
}

// Function to perform OUT
void OUT(int device) {
    printf("%d\n", A);
}

// Function to perform JMP
void JMP(int addr) {
    PC = addr;
}

// Function to perform SKIPZ
void SKIPZ(int addr) {
    if (A != 0) {
        PC = addr;
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int opCode, addrOrDevice;
    int i = 0;

    // Read instructions from input file and store in Instruction Memory (IM)
    while (fscanf(file, "%d %d", &opCode, &addrOrDevice) == 2) {
        IM[i].opCode = opCode;
        IM[i].addrOrDevice = addrOrDevice;
        i++;
    }

    fclose(file);

    printf("Reading Program...\n");
    printf("Program Assembled.\n");
    printf("Run.")

    // Execute the instructions
    while (1) {
        // Fetch
        int MAR1 = PC;
        PC++;
        Instruction IR = IM[MAR1];

        // Execute
        int MAR2 = IR.addrOrDevice;

        switch (IR.opCode) {
            case 1: LOAD(MAR2); break;
            case 2: ADD(MAR2); break;
            case 3: STORE(MAR2); break;
            case 4: SUB(MAR2); break;
            case 5: IN(MAR2); break;
            case 6: OUT(MAR2); break;
            case 7: printf("Program complete.\n"); return 0;
            case 8: JMP(MAR2); break;
            case 9: SKIPZ(MAR2); break;
            default: printf("Invalid opcode: %d\n", IR.opCode); return 1;
        }

        // Print current state
        printf("\nPC = %d | A = %d | DM = [", PC, A);
        for (int j = 0; j < MAXPROGRAMSIZE; j++) {
            printf("%d%s", DM[j], (j == MAXPROGRAMSIZE - 1) ? "" : ", ");
        }
        printf("]\n");
    }

    return 0;
}