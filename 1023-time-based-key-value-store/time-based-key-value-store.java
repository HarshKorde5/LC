class TimeMap_01 {
    Map<String, TreeMap<Integer, String>> map;

    public TimeMap_01() {
        map = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        map.computeIfAbsent(key, k -> new TreeMap<>()).put(timestamp,value);
    }
    
    public String get(String key, int timestamp) {
        if(!map.containsKey(key))    return "";

        TreeMap<Integer, String> timestamps = map.get(key);

        Map.Entry<Integer, String> entry = timestamps.floorEntry(timestamp);

        return entry == null ? "" : entry.getValue();
    }
}

class TimeMap {

    Map<String, List<Pair<Integer,String>>> map;

    public TimeMap() {
        map = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        map.computeIfAbsent(key, k -> new ArrayList<>()).add(new Pair<>(timestamp, value));
    }
    
    public String get(String key, int timestamp) {
        List<Pair<Integer,String>> values = map.getOrDefault(key, new ArrayList<>());

        int left = 0, right = values.size() - 1;
        String result = "";

        while(left <= right){
            int mid = (left + right) / 2;

            if(values.get(mid).getKey() <= timestamp){
                result = values.get(mid).getValue();
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return result;
    }
}
