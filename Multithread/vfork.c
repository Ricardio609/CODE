#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int val = 100;
    pid_t id = vfork();

    if (id == 0)
    {
        // child
        int cnt = 0;
        while (1)
        {
            printf("I'm a child pid: %d ppid: %d val: %d &val: %p\n", getpid(), getppid(), val, &val);
            cnt++;
            sleep(1);
            if (cnt == 2)
                val = 200;
            if (cnt == 5)
                exit(0);
        }
    }
    else if (id > 0)
    {
        // parent
        int cnt = 0;
        while (1)
        {
            printf("I'm a parent pid: %d ppid: %d val: %d &val: %p\n", getpid(), getppid(), val, &val);
            cnt++;
            sleep(1);
            if (cnt == 3)
                val = 300;
        }
    }
    return 0;
}