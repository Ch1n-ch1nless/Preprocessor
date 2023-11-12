#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED

#include "signatures.h"


const int BITMASK_OPCODE = 31;
const int BITMASK_SGNT   = 32 + 64 + 128 + 256;

#define DEF_CMD(name, cmd, ...) CMD_##name = cmd,

#define DEF_JMP_CMD(name, cmd, ...) CMD_##name = cmd,

enum Cmd : int
{
    #include "../DSL/commands.dsl"
    END_CMD
};

#undef DEF_CMD

#undef DEF_JMP_CMD

const size_t NUMBER_OF_COMMANDS = END_CMD;

struct Translation
{
    const char*  asm_cmd;
    size_t       cmd_len;
    unsigned int type_of_args;
    size_t       num_of_args;
    int          byte_cmd;
};

#define DEF_CMD(name, cmd, signature, num_of_args, ...)  {#name, strlen(#name), signature, num_of_args, cmd},

#define DEF_JMP_CMD(name, cmd, num_of_args, ...)         {#name, strlen(#name), LBL, num_of_args, cmd},

const Translation COMMAND_SET[] = {
                                    #include "../DSL/commands.dsl"
                                 };

#undef DEF_CMD

#undef DEF_JMP_CMD

#endif // COMMANDS_H_INCLUDED
