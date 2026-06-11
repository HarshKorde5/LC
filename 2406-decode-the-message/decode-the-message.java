class Solution {
    public String decodeMessage(String key, String message) {
        Map<Character,Character> map = new HashMap<>();
        char ch = 'a';

        for(char x : key.toCharArray()){
            if(x == ' ') continue;
            if(!map.containsKey(x)){
                map.put(x, ch++);
            }
        }

        StringBuilder res = new StringBuilder();

        for(char x : message.toCharArray()){
            if(x == ' ') {
                res.append(' ');
                continue;
            }
            res.append(map.get(x));
        }

        return res.toString();
        
    }
}