/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
*/

import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;

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
    public TreeNode createBalancedBST(List<Integer> inorder, int start, int end) {
        if (start > end) {
            return null;
        }

        int mid = start + (end - start) / 2;
        TreeNode node = new TreeNode(inorder.get(mid));

        node.left = createBalancedBST(inorder, start, mid - 1);
        node.right = createBalancedBST(inorder, mid + 1, end);

        return node;

    }

    public void inorderTraversal(TreeNode root, List<Integer> inorder) {
        if (root == null) {
            return;
        }

        inorderTraversal(root.left, inorder);
        inorder.add(root.val);
        inorderTraversal(root.right, inorder);

    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> inorder = new ArrayList<>();
        inorderTraversal(root, inorder);

        return createBalancedBST(inorder, 0, inorder.size() - 1);
    }
}

class Problem1382 {
    public static void main(String args[]) {

    }
}