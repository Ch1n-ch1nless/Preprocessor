#ifndef SPU_STRUCT_H_INCLUDED
#define SPU_STRUCT_H_INCLUDED

#include "../../Stack/source/stack.h"

#include "../../Common_files/global_reg_consts_and_structs.h"
#include "../../Common_files/global_lbl_consts_and_structs.h"

#define PRINT_PROC_ERR(error, clm) error = ProcessorVerify(clm);                                \
                                   ProcessorError(clm, error, __FILE__, __FUNCTION__, __LINE__);

#define PRINT_PROCESSOR(clm) \
ProcessorDump((clm), #clm, __FILE__, __FUNCTION__, __LINE__);

struct Processor
{
    Stack   stk;
    elem_t* reg_array;
    int*    cmd_array;
    size_t  buf_size;
};

error_t ProcessorCtor(Processor* clm);
error_t ProcessorDtor(Processor* clm);

error_t ProcessorStkPush(Processor* clm, elem_t new_value);
error_t ProcessorStkPop(Processor* clm, elem_t* ret_value);

error_t ProcessorRegPush(Processor* clm, size_t index);
error_t ProcessorRegPop(Processor* clm, size_t index);

error_t ProcessorVerify(Processor* clm);
void    ProcessorError(Processor* clm, error_t error, const char* file, const char* function,
                                                                        const int line);

void    ProcessorDump(Processor* spu, const char* spu_name, const char* file,
                               const char* function, const int   line);

#endif // SPU_STRUCT_H_INCLUDED
