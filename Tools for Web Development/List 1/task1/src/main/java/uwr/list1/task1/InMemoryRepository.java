package uwr.list1.task1;

import java.util.*;
import java.util.stream.Collectors;

public record InMemoryRepository() {
    private final static Map<String, Integer> users = new HashMap<String, Integer>();

    public void addUser(String userName){
        users.put(userName, users.getOrDefault(userName, 0) + 1);
    }

    public Integer getUserCount(String userName){
        return users.get(userName);
    }

    public void removeUser(String userName){
        users.remove(userName);
    }

    private Map<String, Integer> sortMap(Map<String, Integer> mapToSort){
        return mapToSort.entrySet().stream()
                .sorted(Map.Entry.comparingByKey())  // sort alphabetically
                .sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))  // sort by count number
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,
                        (oldValue, newValue) -> null, LinkedHashMap::new));
    }

    public Map<String, Integer> getTop(){
        return this.sortMap(users);
    }

    public Map<String, Integer> getTopIgnoreCase(){
        Map<String, Integer> usersIgnoredCase = users.entrySet().stream()
                .collect(Collectors.toMap(entry -> entry.getKey().toLowerCase(), Map.Entry::getValue,
                        Integer::sum, HashMap::new));
        return this.sortMap(usersIgnoredCase);
    }

    public Map<String, Integer> getTopThree(){
        Map<String, Integer> sortedMap = this.getTop();
        Iterator<Map.Entry<String, Integer>> sortedMapIterator = sortedMap.entrySet().iterator();
        Map<String, Integer> result = new LinkedHashMap<String, Integer>();
        for(int i = 0; i < Math.min(3, sortedMap.size()); i++){
            Map.Entry<String, Integer> entry = sortedMapIterator.next();
            result.put(entry.getKey(), entry.getValue());
        }
        return result;
    }

}
