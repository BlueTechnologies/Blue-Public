const fs = require('fs');

class File {
    static read(file) {
        var filei = new XMLHttpRequest();
        filei.open("GET", file, false);
        filei.onreadystatechange = function ()
        {
            if(filei.readyState === 4)
            {
                if(filei.status === 200 || filei.status == 0)
                {
                    var recieved = filei.responseText;
                    return recieved;
                }
            }
        }
        filei.send(null);
    }

    static write(file, content) {
        fs.writeFile(file, content, err => {
            if (err) {
              console.error(err);
            }
        })
    }
}