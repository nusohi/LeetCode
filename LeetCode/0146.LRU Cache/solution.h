#include <unordered_map>
#include <list>
using namespace std;

typedef list<pair<int, int>> LIST;
typedef unordered_map<int, LIST::iterator> MAP;

class LRUCache {
private:
	int capacity;
	unordered_map<int, LIST::iterator> map;
	list<pair<int, int>> cache;

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		MAP::iterator iter = map.find(key);
		if (iter != map.end()) {
			pair<int, int> kv = *map[key];
			cache.erase(map[key]);
			cache.push_front(kv);
			map[key] = cache.begin();

			return kv.second;
		}
		return -1;
	}

	void put(int key, int value) {
		MAP::iterator iter = map.find(key);

		if (iter != map.end()) {
			// 找到了 已存在，更新
			cache.erase(map[key]);
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();
		}
		else {
			if (map.size() == capacity) {
				// 满了 删除尾部
				map.erase(cache.back().first);
				cache.pop_back();
			}
			// 插入数据
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();
		}

	}
};
