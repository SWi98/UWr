var fs = require("fs");
fs.readFile("some_data.txt", "utf8", (err, data) =>{
    if (err){
        throw err; 
    }
    console.log(data);
});
//cd "D:\Documents\GitHub\UWr\WEPPO\Lista4\Zad6"