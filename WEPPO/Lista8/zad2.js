//const sql = require('mssql');
const sql = require('mssql/msnodesqlv8')
const config ={
    server: 'DESKTOP-F9KTQCL\\SQLEXPRESS',
    database: 'WEPPO',
    user: 'weppo',
    password: 'weppo',
    port: '1433',
    options: {
        trustedConnection: true,
      }
};

(async function(){
    try{
        let pool = await sql.connect(config);

        let new_user = await pool.request().query('INSERT INTO Osoba_v2(Imie, Nazwisko, DataUrodzenia)  \
                                    VALUES(\'Dodany\', \'NaZajeciach\', \'2020-01-30\')');
        let new_id = await pool.request().query('SELECT SCOPE_IDENTITY()');

        console.log(new_id/*.recordset[0]['']*/);

        await pool.request().query('UPDATE Osoba_v2 SET DataUrodzenia = \'2020-01-30\' WHERE ID = \'10\'');

        let uwr_id = await pool.request().query('SELECT ID FROM Miejsce_Pracy WHERE Nazwa = \'UWr\'');
        uwr_id = uwr_id.recordset[0]['ID'];
        console.log(uwr_id);
        await pool.request().query('UPDATE Osoba_v2 SET ID_Miejsce_Pracy = ' + uwr_id + ' WHERE Imie = \'Anna\'');
        await pool.request().query('DELETE from Osoba_v2 where Imie = \'Dodany\'');


    }
    catch(err){
        console.log(err);
    }
})()