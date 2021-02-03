const fs = require('fs');
const path = require('path');

const snippet = path.join(path.join(__dirname, '..'), '.vscode/cpp.code-snippets');
let data = {};

function make(dir) {
	const files = fs.readdirSync(dir, { withFileTypes: true });
	for(let i=0; i<files.length; i++) {
		if(files[i].isDirectory()) {
			make(path.join(dir, files[i].name));
		} else if(files[i].name.endsWith('.cpp')) {
			const name = files[i].name.split('.')[0];
			const file = fs.readFileSync(path.join(dir, name+'.cpp')).toString().split("\n");
			data[name] = {
				prefix: name,
				body: file,
				description: name
			};
		}
	}
}
make(__dirname);
fs.writeFileSync(snippet, JSON.stringify(data, null, 4));