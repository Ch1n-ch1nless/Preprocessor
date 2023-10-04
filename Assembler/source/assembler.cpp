#include "assembler.h"

ERRORS AssemblerTheInstruction(const char* outputfile, Text* guide)
{
    ERRORS error = NO_ERR;

    FILE* output = fopen(outputfile, "w");
    if (output == nullptr)
    {
        error = OPEN_FILE_ERR;
        return error;
    }

    for (size_t i = 0; i < guide->n_lines; i++)
    {
        if (strncmp(guide->line_array[i].str_ptr, cmd_array[0].asm_cmd, 4) == 0)
        {
            fprintf(output, "%u%s\n", cmd_array[0].mode, guide->line_array[i].str_ptr + 4);
        }
        else
        {
            for (size_t j = 1; j < COUNT_OF_COMMANDS; j++)
            {
                if (strncmp(guide->line_array[i].str_ptr, cmd_array[j].asm_cmd, strlen(cmd_array[j].asm_cmd)) == 0)
                {
                    fprintf(output, "%u\n", cmd_array[j].mode);
                }
            }
        }
    }

    fclose(output);

    return error;
}
