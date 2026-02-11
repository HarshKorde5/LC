/*
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
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
    public void inorder(TreeNode root, List<Integer> in) {
        if (root == null)
            return;

        inorder(root.left, in);

        in.add(root.val);

        inorder(root.right, in);

    }

    public List<Integer> getAllElements_1(TreeNode root1, TreeNode root2) {
        List<Integer> list = new ArrayList<>();
        inorder(root1, list);
        inorder(root2, list);

        Collections.sort(list);

        return list;

    }

    public void pushLeft(TreeNode root, Stack<TreeNode> stack) {
        while (root != null) {
            stack.push(root);
            root = root.left;
        }
    }

    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> res = new ArrayList();
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();

        pushLeft(root1, s1);
        pushLeft(root2, s2);

        while (!s1.isEmpty() || !s2.isEmpty()) {
            Stack<TreeNode> stk;

            if (s2.isEmpty() || (!s1.isEmpty() && s1.peek().val <= s2.peek().val)) {
                stk = s1;
            } else {
                stk = s2;
            }

            TreeNode node = stk.pop();
            res.add(node.val);

            pushLeft(node.right, stk);
        }

        return res;

    }
}

class Problem1305 {
    public static void main(String[] args) {

    }
}