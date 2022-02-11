class LRUCache {
    
    class DListNode {
        int key;
        int value;
        DListNode prev;
        DListNode next;
        
        DListNode() {
            this.key = 0;
            this.value = 0;
            this.prev = null;
            this.next = null;
        }
        
        DListNode(int key, int value) {
            this.key = key;
            this.value = value;
            this.prev = null;
            this.next = null;
        }
    }    
    
    private Map<Integer, DListNode> m;
    private final int limit;
    private int count;
    private DListNode head, tail;

    public LRUCache(int capacity) {
        this.limit = capacity;
        this.count = 0;
        this.m = new HashMap<>();
        this.head = new DListNode();
        this.tail = new DListNode();
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if (m.containsKey(key)) {
            DListNode node = m.get(key);
            swim(node);
            return node.value;
        } else 
            return -1;
    }
    
    public void put(int key, int value) {
        DListNode node = m.get(key);
        if (node == null) {
            DListNode n = new DListNode(key, value);
            add(node);
            count++;
            if (count > limit) {
                m.remove(pop());
                count--;
            } 
            m.put(key, node);
        } else {
            node.value = value;
            swim(node);
        }
    }
    
    /** Make a recently used node swim to front */
    private void swim(DListNode node) {
        add(node);
        remove(node);
    }
    
    /** Add new coming node in front */
    private void add(DListNode node) {
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }
    
    /** Remove certain node from list */
    private void remove(DListNode node) {
        DListNode prevNode = node.prev;
        DListNode nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }
    
    /** Remove the node at tail when exceed limit */
    private int pop() {
        DListNode prevTail = tail.prev;
        remove(prevTail);
        return prevTail.key;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */