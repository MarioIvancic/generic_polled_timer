// generic_polled_timer_test.cpp

#include "generic_polled_timer.h"
#include "monotonic_time.h"
#include "unity.h"
#include <stdio.h>
#include <string.h>

using Polled1UsTimer = GenericPolledTimer<decltype(get_monotonic_time()), get_monotonic_time>;
using Polled1UsTimerA = GenericPolledTimerA<decltype(get_monotonic_time()), get_monotonic_time>;

void test_polled_timer_now(void);
void test_polled_timer_set(void);
void test_polled_timer_expired_0(void);
void test_polled_timer_expired_1(void);
void test_polled_timer_expired_2(void);
void test_polled_timer_expired_3(void);
void test_polled_timer_expired_ex_0(void);
void test_polled_timer_expired_ex_1(void);
void test_polled_timer_expired_ex_2(void);
void test_polled_timer_expired_ex_3(void);
void test_polled_timer_expired_ex_4(void);

void test_polled_timer_A_now(void);
void test_polled_timer_A_set(void);
void test_polled_timer_A_expired_0(void);
void test_polled_timer_A_expired_1(void);
void test_polled_timer_A_expired_2(void);
void test_polled_timer_A_expired_3(void);
void test_polled_timer_A_expired_ex_0(void);
void test_polled_timer_A_expired_ex_1(void);
void test_polled_timer_A_expired_ex_2(void);
void test_polled_timer_A_expired_ex_3(void);
void test_polled_timer_A_expired_ex_4(void);


void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}


int generic_polled_timer_test_all(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_polled_timer_now);
    RUN_TEST(test_polled_timer_set);
    RUN_TEST(test_polled_timer_expired_0);
    RUN_TEST(test_polled_timer_expired_1);
    RUN_TEST(test_polled_timer_expired_2);
    RUN_TEST(test_polled_timer_expired_3);
    RUN_TEST(test_polled_timer_expired_ex_0);
    RUN_TEST(test_polled_timer_expired_ex_1);
    RUN_TEST(test_polled_timer_expired_ex_2);
    RUN_TEST(test_polled_timer_expired_ex_3);
    RUN_TEST(test_polled_timer_expired_ex_4);

    RUN_TEST(test_polled_timer_A_now);
    RUN_TEST(test_polled_timer_A_set);
    RUN_TEST(test_polled_timer_A_expired_0);
    RUN_TEST(test_polled_timer_A_expired_1);
    RUN_TEST(test_polled_timer_A_expired_2);
    RUN_TEST(test_polled_timer_A_expired_3);
    RUN_TEST(test_polled_timer_A_expired_ex_0);
    RUN_TEST(test_polled_timer_A_expired_ex_1);
    RUN_TEST(test_polled_timer_A_expired_ex_2);
    RUN_TEST(test_polled_timer_A_expired_ex_3);
    RUN_TEST(test_polled_timer_A_expired_ex_4);
    return UNITY_END();
}


void test_polled_timer_now(void)
{
    Polled1UsTimer::value_type E;
    Polled1UsTimer::value_type t;
    Polled1UsTimer T;

    E = 0;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 1;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 2;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x7FFFFFFFU;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x80000000U;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x80000001U;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0xFFFFFFFEU;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0xFFFFFFFFU;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);
}


void test_polled_timer_set(void)
{
    Polled1UsTimer::value_type now = 0;
    Polled1UsTimer::value_type T = 1;
    Polled1UsTimer::value_type E;
    Polled1UsTimer::value_type t;
    Polled1UsTimer P;

    now = 0;
    set_monotonic_time(now);

    T = 0;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 1;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 2;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFU;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000000U;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000001U;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFEU;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFFU;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);


    now = 0x7FFFFFFFU;
    set_monotonic_time(now);

    T = 0;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 1;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 2;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFU;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000000U;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000001U;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFEU;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFFU;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    now = 0xFFFFFFFFU;
    set_monotonic_time(now);

    T = 0;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 1;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 2;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFU;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000000U;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000001U;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFEU;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFFU;  E = now + T;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);
}


