var fs = require("fs");
fs.readFile(String.raw`D:\Documents\GitHub\UWr\WEPPO\Lista4\Zad6\some_data.txt`, "utf8", (err, data) =>{
    if (err){
        throw err; 
    }
    console.log(data);
});
//cd "D:\Documents\GitHub\UWr\WEPPO\Lista4\Zad6"