package uwr.list1.task1;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import uwr.list1.task1.InMemoryRepository;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

@RestController
public class UserRegistration {
    private InMemoryRepository repository;

    public UserRegistration(){
        this.repository = new InMemoryRepository();
    }

    @RequestMapping(value="/register", method= RequestMethod.POST)
    public Map<String, Object> register(@RequestParam String name) {
        this.repository.addUser(name);
        Integer count = this.repository.getUserCount(name);
        Map<String, Object> res = new LinkedHashMap<>();
        res.put("status", "OK");
        res.put("count", count);
        return res;
    }

    @RequestMapping(value="/delete", method = RequestMethod.DELETE)
    public void remove(@RequestParam String name){
        this.repository.removeUser(name);
    }

    @RequestMapping(value="/stats", method = RequestMethod.GET)
    public ResponseEntity<?> getStats (@RequestParam(required = false) String mode){
        if(mode == null){
            return ResponseEntity.status(HttpStatus.ACCEPTED).body(this.repository.getTopThree());
        }
        else if(mode.equals("ALL")){
            return ResponseEntity.status(HttpStatus.ACCEPTED).body(this.repository.getTop());
        }
        else if(mode.equals("IGNORE_CASE")){
            return ResponseEntity.status(HttpStatus.ACCEPTED).body(this.repository.getTopIgnoreCase());
        }
        else {
            return ResponseEntity.status(HttpStatus.UNPROCESSABLE_ENTITY).body("Invalid mode value");
        }
    }
}