void test_polled_timer_expired_0(void)
{
    Polled1UsTimer::value_type T1 = 0;
    Polled1UsTimer::value_type T2;
    Polled1UsTimer::value_type TO;
    bool r;
    Polled1UsTimer t;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_1(void)
{
    Polled1UsTimer::value_type T1 = 0x7FFFFFFFU;
    Polled1UsTimer::value_type T2;
    Polled1UsTimer::value_type TO;
    Polled1UsTimer t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_2(void)
{
    Polled1UsTimer::value_type T1 = 0x80000000U;
    Polled1UsTimer::value_type T2;
    Polled1UsTimer::value_type TO;
    Polled1UsTimer t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_3(void)
{
    Polled1UsTimer::value_type T1 = 0xFFFFFFFFU;
    Polled1UsTimer::value_type T2;
    Polled1UsTimer::value_type TO;
    Polled1UsTimer t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_ex_0(void)
{
    Polled1UsTimer::value_type T1;
    Polled1UsTimer::value_type T2;
    Polled1UsTimer t;
    bool r;

    // testing for expired timer for timeout 0 when time moves from T1 to T2
    // if should be expired for any times

    // start time = 0
    T1 = 0;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);


    // start time = 0x7FFFFFFFU
    T1 = 0x7FFFFFFFU;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    // start time = 0x80000000U
    T1 = 0x80000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    // start time = 0xFFFFFFFFU
    T1 = 0xFFFFFFFFU;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_expired_ex_1(void)
{
    Polled1UsTimer::value_type T1 = 0;
    Polled1UsTimer::value_type T2;
    Polled1UsTimer::value_type TO;
    Polled1UsTimer t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_ex_2(void)
{
    Polled1UsTimer::value_type T1 = 0x7FFFFFFFU;
    Polled1UsTimer::value_type T2;
    Polled1UsTimer::value_type TO;
    Polled1UsTimer t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_expired_ex_3(void)
{
    Polled1UsTimer::value_type T1 = 0x80000000U;
    Polled1UsTimer::value_type T2;
    Polled1UsTimer::value_type TO;
    Polled1UsTimer t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_expired_ex_4(void)
{
    Polled1UsTimer::value_type T1 = 0xFFFFFFFFU;
    Polled1UsTimer::value_type T2;
    Polled1UsTimer::value_type TO;
    Polled1UsTimer t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_A_now(void)
{
    Polled1UsTimerA::value_type E;
    Polled1UsTimerA::value_type t;
    Polled1UsTimerA T;

    E = 0;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 1;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 2;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x7FFFFFFFU;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x40000000U;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x40000001U;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x7FFFFFFEU;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x7FFFFFFFU;
    set_monotonic_time(E);
    T.now();
    t = T.value();
    TEST_ASSERT_EQUAL_INT32(E, t);
}


void test_polled_timer_A_set(void)
{
    Polled1UsTimerA::value_type now = 0;
    Polled1UsTimerA::value_type T = 1;
    Polled1UsTimerA::value_type E;
    Polled1UsTimerA::value_type t;
    Polled1UsTimerA P;

    now = 0;
    set_monotonic_time(now);

    T = 0;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 1;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 2;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x3FFFFFFU;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x40000000U;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x40000001U;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFEU;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFFU;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);


    now = 0x3FFFFFFFU;
    set_monotonic_time(now);

    T = 0;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 1;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 2;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x3FFFFFFU;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x40000000U;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x40000001U;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFEU;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFFU;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    now = 0x7FFFFFFFU;
    set_monotonic_time(now);

    T = 0;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 1;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 2;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x3FFFFFFU;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x40000000U;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x40000001U;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFEU;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFFU;  E = (now + T) & 0x7FFFFFFFU;
    P.set(T);
    t = P.value();
    TEST_ASSERT_EQUAL_INT32(E, t);
}


void test_polled_timer_A_expired_0(void)
{
    Polled1UsTimerA::value_type T1;
    Polled1UsTimerA::value_type T2;
    Polled1UsTimerA::value_type TO;
    bool r;
    Polled1UsTimerA t;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    T1 = 0;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x3FFFFFFF;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x40000000U

    TO = 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_A_expired_1(void)
{
    Polled1UsTimerA::value_type T1;
    Polled1UsTimerA::value_type T2;
    Polled1UsTimerA::value_type TO;
    Polled1UsTimerA t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    T1 = 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x3FFFFFFF

    TO = 0x3FFFFFFF;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x40000000U

    TO = 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_A_expired_2(void)
{
    Polled1UsTimerA::value_type T1;
    Polled1UsTimerA::value_type T2;
    Polled1UsTimerA::value_type TO;
    Polled1UsTimerA t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    T1 = 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x3FFFFFFF

    TO = 0x3FFFFFFF;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x40000000U

    TO = 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_A_expired_3(void)
{
    Polled1UsTimerA::value_type T1;
    Polled1UsTimerA::value_type T2;
    Polled1UsTimerA::value_type TO;
    Polled1UsTimerA t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    T1 = 0x7FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x3FFFFFFF

    TO = 0x3FFFFFFF;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x40000000U

    TO = 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T1);
    t.set(TO);
    set_monotonic_time(T2);
    r = t.expired();
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_A_expired_ex_0(void)
{
    Polled1UsTimerA::value_type T1;
    Polled1UsTimerA::value_type T2;
    Polled1UsTimerA t;
    bool r;

    // testing for expired timer for timeout 0 when time moves from T1 to T2
    // if should be expired for any times

    // start time = 0
    T1 = 0;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);


    // start time = 0x3FFFFFFFU
    T1 = 0x3FFFFFFFU;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    // start time = 0x40000000U
    T1 = 0x40000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    // start time = 0x7FFFFFFFU
    T1 = 0x7FFFFFFFU;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(0);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_A_expired_ex_1(void)
{
    Polled1UsTimerA::value_type T1 = 0;
    Polled1UsTimerA::value_type T2;
    Polled1UsTimerA::value_type TO;
    Polled1UsTimerA t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x3FFFFFFF

    TO = 0x3FFFFFFF;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x40000000U

    TO = 0x40000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_A_expired_ex_2(void)
{
    Polled1UsTimerA::value_type T1 = 0x3FFFFFFFU;
    Polled1UsTimerA::value_type T2;
    Polled1UsTimerA::value_type TO;
    Polled1UsTimerA t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x3FFFFFFF

    TO = 0x3FFFFFFF;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x40000000U

    TO = 0x40000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_A_expired_ex_3(void)
{
    Polled1UsTimerA::value_type T1 = 0x40000000U;
    Polled1UsTimerA::value_type T2;
    Polled1UsTimerA::value_type TO;
    Polled1UsTimerA t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x3FFFFFFF

    TO = 0x3FFFFFFF;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x40000000U

    TO = 0x40000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_A_expired_ex_4(void)
{
    Polled1UsTimerA::value_type T1 = 0x7FFFFFFFU;
    Polled1UsTimerA::value_type T2;
    Polled1UsTimerA::value_type TO;
    Polled1UsTimerA t;
    bool r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x3FFFFFFF

    TO = 0x3FFFFFFF;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x40000000U

    TO = 0x40000000U;
    set_monotonic_time(T1);
    t.now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x3FFFFFFFU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x40000000U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000001U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x40000002U;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFEU;
    set_monotonic_time(T2);
    r = t.expired(TO);
    TEST_ASSERT_TRUE(r);
}
