#ifndef _ASM_POWERPC_ARCHRANDOM_H
#define _ASM_POWERPC_ARCHRANDOM_H

#ifdef CONFIG_ARCH_RANDOM

#include <asm/machdep.h>

static inline int arch_get_random_long(unsigned long *v)
{
	return 0;
}

static inline int arch_get_random_int(unsigned int *v)
{
	return 0;
}

static inline int arch_get_random_seed_long(unsigned long *v)
{
	if (ppc_md.get_random_seed)
		return ppc_md.get_random_seed(v);

	return 0;
}
static inline int arch_get_random_seed_int(unsigned int *v)
{
	unsigned long val;
	int rc;

	rc = arch_get_random_seed_long(&val);
	if (rc)
		*v = val;

	return rc;
}

static inline int arch_has_random(void)
{
	return 0;
}

static inline int arch_has_random_seed(void)
{
	return !!ppc_md.get_random_seed;
}
#endif /* CONFIG_ARCH_RANDOM */

#ifdef CONFIG_PPC_POWERNV
int pnv_get_random_long(unsigned long *v);
#define powernv_get_random_long pnv_get_random_long
#endif

#endif /* _ASM_POWERPC_ARCHRANDOM_H */
