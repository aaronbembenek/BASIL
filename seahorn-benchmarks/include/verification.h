#pragma once

#ifdef __BASIL__

volatile int __NONDET_INT;

__attribute__((noinline)) int __VERIFIER_nondet_int()
{
    return __NONDET_INT;
}

volatile long __NONDET_LONG;

__attribute__((noinline)) long __VERIFIER_nondet_long()
{
    return __NONDET_LONG;
}

__attribute__((noinline)) unsigned int __VERIFIER_nondet_uint() {
    return __VERIFIER_nondet_int();
}

__attribute__((noinline)) int __VERIFIER_nondet_bool() {
    return __VERIFIER_nondet_int();
}

__attribute__((noinline)) char __VERIFIER_nondet_char() {
    return (char)__VERIFIER_nondet_int();
}

__attribute__((noinline, noreturn)) void __VERIFIER_error()
{
    while (1)
    {
        // do nothing
    }
}

__attribute__((noinline)) void __VERIFIER_assume(int e)
{
    while (!e)
    {
        // do nothing
    }
}
#endif

__attribute__((noinline)) void __VERIFIER_assert(int e)
{
    if (!e)
    {
        __VERIFIER_error();
    }
}

#define assume(e) __VERIFIER_assume(e)

#define unknown() __VERIFIER_nondet_int()
#define unknown1() __VERIFIER_nondet_int()
#define unknown2() __VERIFIER_nondet_int()
#define unknown3() __VERIFIER_nondet_int()
#define unknown4() __VERIFIER_nondet_int()
#define nondet() __VERIFIER_nondet_int()
#define rand() __VERIFIER_nondet_int()

#define __assert_fail(e, file, line, fun) __VERIFIER_error()

#define sassert(e) __VERIFIER_assert(e)

#define tmpl(x) ((void)(0))

#define LARGE_INT 1000000

int printf(char const *__restrict __format, ...)
{
    return 0;
}

int puts(char const *__s)
{
    return 0;
}

__attribute__((noreturn, always_inline)) void exit(int code)
{
    __VERIFIER_assume(0);
    while (1)
    {
        // do nothing
    }
}
