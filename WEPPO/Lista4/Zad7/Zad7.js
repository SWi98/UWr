var fs = require("fs");
var readline = require("readline");

var lineReader = readline.createInterface({
    input: fs.createReadStream("logs.txt")
});

var res; 

function IPsorting(a, b){
    if(a[1] > b[1]){
        return -1;
    }
    if(b[1] > a[1]){
        return 1;
    }
    return 0;
}

dict = {};

lineReader.on("line", (line) =>{
    line = line.split(" ");
    if (line[0] in dict){
        dict[line[0]] += 1;
    }
    else{
        dict[line[0]] = 1;
    }
})

lineReader.on("close", () => {
    var dict_as_array = Object.keys(dict).map((key) => [key, dict[key]]);
    dict_as_array.sort(IPsorting);
    //console.log(dict_as_array);

    for(let i = 0; i < 3; i++){
        if(i < dict_as_array.length){
            console.log(dict_as_array[i][0]);
        }
}});

/*fs.readFile("logs.txt", "utf8", (err, data) =>{
    if (err){
        throw err;
    }

    res = data.split("\n");
    dict = {};
    
    for(var line of res){
        line = line.split(" ");

        if (line[0] in dict){
            dict[line[0]] += 1;
        }
        else{
            dict[line[0]] = 1;
        }
    }
    var dict_as_array = Object.keys(dict).map((key) => [key, dict[key]]);
    dict_as_array.sort(IPsorting);
    console.log(dict_as_array);

    for(let i = 0; i < 3; i++){
        if(i < dict_as_array.length){
            console.log(dict_as_array[i][0]);
        }
    }
})*/


//cd "D:\Documents\GitHub\UWr\WEPPO\Lista4\Zad7"