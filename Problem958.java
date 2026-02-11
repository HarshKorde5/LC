/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        boolean isComplete = false;

        while (q.isEmpty() != true) {
            TreeNode node = q.poll();

            if (node == null) {
                isComplete = true;
            } else {
                if (isComplete == true)
                    return false;
                q.offer(node.left);
                q.offer(node.right);
            }
        }

        return true;
    }
}

class Problem958 {
    public static void main(String[] args) {

    }
}