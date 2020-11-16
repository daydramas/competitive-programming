/*
 * Is working
*/
const fs = require('fs');
const path = require('path');

function recurse(file_path, depth) {
    if (depth) {
        try {
            fs.unlinkSync(path.join(file_path, "README.md"));
        } catch {}
    }
    const files = fs.readdirSync(file_path, { withFileTypes: true });
    /* Look into folders into its current one */
    for (var i=0; i<files.length; i++) {
        if (files[i].isDirectory()) {
            recurse(path.join(file_path, files[i].name), depth+1);
        }
    }
}

module.exports = function main() {
    recurse(path.join(__dirname, "../../.."), 0)
}