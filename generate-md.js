/*
 * This program recursively generates READMEs for my solutions
*/
const fs = require('fs'); 
const path = require('path'); 

function recurse(file_path) {
    const files = fs.readdirSync(file_path, { withFileTypes: true });
    /* Check if there exists a .cpp and .in and .out file in the current folder */
    var cppFiles;
    if ( ( cppFiles = files.filter(file => path.extname(`${file_path}/${file.name}`) == ".cpp") ).length != 0) {
        /* Add README */
        cppFiles = cppFiles.filter(file => file.name!="tempCodeRunnerFile.cpp");
        if (cppFiles.length == 1) {
            const code = fs.readFileSync(`${file_path}/${cppFiles[0].name}`, {encoding:'utf8', flag:'r'} ); 
            const MDHeader = file_path.split('/').pop();
            const MDdata = `# ${MDHeader}\n\`\`\`cpp\n${code}\n\`\`\``;
            fs.writeFileSync(`${file_path}/README.md`, MDdata); 
        } else {
            var navbar = `<a href="#0">${cppFiles[0].name}</a>`;
            for (var i=1; i<cppFiles.length; i++) 
                navbar += ` | <a href="#${i}">${cppFiles[i].name}</a>`;
            var MDdata = `<div align="center"> ${navbar} </div>\n\n`;
            for (var i=0; i<cppFiles.length; i++) {
                const code = fs.readFileSync(`${file_path}/${cppFiles[i].name}`, {encoding:'utf8', flag:'r'} ); 
                MDdata += `# [${cppFiles[i].name}](#${i})\n`;
                MDdata += `\`\`\`cpp\n${code}\n\`\`\`\n\n`;
            }
            fs.writeFileSync(`${file_path}/README.md`, MDdata); 
        }
        
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