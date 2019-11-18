var fs = require("fs");
var util = require("util");
var dict = {};

function read(callback){
    fs.readFile("logs2.txt", "utf-8", (err, data) =>{
        if(err){
            throw err;
        }

        res = data.split("\n");

        for(var line of res){
            line = line.split(" ");
            if(line[1] in dict){
                dict[line[1]] ++;
            }
            else{
                dict[line[1]] = 1;
            }
        }
        
        callback();
    })
}

function fspromise(path, enc){
    return new Promise((resolve, reject) => {
        fs.readFile(path, enc, (err, data) => {
            if(err){
                reject(err);
            }
            res = data.split("\n");

            for(var line of res){
                line = line.split(" ");
                if(line[1] in dict){
                    dict[line[1]] ++;
                }
                else{
                    dict[line[1]] = 1;
                }
            }

            resolve(dict);
        });
    });
}

function display(dict){
    console.log(dict);
}

function zad1(){
    read(display)
}

function zad2(){
    fspromise("logs2.txt", "utf-8").then(data => console.log(data));
    (async function(){                                      
        var res = await fspromise("logs2.txt", "utf-8");    // The keyword await makes JavaScript wait until that promise settles 
        console.log(res);                                   // and returns its result.
    })();
}

var file = util.promisify(fs.readFile);         // Takes a function and returns a version that returns promises
function zad3(){
    file("logs2.txt", "utf-8").then((data) => {
        res = data.split("\n");
        for(var line of res){
            line = line.split(" ");
            if(line[1] in dict){
                dict[line[1]] ++;
            }
            else{
                dict[line[1]] = 1;
            }
        }
        console.log(dict);
    }).catch((error) => {throw error});
    
    (async function(){
        var res = await file("logs2.txt", "utf-8");
        dict = {};
        res = res.split("\n");
        for(var line of res){
            line = line.split(" ");
            if(line[1] in dict){
                dict[line[1]] ++;
            }
            else{
                dict[line[1]] = 1;
            }
        }
        console.log(dict);
    })();
}

function zad4(){
    (async function (){
        let dataFromFile;
        dataFromFile = await fs.promises.readFile("logs2.txt", "utf-8");    //Now readFile returns Promise object.
        res = dataFromFile.split("\n");
        for(var line of res){
            line = line.split(" ");
            if(line[1] in dict){
                dict[line[1]] ++;
            }
            else{
                dict[line[1]] = 1;
            }
        }
        console.log(dict);
    })();

    fs.promises.readFile("logs2.txt", "utf-8").then((res) =>{
        dict = {};
        res = res.split("\n");
        for(var line of res){
            line = line.split(" ");
            if(line[1] in dict){
                dict[line[1]] ++;
            }
            else{
                dict[line[1]] = 1;
            }
        }
        console.log(dict);
    });
}

zad4();

//cd "D:\Documents\GitHub\UWr\WEPPO\Lista4\Zad8"