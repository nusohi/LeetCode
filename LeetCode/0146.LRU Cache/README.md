# 146. LRU缓存机制 | LRU Cache

**题目:**

运用你所掌握的数据结构，设计和实现一个  [LRU (最近最少使用) 缓存机制](https://baike.baidu.com/item/LRU)。它应该支持以下操作： 获取数据 `get` 和 写入数据 `put` 。

获取数据 `get(key)` - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。

写入数据 `put(key, value)` - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

**进阶:**

你是否可以在 **O(1)** 时间复杂度内完成这两种操作？

**示例:**

```
LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
```

## 思路

### 哈希表 + 双向链表

时间复杂度为 **O(1)** ：

- 获取数据 `get` 应该依赖**哈希表**来查找，并且需要将 `Cache` *(链表)*中的数据移至表头。
- 写入数据 `put` 时也需要将数据放在 `Cache` 的表头，而如果数据存满，需要删除表尾元素，并找到对应哈希表中的 `key` 将其删除，所以 `Cache` 中存储键值对 `pair<int, int>` 。

![](https://pic.leetcode-cn.com/9201fabe4dfdb5a874b43c325d39857182c8ec267f830649a52dda90a63d6671-file_1562356927818)

执行时间 ***160ms*** 。([Submission Detail](https://leetcode-cn.com/submissions/detail/25259610/))

```cpp
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
```

