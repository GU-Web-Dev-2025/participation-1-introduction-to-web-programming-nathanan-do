#include "LMC.h"

struct LMC lmc;

// Add a global flag to end program when needed
static int shouldHalt = 0; // 0 = continue, 1 = halt

void initializeLMC(int debugModeToggle){

    lmc.opcodes[0] = "HLT";
    lmc.opcodes[1] = "ADD";
    lmc.opcodes[2] = "SUB";
    lmc.opcodes[3] = "STA";
    lmc.opcodes[4] = "UNUSED";
    lmc.opcodes[5] = "LDA";
    lmc.opcodes[6] = "BRA";
    lmc.opcodes[7] = "BRZ";
    lmc.opcodes[8] = "BRP";
    lmc.opcodes[9] = "INP/OUT";

    lmc.zeroFlag = 1;
    lmc.negativeFlag = 0;
    lmc.accumulator = 0;

    lmc.debugMode = debugModeToggle;
    
}

void loadProgram(const char * filename){

    FILE * file = fopen(filename, "r");

    if(file == NULL){
        printf("Error opening file [%s]! Program terminating...\n", filename);
        exit(0);
    }else{
        printf("Successfully opened file [%s].\n", filename);
    }

    // a string that can hold 5 characters
    // captures null terminator '\0' and newline char
    char line[5];
    int mailboxCounter = 0;
    while(fgets(line, 5, file) != NULL){
        line[3] = '\0'; //end string with a null terminator
        lmc.mailboxes[mailboxCounter++] = atoi(line);
    }

    fclose(file);

}

void runProgram(){ 

    if(lmc.debugMode == 1){
        printLMC();
        printMailboxes();
    }

    while(1){
        fetch();
        decode();
        execute();

        // Check the global flag to determine if the program should halt
        if (shouldHalt) {
            break; // Exit the loop if the program should halt
        }

        if(lmc.debugMode == 1){
            printf("\nPress enter to continue...\n");
            getchar();  // pauses the program until the user presses <enter>
        }
    }
}

void fetch(){ 

    if(lmc.debugMode == 1){
        printf("fetching instruction: %2d\n", lmc.instructionCounter);
    }
    
    //get next instruction from mailbox at instruction counter
    lmc.currentInstruction = lmc.mailboxes[lmc.instructionCounter];
    
    //increment instruction counter
    lmc.instructionCounter++;

}

void decode(){ 
    //convert the three-digit instruction into a task to do
    if(lmc.currentInstruction == 0){
        lmc.opcode = 0;
        lmc.operand = 0;
    }
    if(lmc.currentInstruction > 99 && lmc.currentInstruction < 200){
        lmc.currentInstruction = lmc.currentInstruction - 100;
        lmc.opcode = 1;
        lmc.operand = lmc.currentInstruction;
    }
    if(lmc.currentInstruction > 199 && lmc.currentInstruction < 300){
        lmc.currentInstruction = lmc.currentInstruction - 200;
        lmc.opcode = 2;
        lmc.operand = lmc.currentInstruction;
    }
    if(lmc.currentInstruction > 299 && lmc.currentInstruction < 400){
        lmc.currentInstruction = lmc.currentInstruction - 300;
        lmc.opcode = 3;
        lmc.operand = lmc.currentInstruction;
    }
    if(lmc.currentInstruction > 399 && lmc.currentInstruction < 500){
        lmc.currentInstruction = lmc.currentInstruction - 400;
        lmc.opcode = 4;
        lmc.operand = lmc.currentInstruction;
    }
    if(lmc.currentInstruction > 499 && lmc.currentInstruction < 600){
        lmc.currentInstruction = lmc.currentInstruction - 500;
        lmc.opcode = 5;
        lmc.operand = lmc.currentInstruction;
    }
    if(lmc.currentInstruction > 599 && lmc.currentInstruction < 700){
        lmc.currentInstruction = lmc.currentInstruction - 600;
        lmc.opcode = 6;
        lmc.operand = lmc.currentInstruction;
    }
    if(lmc.currentInstruction > 699 && lmc.currentInstruction < 800){
        lmc.currentInstruction = lmc.currentInstruction - 700;
        lmc.opcode = 7;
        lmc.operand = lmc.currentInstruction;
    }
    if(lmc.currentInstruction > 799 && lmc.currentInstruction < 900){
        lmc.currentInstruction = lmc.currentInstruction - 800;
        lmc.opcode = 8;
        lmc.operand = lmc.currentInstruction;
    }
    if(lmc.currentInstruction > 899 && lmc.currentInstruction <1000){
        lmc.currentInstruction = lmc.currentInstruction - 900;
        lmc.opcode = 9;
        lmc.operand = lmc.currentInstruction;
    }
    
    //get opcode and operand
    

    //debug print out
    if(lmc.debugMode == 1){
        printf("opcode: %d (%s), operand: %2d\n", lmc.opcode, lmc.opcodes[lmc.opcode], lmc.operand);
    }
}

