/*
 * This program recursively generates READMEs for my solutions
*/
const fs = require('fs'); 
const path = require('path'); 

function recurse(file_path) {
    if (file_path.startsWith(`${__dirname}/Datastructures`)) return;

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
            /* This automatically changes *.cpp to a folder with its contents */
            for (var i=0; i<cppFiles.length; i++) {
                const name = cppFiles[i].name.split('.')[0];
                fs.mkdirSync(`${file_path}/${name}`); 
                fs.renameSync(`${file_path}/${name}.cpp`, `${file_path}/${name}/main.cpp`); 
                fs.writeFileSync(`${file_path}/${name}/${name}.in`, '');
                fs.writeFileSync(`${file_path}/${name}/${name}.out`, '');
            }
        }
        
    }
    /* Look into folders into its current one */
    for (var i=0; i<files.length; i++) {
        if (!files[i].isFile()) {
            recurse(`${file_path}/${files[i].name}`);
        }
    }

}

module.exports = function main() {
    console.log('Generating markdown files...');
    recurse(__dirname);
    console.log('Done with generating markdown files!!!');
}

