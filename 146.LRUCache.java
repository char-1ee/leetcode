import java.util.HashMap;

class LRUCache {

    class LinkedNode {
        int key;
        int val;
        LinkedNode prev;
        LinkedNode next;
    }
    
    /** add a node in head */
    private void addNode(LinkedNode node) {
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }
    
    /** remove a node */
    private void removeNode(LinkedNode node) {
        LinkedNode prevNode = node.prev;
        LinkedNode nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    } 
    
    /** move a used node to head */
    private void moveToHead(LinkedNode node) {
        removeNode(node);
        addNode(node);
    }
    
    /** pop the tail node */
    private LinkedNode popTail() {
        LinkedNode node = tail.prev;
        removeNode(node);
        return node;
    }
    
    private int capacity;
    private int size;
    private LinkedNode head, tail;
    private HashMap<Integer, LinkedNode> cache;
    
    public LRUCache(int capacity) {
        this.size = 0;
        this.capacity = capacity;
        this.cache = new HashMap<>();
        this.head = new LinkedNode();
        this.tail = new LinkedNode();
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        LinkedNode node = cache.get(key);
        if (node == null) return -1;
        moveToHead(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        LinkedNode node = cache.get(key);
        if (node != null) {
            node.val = value;
            moveToHead(node);
        } else {
            LinkedNode newNode = new LinkedNode();
            newNode.val = value;
            newNode.key = key;
            
            cache.put(key, newNode);
            addNode(newNode);
            size++;
            if (size > capacity) {
                LinkedNode tail = popTail();
                cache.remove(tail.key);
                size--;
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