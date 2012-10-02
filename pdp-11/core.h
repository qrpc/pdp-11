//
//  core.h
//  pdp-11
//
//  Created by Robert Altenburg on 9/16/12.
//  Copyright (c) 2012 Robert Altenburg. All rights reserved.
//

// implementation for a pdp-11/40

#ifndef pdp_11_core_h
#define pdp_11_core_h

#include "dispatch.h"


char core[1 << 16];
short reg[8];

#define PSW     core[0177776]

#define PSW_C   001
#define PSW_V   002
#define PSW_Z   004
#define PSW_N   010
#define PSW_T   020

#define SP reg[6]
#define PC reg[7]


// memory access functions
short read_word (char addr);
char read_byte (char addr);

void write_word (char dest_addr, short source_value);
void write_byte(char dest_addr, char source_value);

// emulator helper functions
void dump_core (short orig, short range);
void load_core (short program[], short length, short start);
void process_loop (void);

//program status worf functions
void psw_set (short values);
void psw_reset (short values);
void psw_on_word (short word);
void psw_on_byte (short byte);
char psw_test (short values);


void push (short word);
short pop (void);

// functions used only inside core

short get_operand (char addr);
short get_address (char addr);

char core_read_byte(short offset);
short core_read_word(short offset);

void core_write_byte(char byte, short offset);
void core_write_word (short word, short offset);

#endif
