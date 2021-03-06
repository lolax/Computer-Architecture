#ifndef _CPU_H_
#define _CPU_H_

// Holds all information about the CPU
struct cpu {
  unsigned int PC;
  unsigned char FL;
  unsigned char reg[8];
  unsigned char ram[256];

  // program counter
  // flag
  // registers (array)
  // ram (array)
};

// ALU operations
enum alu_op {
  ALU_ADD,
  ALU_SUB,
	ALU_MUL,
  ALU_DIV,
  ALU_MOD,
  ALU_INC,
  ALU_DEC,
  ALU_CMP,
  ALU_AND,
  ALU_NOT,
  ALU_OR,
  ALU_XOR,
  ALU_SHL,
  ALU_SHR,
};

// Instructions

// These use binary literals. If these aren't available with your compiler, hex
// literals should be used.

#define LDI  0b10000010
#define HLT  0b00000001
#define PRN  0b01000111
#define ADD  0b10100000
#define SUB  0b10100001
#define MUL  0b10100010
#define DIV  0b10100011
#define MOD  0b10100100
#define PUSH 0b01000101
#define POP  0b01000110
#define CALL 0b01010000
#define RET  0b00010001
#define CMP  0b10100111
#define JMP  0b01010100
#define JEQ  0b01010101
#define JNE  0b01010110
#define JGT  0b01010111
#define JLT  0b01011000
// TODO: more instructions here. These can be used in cpu_run().

// Function declarations

extern void cpu_load(struct cpu *cpu, char *file);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);

#endif
