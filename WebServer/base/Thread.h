// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#pragma once
#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <functional>
#include <memory>
#include <string>
#include "CountDownLatch.h"
#include "noncopyable.h"
//该类对线程进行封装，并将接口放在currThread.h中

//首先 Thread初始化时 初始化各类变量，如func_  name_ latch_    tid_(进程id) pthreadId_(线程id)


class Thread : noncopyable {
 public:
  typedef std::function<void()> ThreadFunc;
  explicit Thread(const ThreadFunc&, const std::string& name = std::string());
  ~Thread();
  void start();
  int join();
  bool started() const { return started_; }
  pid_t tid() const { return tid_; }
  const std::string& name() const { return name_; }

 private:
  void setDefaultName();
  bool started_;
  bool joined_;
  pthread_t pthreadId_;
  pid_t tid_;
  ThreadFunc func_;
  std::string name_;
  CountDownLatch latch_;
};