void execute(){ 

    //perform the task of the the opcode and operand
    switch(lmc.opcode){
        case 0:// HLT - halt
            printf("Exiting program...\n");
            shouldHalt = 1; // Set the global flag to indicate the program should end
            break;
        case 1: // adds mailbox value to accumulator
           lmc.accumulator = lmc.accumulator + lmc.mailboxes[lmc.operand];
            break;
        case 2: // subtracts accumulator by mailbox
           lmc.accumulator = lmc.accumulator - lmc.mailboxes[lmc.operand];
            break;
        case 3: // value in accumulator is stored to mailbox
            lmc.mailboxes[lmc.operand] = lmc.accumulator;
            break;
        case 5: // LDA - load value in mailbox to accumulator
            lmc.accumulator = lmc.mailboxes[lmc.operand];
            break;
        case 6: // Sets instruction counter to operand
            lmc.instructionCounter = lmc.operand;
            break;
        case 7: // Set instruction to operand if ZeroFlag is set
            if(lmc.zeroFlag == 1){
                lmc.instructionCounter = lmc.operand;
            }
            break;
        case 8: // set instruction to operand is negativeFlag is set
            if(lmc.negativeFlag == 0){
                lmc.instructionCounter = lmc.operand;
            }
            break;
        case 9:
            // IO case already completed
            if(lmc.operand == 1){
                printf("Enter input and press enter: ");
                scanf("%d", &lmc.accumulator);
                getchar(); // remove the newline char
            }else if(lmc.operand == 2){
                printf("Output: %3d\n", lmc.accumulator);
            }
            break;
    };

    /*************************/
    //set flags here
    /*************************/

    lmc.zeroFlag = (lmc.accumulator == 0) ? 1 : 0;
    lmc.negativeFlag = (lmc.accumulator < 0) ? 1 : 0;

    // lmc.obj = (lmc.obj(comparison case)) ? (if true) : (if false)


    if(lmc.debugMode == 1){
        
        printMailboxes();
        printLMC();
    }
    
}

void printLMC(){ 

    printf("+------------- LMC -------------+\n");
    printf("| Accumulator: [%3d]            |\n", lmc.accumulator);
    printf("| Instruction Counter: [%2d]     |\n", lmc.instructionCounter);
    printf("| Flags:                        |\n");
    printf("|   Negative Flag: %d            |\n", lmc.negativeFlag);
    printf("|   Zero Flag %d                 |\n", lmc.zeroFlag);
    printf("+-------------------------------+\n");
}

void printMailboxes(){
    printf("\nMemory Contents [mailbox:data]");
    for(int i = 0; i < 100; i++){
        if(i % 10 == 0){
            printf("\n");
        }
        printf("[%2d:%3d] ", i, lmc.mailboxes[i]);
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

