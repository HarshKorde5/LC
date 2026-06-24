/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
        public Node copyRandomList(Node head) { 

        if(head == null)    return null;
        Node oldHead = head;

        while(oldHead != null){
            Node newnode = new Node(oldHead.val);
            newnode.next = oldHead.next;
            oldHead.next = newnode;

            oldHead = newnode.next;
        }

        Node newHead = head.next;
        oldHead = head;

        while(oldHead != null){

            if(oldHead.random != null){
                oldHead.next.random = oldHead.random.next;
            }

            oldHead = oldHead.next.next;
        }


        oldHead = head;
        while(oldHead != null){
            Node temp = oldHead.next;
            oldHead.next = temp.next;

            if(temp.next != null){
                temp.next = temp.next.next;
            }

            oldHead = oldHead.next;
        }

        return newHead;
    }
    public Node copyRandomList_01(Node head) {
        Map<Node, Node> copyMap = new HashMap<>();
        copyMap.put(null,null);

        Node curr = head;

        while(curr != null){

            if(!copyMap.containsKey(curr)){
                copyMap.put(curr, new Node(0));
            }
            copyMap.get(curr).val = curr.val;

            if(!copyMap.containsKey(curr.next)){
                copyMap.put(curr.next, new Node(0));
            }
            copyMap.get(curr).next = copyMap.get(curr.next);

            if(!copyMap.containsKey(curr.random)){
                copyMap.put(curr.random, new Node(0));
            }
            copyMap.get(curr).random = copyMap.get(curr.random);

            curr = curr.next;
        }

        return copyMap.get(head);
    }
}
