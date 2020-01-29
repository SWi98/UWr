const sql = require('mssql');
const config ={
    user: 'weppo',
    password: 'weppo',
    server: 'DESKTOP-F9KTQCL\\SQLEXPRESS',
    database: 'WEPPO',
};

(async function(){
    try{
        let pool = await sql.connect(config);
        console.log("udalo sie");
    }
    catch(err){
        console.log(err);
    }
})()