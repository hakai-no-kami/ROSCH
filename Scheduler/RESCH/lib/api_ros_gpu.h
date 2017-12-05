#ifndef __LIB_ROS_GPU_H__
#define __LIB_ROS_GPU_H__

#include <sys/shm.h>
#include <pthread.h>
#if 0
#ifdef __cplusplus
extern "C"{
#endif
#endif
#include <queue>
#include <iostream>

int ros_gsched_init(void);
int ros_gsched_enqueue(void);
int ros_gsched_dequeue(void);
int ros_gsched_exit(void);

extern pthread_mutex_t *m;
extern int shmid;
extern std::priority_queue<int> pq; 
#if 0
#ifdef __cplusplus
}
#endif
#endif
#endif
