/*
 * This program recursively generates READMEs for my solutions
*/
const fs = require('fs'); 
const path = require('path'); 

function recurse(file_path) {
    const files = fs.readdirSync(file_path, { withFileTypes: true });
    /* Check if there exists a .cpp and .in and .out file in the current folder */
    var cppFile;
    if ( ( cppFile = files.find(file => path.extname(`${file_path}/${file.name}`) == ".cpp") ) && 
                     files.find(file => path.extname(`${file_path}/${file.name}`) == ".in")  && 
                     files.find(file => path.extname(`${file_path}/${file.name}`) == ".out") ) {
        /* Add README */
        const code = fs.readFileSync(`${file_path}/${cppFile.name}`, {encoding:'utf8', flag:'r'} ); 
        const data = `\`\`\`cpp\n${code}\n\`\`\``;
        fs.writeFileSync(`${file_path}/README.md`, data); 
    }
    /* Look into folders into its current one */
    for (var i=0; i<files.length; i++) {
        if (!files[i].isFile()) {
            recurse(`${file_path}/${files[i].name}`);
        }
    }

}

async function main() {
    console.log('Starting process...');
    recurse(__dirname);
    console.log('Done!!!');
}

main();