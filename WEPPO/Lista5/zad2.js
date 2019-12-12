//cd "d:\Documents\GitHub\UWr\WEPPO\Lista5"
var fs = require('fs');
var https = require('https');
(async function () {
    var pfx = await fs.promises.readFile('test2.pfx');
    var server = https.createServer({
        pfx: pfx,
        passphrase: 'test'
    },
        (req, res) => {
            res.setHeader('Content-type', 'text/html; charset=utf-8');
            res.end(`hello world ${new Date()}`);
        });
    server.listen(3000);
    console.log('started');
})(); 
