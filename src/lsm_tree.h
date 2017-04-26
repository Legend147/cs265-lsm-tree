#include <vector>

#include "spin_lock.h"
#include "types.h"

#define DEFAULT_TREE_DEPTH 3
#define DEFAULT_TREE_FANOUT 10
#define DEFAULT_BUFFER_NUM_PAGES 1000
#define DEFAULT_THREAD_COUNT 4

#define DUMP_PATTERN "%d:%d"
#define LEVEL_NUM_ENTRIES_PATTERN "LVL%d: %lu"

class LSMTree {
    Buffer buffer;
    int enclosure_size, num_threads;
    std::vector<Level> levels;
    Enclosure * get_enclosure(int) const;
    void merge_down(vector<Level>::iterator);
public:
    LSMTree(int, int, int, int);
    void put(KEY_t, VAL_t);
    void get(KEY_t) const;
    void range(KEY_t, KEY_t) const;
    void del(KEY_t);
    void load(std::string);
    void stats(void) const;
};