#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>

typedef struct SchedInfo {
  int core;
  int priority;
  int run_time;
  int start_time;
  int end_time;
  int ignorable;
  int group;
} SchedInfo;


typedef struct NodeInfo {
  std::string name;
  int index;
  int core;
  std::vector<SchedInfo> v_sched_info;
  std::vector<std::string> v_subtopic;
  std::vector<std::string> v_pubtopic;
	bool is_single_process;
	int period_count;
} NodeInfo;

// typedef struct ImportantNodes{
//   std::vector<NodeInfo*> v_node_list;
// } ImportantNodes;

#endif // TYPE_H
