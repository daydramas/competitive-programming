const fs = require('fs');
const path = require('path');

function make() {
	const files = fs.readdirSync(__dirname, { withFileTypes: true })
		.filter(f => f.name.split('.')[1] == 'cpp');
	const snippet = path.join(path.join(__dirname, '..'), '.vscode/cpp.code-snippets');
	let data = {};
	for (let i = 0; i < files.length; i++) {
		const name = files[i].name.split('.')[0];
		const file = fs.readFileSync(path.join(__dirname, name + '.cpp')).toString().split("\n");
		data[name] = {
			prefix: name,
			body: file,
			description: name
		};
	}
	fs.writeFileSync(snippet, JSON.stringify(data, null, 4));
}

make();