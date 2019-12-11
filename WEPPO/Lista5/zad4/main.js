var http = require("http");
var express = require("express");

var app = express();

app.set("view engine", "ejs");
app.set("views", "./views");

app.use(express.urlencoded({extended:true}));
app.get("/", (req, res) => {
    res.render("main_page");
})
app.post("/", (req, res) => {
    var name = req.body.NameInput;
    var surname = req.body.SurnameInput;
    var class_name = req.body.ClassName;
    var date = req.body.DateInput;
    var Exercise = [];
    var SumOfPoints = 0;
    for (let i = 0; i < 10; i++){
        var field = req.body["Exercise" + i.toString()];
        if (field == ""){
            Exercise[i] = 0;
        }
        else{
            Exercise[i] = field;
        }
        SumOfPoints += parseInt(Exercise[i], 10);
    }
    if (Validate(name, surname, class_name, date)){
        res.render("print", {Name:name, Surname:surname, ClassName:class_name, Date:date, Exercise:Exercise, 
                SumOfPoints: SumOfPoints});
    }
    else{
        res.render("main_page");
    }
})

function Validate(name, surname, class_name, date){
    return name != "" && surname != "" && class_name != "" && date != "";
}
http.createServer(app).listen(3000);