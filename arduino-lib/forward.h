#pragma once
extern "C" void __cxa_pure_virtual(void);
__extension__ typedef int __guard __attribute__((mode (__DI__)));
extern "C" int __cxa_guard_acquire(__guard *g);
extern "C" void __cxa_guard_release (__guard *g);
extern "C" void __cxa_guard_abort (__guard *g);
