var http = require("http");
var express = require("express");
var multer = require('multer')
var path = require('path');
var app = express();

app.set("view engine", "ejs");
app.set("views", "./views");

app.use(express.urlencoded({extended:true}));

const storage = multer.diskStorage({
    destination: function(req, file, cb){
        cb(null, __dirname + "/uploads");
    },
    filename: function(req, file, cb){
        cb(null, file.originalname + path.extname(file.originalname));
    }
});

var upload = multer({storage: storage}).single("file");

app.get("/", (req, res) =>{
    res.render("main_page.ejs");
})

app.post("/fileupload", (req, res) =>{
    upload(req, res, function(err){
        if(err){
            console.log(err)
        }
        else{
            console.log("done");
        }
    });
    res.end("...");
})

http.createServer(app).listen(3000);