package elementary.ksum;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import utils.TreeNode;

/** 
 * 1. Inorder traverse; 
 * 2. two-pointer find the target 
 * time: O(n)
 */
class Solution1 {
    private List<Integer> list = new ArrayList<>();

    public boolean findTarget(TreeNode root, int k) {
        traverse(root);
        return find(k);
    }
    private void traverse(TreeNode root) {
        if (root == null)
            return;
        traverse(root.left);
        list.add(root.val);
        traverse(root.right);
    }
    private boolean find(int k) {
        int i = 0, j = list.size() - 1;
        while (i < j) {
            int sum = list.get(j) + list.get(i);
            if (sum == k)
                return true;
            else if (sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
}

/**
 * Hashset + recursion 
 * time: O(n), space: O(n)
 */
class Solution2 {
    private HashSet<Integer> set = new HashSet<>();
    
    public boolean findTarget(TreeNode root, int k) {
        return find(root, k);
    }
    
    private boolean find(TreeNode root, int k) {
        if (root == null) return false;
        if (set.contains(k - root.val)) {
            return true;
        } 
        set.add(root.val);
        return find(root.left, k) || find(root.right, k);
    }
}