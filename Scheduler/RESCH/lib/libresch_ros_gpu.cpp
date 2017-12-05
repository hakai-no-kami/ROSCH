#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "api_ros_gpu.h"

pthread_mutex_t *m;
int shmid;
std::priority_queue<int> pq;

int ros_gsched_init(){
	pthread_mutexattr_t mat;
  shmid = shmget(IPC_PRIVATE, sizeof(pthread_mutex_t), 0600);
  if (shmid < 0) {
    perror("shmget");
    return 1;
  }

  m = (pthread_mutex_t*)shmat(shmid, NULL, 0);
  if (m == (void*)-1) {
    perror("shmat");
    return 1;
  }

  pthread_mutexattr_init(&mat);
	if (pthread_mutexattr_setpshared(&mat, PTHREAD_PROCESS_SHARED) != 0) {
    perror("pthread_mutexattr_setpshared");
    return 1;
  }
  pthread_mutex_init(m, &mat);
	return 0;
}

int ros_gsched_enqueue()
{
	int my_prio;

	my_prio = getpriority(PRIO_PROCESS,0);
	pq.push(my_prio);
	
	while(1){
		if(pq.top() == my_prio){
			if (pthread_mutex_lock(m) != 0) {
				perror("pthread_mutex_lock");
    	  return 1;
  	  }
			break;
		}
	}
	return 0;
}

int ros_gsched_dequeue()
{
	if (pthread_mutex_unlock(m) != 0) {
    perror("pthread_mutex_unlock");
    return 1;
  }
	pq.pop();
	return 0;
}

int ros_gsched_exit()
{
	if(pq.size() != 0)
	{
		shmdt(m);
	}
	else{
		if (shmctl(shmid, IPC_RMID, NULL) != 0) {
			perror("shmctl");
			return 1;
		}
	}
	return 0;
}

#if 0
int sample()
{
  pid_t pid;

  pid = fork();
  printf("[%s] before pthread_mutex_lock()\n",pid == 0 ? "child" : "parent");

	/* rosch*/
	ros_gsched_enqueue();
  
  printf("[%s] press enter\n", pid == 0 ? "child" : "parent");
  getchar();

	/* rosch */
	ros_gsched_dequeue();

  printf("[%s] after pthread_mutex_unlock()\n",pid == 0 ? "child" : "parent");
  
	/* rosch */
	ros_gsched_exit();

  if (pid != 0) {
    wait(NULL);
    printf("[%s] after wait()\n", pid == 0 ? "child" : "parent");
		
		/* rosch */
		ros_gsched_exit();
   }
	return 0;
}

int main ()
{
	ros_gsched_init();
	sample();
  
	return 0;
}
#endif
