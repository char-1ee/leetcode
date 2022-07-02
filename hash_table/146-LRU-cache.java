package hash_table;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

class LRUCache {

    class DLinkedNode {
        int key;
        int value;
        DLinkedNode last;
        DLinkedNode next;

        DLinkedNode() {
            this.key = 0;
            this.value = 0;
            this.last = null;
            this.next = null;
        }

        DLinkedNode(int key, int value) {
            this.key = key;
            this.value = value;
            this.last = null;
            this.next = null;
        }
    }

    private void removeNode(DLinkedNode node) {
        DLinkedNode lastNode = node.last;
        DLinkedNode nextNode = node.next;
        lastNode.next = nextNode;
        nextNode.last = lastNode;
    }

    private DLinkedNode popTail() {
        DLinkedNode res = tail.last;
        removeNode(res);
        return res;
    }

    private void moveToHead(DLinkedNode node) {
        DLinkedNode nextToHead = head.next;

        node.last = head;
        node.next = nextToHead;

        head.next = node;
        nextToHead.last = node;
    }

    private Map<Integer, DLinkedNode> map;
    private int capacity; // max size of map
    private int size; // current size of map
    private DLinkedNode head, tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        this.size = 0;

        this.head = new DLinkedNode();
        this.tail = new DLinkedNode();
        head.next = tail;
        tail.last = head;
    }

    public int get(int key) {
        DLinkedNode node = map.getOrDefault(key, null);
        if (node == null)
            return -1;

        removeNode(node);
        moveToHead(node);

        return node.value;
    }

    public void put(int key, int value) {
        DLinkedNode node = map.getOrDefault(key, null);

        if (node != null) { // put -> update
            node.value = value;
            removeNode(node);
            moveToHead(node);
        } else { // put a new node
            node = new DLinkedNode(key, value);
            map.put(key, node);
            moveToHead(node);
            size++;

            if (size > capacity) {
                DLinkedNode popNode = popTail();
                map.remove(popNode.key);
                --size;
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

class LRUCache2 extends LinkedHashMap<Integer, Integer> {
    private int capacity;

    public LRUCache2(int capacity) {
        super(capacity, 0.75F, true); // set accessOrder true
        this.capacity = capacity;
    }

    public int get(int key) {
        return super.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        super.put(key, value);
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        return this.size() > capacity;
    }
}