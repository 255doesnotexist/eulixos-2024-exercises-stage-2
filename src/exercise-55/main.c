#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void
set_memory_limit (rlim_t memory_limit)
{
  struct rlimit rl;

  // TODO 设置进程的内存限制
  rl.rlim_cur = memory_limit;
  rl.rlim_max = memory_limit;

  // TODO 使用 setrlimit 函数设置进程的资源限制
  if (setrlimit(RLIMIT_AS, &rl) != 0) {
      perror("setrlimit failed");
      exit(EXIT_FAILURE);
  }
}

void
run_child_process (rlim_t memory_limit, const char *program_path)
{
  pid_t pid = fork ();
  if (pid == 0)
    {
      // 子进程
      set_memory_limit (memory_limit);
      execl (program_path, program_path, (char *)NULL);
      // 如果 execl 返回，说明出错了
      perror ("execl failed");
      exit (EXIT_FAILURE);
    }
  else if (pid > 0)
    {
      // 父进程
      int status;
      waitpid (pid, &status, 0);
      if (WIFEXITED (status))
        {
          printf ("Child process exited with status %d\n",
                  WEXITSTATUS (status));
        }
      else if (WIFSIGNALED (status))
        {
          printf ("Child process killed by signal %d\n", WTERMSIG (status));
        }
    }
  else
    {
      // fork 失败
      perror ("fork failed");
      exit (EXIT_FAILURE);
    }
}

int
main ()
{
  // 设置内存限制为 100 MB
  rlim_t memory_limit = 100 * 1024 * 1024; // 100 MB

  // 要运行的子进程程序路径
  // const char* program_path = "./child_program";
  const char *program_path = "./build/exercise-55/child_program";
  // 运行子进程并设置内存限制
  run_child_process (memory_limit, program_path);

  return 0;
}
