# Compiler & Microprocessor Project

> C compiler (Lex/Yacc) emitting assembly for a RISC datapath written in VHDL, verified in simulation.

## About

A full-stack "from source code to silicon" project built solo for the Computer Engineering course of the 4th year Informatique et Réseaux program at INSA Toulouse. One half is a compiler, written in C with Flex and Bison, that translates a subset of C (variables, constants, arithmetic, comparisons, `if`/`elsif`/`else`, `while`, pointers, `printf`) into assembly and machine code for a custom memory-addressed RISC instruction set. The other half is the target microprocessor itself, designed in VHDL as a Vivado project: its datapath building blocks (program counter, dual-read-port register file, ALU) are each implemented and verified in simulation with dedicated testbenches. Code generation and the hardware were designed together — the compiler manages its own symbol table and a temporary-value stack laid out in the processor's data memory, resolves jump labels to instruction addresses, and emits both a readable assembly listing and the binary encoding the datapath decodes.

## Tech stack

- **Compiler:** C, Flex (lexer), Bison/Yacc (parser), GNU Make
- **Hardware:** VHDL, AMD/Xilinx Vivado (project + XSim behavioral simulation)

## Build & run

### Compiler

Requires `flex`, `bison`, and `gcc`.

```sh
cd Compiler
make compile                      # flex + bison + gcc -> ./compiler
./compiler testfiles/test_while   # or read from stdin by omitting the file
```

Compilation produces two files in the working directory:

- `output_assembly.txt` — human-readable assembly (`ADD`, `MUL`, `SOU`, `DIV`, `COP`, `AFC`, `JMP`, `JMF`, `INF`, `SUP`, `EQU`, `PRI`)
- `output_binary.txt` — the same program with opcodes encoded numerically

Sample programs live in `Compiler/testfiles/`.

### Microprocessor

Open `MicroProcessor/ProjetSystemeInformatique.xpr` in Vivado. Each component has a testbench under `sim_1` (`ALUTb`, `Banc_RegistreTb`, `Compteur_8bitsTb`, `PerceptronTb`) that can be run as a behavioral simulation.

## Project structure

```
Compiler/                  C-to-assembly compiler (Flex/Bison)
├── lexer.l                Tokenizer for the C subset
├── parser.y               Grammar, three-address code generation, label
│                          resolution, and assembly/binary emitters
├── memory/                Symbol table + temporary-address stack
│                          (temporaries allocated from address 512)
├── testfiles/             Example programs (if/else, while, pointers)
└── Makefile               Build targets (make compile)

MicroProcessor/            VHDL processor (Vivado project)
└── ...srcs/
    ├── sources_1/new/     Datapath components:
    │   ├── Compteur_8bits.vhd   Program counter (load/up/down/reset)
    │   ├── Banc_Registre.vhd    16x8-bit register file, 2 read ports
    │   │                        with write-through, 1 write port
    │   ├── ALU.vhd              Add/sub/mul + logic ops, carry &
    │   │                        negative flags
    │   └── Perceptron.vhd       Fixed-point perceptron neuron
    │                            (iterative MAC + activation)
    └── sim_1/new/         One testbench per component

CourseMaterial/            Original project brief (sujet.pdf)
```
