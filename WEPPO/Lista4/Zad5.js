console.log("Podaj imię");

function _once(){
    process.stdin.on('data', (name) => {
        console.log(name.toString());
        process.stdin.pause();
    });
}

function _on(){
    process.stdin.on('readable', function(){
        let name;                               // 'readable' event allows us to read the data whenever we want
        name = this.read();                     // read() reads everything so we don't have to pause the stream (?)
        console.log(name.toString());
        //process.stdin.pause();
    })
}

_once();