//
//  stdarg.h
//  C_Compiler
//
//  Created by 张少雄 on 12/28/16.
//  Copyright © 2016 张少雄. All rights reserved.
//

#ifndef stdarg_h
#define stdarg_h

/**
 * Refer this document for the x86-64 ABI.
 * http://www.x86-64.org/documentation/abi.pdf
 */

typedef struct {
    unsigned int gp_offset;
    unsigned int fp_offset;
    void *overflow_arg_area;
    void *reg_save_area;
} __va_elem;

typedef __va_elem va_list[1];

static void *__va_arg_gp(__va_elem *ap) {
    void *r = (char *)ap->reg_save_area + ap->gp_offset;
    ap->gp_offset += 8;
    return r;
}

static void *__va_arg_fp(__va_elem *ap) {
    void *r = (char *)ap->reg_save_area + ap->fp_offset;
    ap->fp_offset += 16;
    return r;
}

static void *__va_arg_mem(__va_elem *ap) {
    1 / 0; // unimplemented
}

#define va_start(ap, last) __builtin_va_start(ap)
#define va_arg(ap, type)                                \
({                                                  \
int klass = __builtin_reg_class((type *)0);     \
*(type *)(klass == 0 ? __va_arg_gp(ap) :        \
klass == 1 ? __va_arg_fp(ap) :        \
__va_arg_mem(ap));                    \
})

#define va_end(ap) 1
#define va_copy(dest, src) ((dest)[0] = (src)[0])

// Workaround to load stdio.h properly
#define __GNUC_VA_LIST 1
typedef va_list __gnuc_va_list;

#endif /* stdarg_h */
