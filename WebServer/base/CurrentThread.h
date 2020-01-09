
#pragma once
#include <stdint.h>




//__builtin_expect() �� GCC (version >= 2.96���ṩ������Աʹ�õģ�Ŀ���ǽ�����֧ת�ơ�����Ϣ�ṩ�����������������������ԶԴ�������Ż����Լ���ָ����ת�����������½���
//__builtin_expect((x),1)��ʾ x ��ֵΪ��Ŀ����Ը���
//__builtin_expect((x),0)��ʾ x ��ֵΪ�ٵĿ����Ը���
//Ҳ����˵��ʹ��likely()��ִ�� if ��������Ļ������ʹ�� unlikely()��ִ�� else ��������Ļ������ͨ�����ַ�ʽ���������ڱ�������У��Ὣ�����Ը���Ĵ������������Ĵ��룬�Ӷ�����ָ����ת�����������ϵ��½�



//ע�⣬��.hֻ��һ��ͷ�ļ� ָ����һ��namespace,������һЩ�����ͺ���
//��Thread.cpp(�ж�Ӧ��Thread.h)�ж�������ı����뺯��


namespace CurrentThread {
// internal
extern __thread int t_cachedTid;    //�߳�id
extern __thread char t_tidString[32];  //�߳�id���ַ�����ʾ
extern __thread int t_tidStringLength;//�߳�id���ַ�������
extern __thread const char* t_threadName;//�����߳�������
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
