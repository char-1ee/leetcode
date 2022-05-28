package binary_search_tree;

import java.util.*;
import utils.TreeNode;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> s = new Stack<>();
        while (root != null || !s.isEmpty())
        {
            while (root != null)
            {
                s.push(root);
                root = root.left;
            }
            root = s.pop();
            k--; // every time k--, means a leftmost leaf node is counted
            if (k == 0) break; // when kth leftmost leaf node is met, end loop
            root = root.right;
        }
        return root.val;
    }
}