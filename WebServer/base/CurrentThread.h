
#pragma once
#include <stdint.h>




//__builtin_expect() 是 GCC (version >= 2.96）提供给程序员使用的，目的是将“分支转移”的信息提供给编译器，这样编译器可以对代码进行优化，以减少指令跳转带来的性能下降。
//__builtin_expect((x),1)表示 x 的值为真的可能性更大；
//__builtin_expect((x),0)表示 x 的值为假的可能性更大。
//也就是说，使用likely()，执行 if 后面的语句的机会更大，使用 unlikely()，执行 else 后面的语句的机会更大。通过这种方式，编译器在编译过程中，会将可能性更大的代码紧跟着起面的代码，从而减少指令跳转带来的性能上的下降



//注意，该.h只是一个头文件 指明了一个namespace,里面有一些变量和函数
//在Thread.cpp(有对应的Thread.h)中定义引入的变量与函数


namespace CurrentThread {
// internal
extern __thread int t_cachedTid;    //线程id
extern __thread char t_tidString[32];  //线程id的字符串表示
extern __thread int t_tidStringLength;//线程id的字符串长度
extern __thread const char* t_threadName;//启动线程自命名
void cacheTid();
inline int tid() {
  if (__builtin_expect(t_cachedTid == 0, 0)) {
    cacheTid();
  }
  return t_cachedTid;
}

inline const char* tidString()  // for logging
{
  return t_tidString;
}

inline int tidStringLength()  // for logging
{
  return t_tidStringLength;
}

inline const char* name() { return t_threadName; }
}
