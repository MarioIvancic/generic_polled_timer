# generic_polled_timer
Generic polled timer C++ template class than needs to be polled to check for timeout event


# Building (for testing and code coverage analysis)
Makefile is designed for building on Linux using gcc, gcov, lcov and genhtml. You can:

  * **make debug**     to make debug version
  * **make release**   to make release version
  * **make all**       to make debug and release versions
  * **make**           same as 'make all'
  * **make coverage**  to test line and function coverage
  * **make clean**     to clean working directory



# Customization

```C++
GenericPolledTimer<class T, T (*f)()>
GenericPolledTimerA<class T, T (*f)()>
```

  * **T**
The data type for internal variable. Usually set to decltype(f())


  * **f**
A time source function that takes no arguments and return some kind of intager.



# Generic polled timer API

The GenericPolledTimer and GenericPolledTimerA are template'd versions of the
old PolledTimer class. They are generic in a sense that time source function
and data type are template arguments so it is possible to have two or more
versions in the same program, for instance one with time base 1ms and another
with time base 1s.

Template GenericPolledTimer<class T, T (*f)()> has two parameters.
The first parameter T is a type parameter which is the return type of a time
source function and also type of internal data variable. It is also available
as value_type public alias.
The second parameter f is time source function to be called by the class.

Template GenericPolledTimerA<class T, T (*f)()> has two parameters.
The first parameter T is a type parameter which is the return type of a time
source function and also type of internal data variable. It is also available
as value_type public alias.
The second parameter f is time source function to be called by the class.
This version (with A suffix) has a "armed" flag as top bit in internal state
variable. The timer is armed after a call to set() until it expires.
When timer is not in the armed state expired() will always return false
regardless of current time and timer set value.
The now() call will also put timer in armed state but expired(timeout)
will not clear the armed flag when timer expires. This needs to be done
manually using armed(false) call.

GenericPolledTimer class members


```C++
    GenericPolledTimer::value_type
```
The type of internal data and return type of the time source function.



```C++
    GenericPolledTimer::MAX_TIMEOUT
```
The constant of type value_type that represent maximal achievable timeout value.



```C++
    void GenericPolledTimer::set(value_type timeout);
```
Set timer to expire for timeout ticks from now.
Expiration is checked using bool GenericPolledTimer::expired() function.



```C++
    void GenericPolledTimer::now();
```
Set timer to current time.
Expiration is checked using bool GenericPolledTimer::expired(value_type timeout) function.
This is useful if there is more than one timeout event that all start at the same time.



```C++
    bool GenericPolledTimer::is_timedout();
    bool GenericPolledTimer::expired();
```
Test a timer for timeout event if timer is started using the set() member function.



```C++
    bool GenericPolledTimer::expired(value_type timeout);
```
Test a timer for timeout event where timeout is explicit and timer is started
using the now() member function.



We are using free running timer/counter as time source so all counter values forms a circle.
For instance, on 8-bit counter we will have 0, 1, 2, .., 253, 254, 255, 0, 1, ...
Timer current time and timer time of timeout (now() + timeout) are on the same circle.
All operations on timer values are done using modular arithmetic, so we can't tell which is
lower or higher, we can only calculate the distance between time points.
The distance D between time T and current time C is: D = (C - T) where D, C and T are all
of some unsigned integer type.

So, we must define some threshold value H so that for all distances lower than H timer is
expired and for distances higher or equal to H timer is active.

If H is big we can have longer timeout value but shorter time window for timer expiration
detection so it can be missed.

If timer period is P (for instance 65536 for 16-bit timer) then best option is to set H = P / 2

In this code MAX_TIMEOUT has the role of threshold H and it is set to
( ( (value_type) -1 ) / 2 ).

There is no flags in the timer object so timer is stateless. If you set a timer to some timeout
value, as time pass by, expired() will at first return false, then after some time
true, then after some time false, and so on.
You can't start or stop a timer, it is always running as long as you test it.
If you want to "stop" it just stop testing it, and don't forget to set it again later.


    Simple example

```C++
    extern "C" uint32_t get_monotonic_time_us(void);

    using PolledTimer1us = GenericPolledTimer<decltype(get_monotonic_time_us()), get_monotonic_time_us>;

    PolledTimer1us T;

    // implicit timeout
    T.set(1000000);

    if( T.expired() )
    {
        do_something();
    }


    // explicit timeout
    T.now();

    if( T.expired(1000000) )
    {
        do_something();
    }

    // get current value into auto variable
    auto v1 = T.value();

    // get current value into variable declared using value_type
    PolledTimer1us::value_type v2 = T.value();
```
