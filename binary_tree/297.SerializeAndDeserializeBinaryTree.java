package binary_tree;

import utils.TreeNode;
import java.util.*;

/** DFS */
class Codec_DFS {
    private static final String N = "null";
    private static final String comma = ",";
    private int index; // index for deserialization

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        buildString(root, sb);
        return sb.toString();
    }

    private void buildString(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append(N).append(comma);
            return;
        }
        sb.append(root.val).append(comma);
        buildString(root.left, sb);
        buildString(root.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        // Alternativly, use queue to contain String, but timecosting
        String[] str = data.split(comma);
        index = 0;
        return buildTree(str);
    }

    private TreeNode buildTree(String[] str) {
        if (index >= str.length || str[index].equals(N)) {
            index++; // cannot written in `str[idnex++].equals(N)`
            return null;
        }
        TreeNode t = new TreeNode(Integer.parseInt(str[index++]));
        t.left = buildTree(str);
        t.right = buildTree(str);
        return t;
    }
}

/** BFS */
class Codec_BFS {

    private static final String COMMA = ",";
    private static final String NULL = "null";

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null)
            return "";
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            TreeNode t = q.poll();
            if (t != null) {
                sb.append(t.val).append(COMMA);
                q.add(t.left);
                q.add(t.right);
            } else {
                sb.append(NULL).append(COMMA);
            }
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == "")
            return null;
        Queue<TreeNode> q = new LinkedList<>();
        String[] str = data.split(COMMA);
        TreeNode root = new TreeNode(Integer.parseInt(str[0]));
        q.add(root);
        for (int i = 1; i < str.length; i++) {
            TreeNode t = q.poll();
            if (!str[i].equals(NULL)) {
                TreeNode left = new TreeNode(Integer.parseInt(str[i]));
                t.left = left;
                q.add(left);
            }
            if (!str[++i].equals(NULL)) {
                TreeNode right = new TreeNode(Integer.parseInt(str[i]));
                t.right = right;
                q.add(right);
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));