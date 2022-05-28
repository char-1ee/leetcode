package binary_tree;

import utils.TreeNode;

class Codec {
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

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));