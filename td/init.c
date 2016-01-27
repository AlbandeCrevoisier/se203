/* init.c */

extern char _bss_start, _bss_end;

void
init_bss(void)
{
	char *i = &(_bss_start);
	while (i < &(_bss_end))
		*i++ = 0;
}
