Final grade: 110/100

## Corewar
---

## What is Corewar?

Core War was inspired by a malicious virus written in the 80’s. In response to a self-replicating virus, Reaper was invented . It was a virus designed to spread and eliminate the malware.

Following this A. K. Dewdney was inspired to create Corewar.

The game was to design two competing viruses to overtake a computer. A successful champion can both protect itself and smother its' opponet.  
This is all happening on a virtual computer within your computer designed to immitate ram, and create a safe game arena. 

This is what is what two viruses (champions) poised for battle looks like. The white is empty memory, and the purple is instructions waiting to be caried out. 

![Input](./imgs/corewar.png)
## Description

### The Project

This project was developed by @adietric, @flafonso, @yodana, and myself. There were two principle parts; the asm and the virtual machine. 
The asm's role is to take a champion written in assembly language, parse it in detail, and compile it into bytecode. 
The virtual machine then loads the champions into the arena, and allows them to fight until all champions are dead, and
then declares the last champion alive the winner. Further details can be found in the attached "Corewar" pdf. 
My role in this project was to create the architecture of the VM, and I also wrote all the operations (actions) the champions
can make. 

### Usage:

Run the make command to create the executables ./asm and ./corewar. Use ./asm with a .s file to create a .cor file. 
Use the ./corewar executable with between 1 and 4 .cor files and see the battle unfold! There is a folder named champions filled with pre-compiled .cor. Within this folder is a further folder called "examples" if you would like to try the asm with some .s files. 

#### Flags:
* The -n flag allows you to give a custom id to a champion of your choice. 
* The -v flag allows verbose mode. You can see the lives/deaths/operations/cycles of the battle in course. -v 4 will give you the clearest idea of what is happening. 
* The -dump flag, followed by an integer will dump the arena in hex form onto the stdout when the cycles correspond to the given integer. The program then exits. 
