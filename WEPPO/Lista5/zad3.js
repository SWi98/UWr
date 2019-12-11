var fs = require("fs");
var http = require("http")

var server = http.createServer(
    (req, res) => {
        res.setHeader("Content-disposition", "attachment; filename=something.txt");
        res.write("some text");
        res.end();
    }
);

server.listen(3000);