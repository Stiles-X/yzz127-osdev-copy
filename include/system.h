#ifndef __SYSTEM_H
#define __SYSTEM_H

/* MAIN.C */
extern unsigned char *memecpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *emeset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen(const char *str);
extern unsigned char inportb(unsigned short _port);
extern void outportb(unsigned short _port, unsigned char _data);

extern void cls();
extern void putch(unsigned char c);
extern void puts(unsigned char *str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();

extern void gdt_install();
extern void idt_install();
extern void isrs_install();

typedef struct regs
{
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;
} register_t;

void irq_install_handler(int irq, void (*handler)(register_t *r));
void irq_uninstall_handler(int irq);
void irq_install();

void timer_install(unsigned int frequency);

void keyborad_install();

#define NULL 0

#endif