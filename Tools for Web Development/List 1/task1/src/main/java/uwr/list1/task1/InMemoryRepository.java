package uwr.list1.task1;

import java.util.*;
import java.util.stream.Collectors;

public record InMemoryRepository() {
    private final static Map<String, Integer> users = new HashMap<String, Integer>();
    private final static Map<String, Integer> usersIgnoredCase = new HashMap<String, Integer>();

    public void addUser(String userName){
        users.put(userName, users.getOrDefault(userName, 0) + 1);
       // String ignoredCaseUserName = userName.substring(0, 1).toUpperCase() + userName.substring(1).toLowerCase();
       // System.out.println(ignoredCaseUserName);
       // usersIgnoredCase.put(ignoredCaseUserName, usersIgnoredCase.getOrDefault(ignoredCaseUserName, 0) + 1);
    }

    public Integer getUserCount(String userName){
        return users.get(userName);
    }

    public void removeUser(String userName){
        //Integer count = users.get(userName);
        users.remove(userName);
       // String ignoredCaseUserName = userName.substring(0, 1).toUpperCase() + userName.substring(1).toLowerCase();
       // usersIgnoredCase.put(ignoredCaseUserName, usersIgnoredCase.get);
    }

    private Map<String, Integer> sortMap(Map<String, Integer> mapToSort){
        return mapToSort.entrySet().stream()
                .sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
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
