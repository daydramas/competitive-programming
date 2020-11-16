const prompt = require('prompt');
const config = require('./config.json');
prompt.start();

prompt.get(config, function (err, result) {
    console.log(result);
    for (var key in result) {
        if(["y", "yes", "Y"].includes(result[key])) {
            const path = config.find( e => e.name == key ).path;
            require(path)();
        }
    }
});